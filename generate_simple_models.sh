#!/bin/bash

# Basit C++ Model Sınıfları Oluşturucu Script
# JSON şemalarından sadece attribute, getter, setter ve validation içeren sınıflar oluşturur

set -e

# Renkli çıktı
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

echo -e "${BLUE}Basit C++ Model Sınıfları Oluşturucu${NC}"
echo "========================================"

# Dizin kontrolü
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ZMQ_MESSAGES_DIR="$SCRIPT_DIR/zmq_messages"
MODEL_DIR="$SCRIPT_DIR/Model"

if [ ! -d "$ZMQ_MESSAGES_DIR" ]; then
    echo -e "${RED}Hata: zmq_messages dizini bulunamadı!${NC}"
    exit 1
fi

# Model dizinini oluştur
mkdir -p "$MODEL_DIR"
echo -e "${GREEN}Model dizini oluşturuldu: $MODEL_DIR${NC}"

# JSON'dan C++ tipini belirle
get_cpp_type() {
    local json_type="$1"
    local minimum="$2"
    local maximum="$3"
    
    case "$json_type" in
        "integer")
            echo "int64_t"
            ;;
        "number")
            echo "double"
            ;;
        "string")
            echo "std::string"
            ;;
        *)
            echo "std::string"
            ;;
    esac
}

# Validation fonksiyonu oluştur
create_validation_function() {
    local cpp_type="$1"
    local field_name="$2"
    local minimum="$3"
    local maximum="$4"
    local var_name="$5"
    
    if [ "$cpp_type" = "int64_t" ]; then
        echo "    void validate${field_name}(int64_t value) const {"
        echo "        if (value < ${minimum}LL || value > ${maximum}LL) {"
        echo "            throw std::out_of_range(\"${field_name} değeri geçerli aralık dışında: \" + std::to_string(value));"
        echo "        }"
        echo "    }"
        echo ""
    elif [ "$cpp_type" = "double" ]; then
        echo "    void validate${field_name}(double value) const {"
        echo "        if (std::isnan(value) || value < $minimum || value > $maximum) {"
        echo "            throw std::out_of_range(\"${field_name} değeri geçerli aralık dışında: \" + std::to_string(value));"
        echo "        }"
        echo "    }"
        echo ""
    fi
}

# Tek JSON dosyasını işle
process_json_file() {
    local json_file="$1"
    local filename=$(basename "$json_file" .json)
    
    echo -e "${YELLOW}${filename} sınıfı işleniyor...${NC}"
    
    # JSON'dan title ve properties'i çıkar
    local title=$(jq -r '.title // "UnknownClass"' "$json_file")
    local description=$(jq -r '.description // "Açıklama yok"' "$json_file")
    
    # Header dosyası oluştur
    local header_file="$MODEL_DIR/${title}.h"
    
    cat > "$header_file" << EOF
#pragma once
#include <string>
#include <cstdint>
#include <stdexcept>
#include <cmath>

/**
 * @brief $description
 * Auto-generated from ${filename}.json
 */
class $title {
private:
EOF

    # Private member variables
    echo "    // Member variables" >> "$header_file"
    jq -r '.properties | to_entries[] | "\(.key) \(.value.type) \(.value.minimum // "null") \(.value.maximum // "null")"' "$json_file" | while read -r field_name json_type minimum maximum; do
        if [ "$minimum" = "null" ]; then minimum="0"; fi
        if [ "$maximum" = "null" ]; then maximum="1000000"; fi
        
        cpp_type=$(get_cpp_type "$json_type" "$minimum" "$maximum")
        echo "    $cpp_type ${field_name}_;" >> "$header_file"
    done
    
    echo "" >> "$header_file"
    echo "    // Validation functions" >> "$header_file"
    
    # Validation functions
    jq -r '.properties | to_entries[] | "\(.key) \(.value.type) \(.value.minimum // "null") \(.value.maximum // "null")"' "$json_file" | while read -r field_name json_type minimum maximum; do
        if [ "$minimum" = "null" ]; then minimum="0"; fi
        if [ "$maximum" = "null" ]; then maximum="1000000"; fi
        
        cpp_type=$(get_cpp_type "$json_type" "$minimum" "$maximum")
        # Capitalize first letter for function name
        field_name_cap="$(tr '[:lower:]' '[:upper:]' <<< ${field_name:0:1})${field_name:1}"
        
        create_validation_function "$cpp_type" "$field_name_cap" "$minimum" "$maximum" "$field_name" >> "$header_file"
    done
    
    cat >> "$header_file" << EOF
public:
    // Constructor
    $title() {
EOF

    # Constructor initialization
    jq -r '.properties | to_entries[] | "\(.key) \(.value.type)"' "$json_file" | while read -r field_name json_type; do
        cpp_type=$(get_cpp_type "$json_type")
        if [ "$cpp_type" = "int64_t" ]; then
            echo "        ${field_name}_ = 0;" >> "$header_file"
        elif [ "$cpp_type" = "double" ]; then
            echo "        ${field_name}_ = 0.0;" >> "$header_file"
        else
            echo "        ${field_name}_ = \"\";" >> "$header_file"
        fi
    done
    
    cat >> "$header_file" << EOF
    }
    
    // Destructor
    ~$title() = default;
    
    // Getters and Setters
EOF

    # Getter/Setter methods
    jq -r '.properties | to_entries[] | "\(.key) \(.value.type) \(.value.minimum // "null") \(.value.maximum // "null")"' "$json_file" | while read -r field_name json_type minimum maximum; do
        if [ "$minimum" = "null" ]; then minimum="0"; fi
        if [ "$maximum" = "null" ]; then maximum="1000000"; fi
        
        cpp_type=$(get_cpp_type "$json_type" "$minimum" "$maximum")
        field_name_cap="$(tr '[:lower:]' '[:upper:]' <<< ${field_name:0:1})${field_name:1}"
        
        # Getter
        echo "    $cpp_type get${field_name_cap}() const {" >> "$header_file"
        echo "        return ${field_name}_;" >> "$header_file"
        echo "    }" >> "$header_file"
        echo "" >> "$header_file"
        
        # Setter
        echo "    void set${field_name_cap}(const $cpp_type& value) {" >> "$header_file"
        if [ "$cpp_type" != "std::string" ]; then
            echo "        validate${field_name_cap}(value);" >> "$header_file"
        fi
        echo "        ${field_name}_ = value;" >> "$header_file"
        echo "    }" >> "$header_file"
        echo "" >> "$header_file"
    done
    
    # isValid method
    cat >> "$header_file" << EOF
    // Validation
    bool isValid() const {
        try {
EOF

    jq -r '.properties | to_entries[] | "\(.key) \(.value.type)"' "$json_file" | while read -r field_name json_type; do
        cpp_type=$(get_cpp_type "$json_type")
        field_name_cap="$(tr '[:lower:]' '[:upper:]' <<< ${field_name:0:1})${field_name:1}"
        
        if [ "$cpp_type" != "std::string" ]; then
            echo "            validate${field_name_cap}(${field_name}_);" >> "$header_file"
        fi
    done
    
    cat >> "$header_file" << EOF
            return true;
        } catch (const std::exception&) {
            return false;
        }
    }
};
EOF

    echo -e "${GREEN}✅ ${title}.h oluşturuldu${NC}"
}

# Ana fonksiyon
main() {
    echo -e "${BLUE}JSON dosyaları taranıyor...${NC}"
    
    # zmq_messages dizinindeki tüm JSON dosyalarını bul
    json_files=($(find "$ZMQ_MESSAGES_DIR" -name "*.json" | sort))
    
    if [ ${#json_files[@]} -eq 0 ]; then
        echo -e "${RED}Hata: zmq_messages dizininde JSON dosyası bulunamadı!${NC}"
        exit 1
    fi
    
    echo -e "${YELLOW}Bulunan JSON dosyaları:${NC}"
    for file in "${json_files[@]}"; do
        echo "  - $(basename "$file")"
    done
    echo ""
    
    # Her JSON dosyasını işle
    for json_file in "${json_files[@]}"; do
        # jq'nin kurulu olup olmadığını kontrol et
        if ! command -v jq &> /dev/null; then
            echo -e "${RED}Hata: jq komutu bulunamadı. Lütfen jq'yu kurun: sudo apt-get install jq${NC}"
            exit 1
        fi
        
        process_json_file "$json_file"
        echo ""
    done
    
    # CMakeLists.txt oluştur
    create_cmake_file
    
    # Örnek main dosyası oluştur
    create_example_main
    
    echo -e "${GREEN}🎉 Tüm C++ Model sınıfları başarıyla oluşturuldu!${NC}"
    echo -e "${GREEN}📁 Model dizini: $MODEL_DIR${NC}"
    echo ""
    echo -e "${YELLOW}Oluşturulan dosyalar:${NC}"
    ls -la "$MODEL_DIR"
    echo ""
    echo -e "${BLUE}Derleme için: cd Model && mkdir build && cd build && cmake .. && make${NC}"
}

# CMakeLists.txt oluştur
create_cmake_file() {
    echo -e "${YELLOW}CMakeLists.txt oluşturuluyor...${NC}"
    
    cat > "$MODEL_DIR/CMakeLists.txt" << 'EOF'
cmake_minimum_required(VERSION 3.12)
project(SimpleTrackModels)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

# Example executable
add_executable(model_example main.cpp)
EOF
}

# Örnek main dosyası oluştur
create_example_main() {
    echo -e "${YELLOW}Örnek main.cpp oluşturuluyor...${NC}"
    
    cat > "$MODEL_DIR/main.cpp" << 'EOF'
#include <iostream>
#include <vector>
#include <memory>

// Include all generated headers
EOF

    # Tüm header dosyalarını include et
    for json_file in "$ZMQ_MESSAGES_DIR"/*.json; do
        if [ -f "$json_file" ]; then
            title=$(jq -r '.title // "UnknownClass"' "$json_file")
            echo "#include \"${title}.h\"" >> "$MODEL_DIR/main.cpp"
        fi
    done
    
    cat >> "$MODEL_DIR/main.cpp" << 'EOF'

int main() {
    std::cout << "=== C++ Model Sınıfları Test Programı ===" << std::endl;
    
    try {
EOF

    # Her sınıf için örnek kod oluştur
    for json_file in "$ZMQ_MESSAGES_DIR"/*.json; do
        if [ -f "$json_file" ]; then
            title=$(jq -r '.title // "UnknownClass"' "$json_file")
            
            cat >> "$MODEL_DIR/main.cpp" << EOF
        
        // $title örneği
        std::cout << "\\n--- $title ---" << std::endl;
        $title ${title,,}Obj;
        
EOF

            # İlk birkaç field için örnek değer atama
            jq -r '.properties | to_entries[0:3][] | "\(.key) \(.value.type)"' "$json_file" | while read -r field_name json_type; do
                field_name_cap="$(tr '[:lower:]' '[:upper:]' <<< ${field_name:0:1})${field_name:1}"
                cpp_type=$(get_cpp_type "$json_type")
                
                if [ "$cpp_type" = "int64_t" ]; then
                    echo "        ${title,,}Obj.set${field_name_cap}(12345);" >> "$MODEL_DIR/main.cpp"
                elif [ "$cpp_type" = "double" ]; then
                    echo "        ${title,,}Obj.set${field_name_cap}(123.45);" >> "$MODEL_DIR/main.cpp"
                else
                    echo "        ${title,,}Obj.set${field_name_cap}(\"test_value\");" >> "$MODEL_DIR/main.cpp"
                fi
            done
            
            cat >> "$MODEL_DIR/main.cpp" << EOF
        
        std::cout << "Validation: " << (${title,,}Obj.isValid() ? "Geçerli" : "Geçersiz") << std::endl;
EOF
        fi
    done
    
    cat >> "$MODEL_DIR/main.cpp" << 'EOF'
        
    } catch (const std::exception& e) {
        std::cerr << "Hata: " << e.what() << std::endl;
        return 1;
    }
    
    std::cout << "\n🎉 Tüm testler tamamlandı!" << std::endl;
    return 0;
}
EOF
}

# Script'i çalıştır
main
