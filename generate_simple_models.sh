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

# JSON'dan C++ tipini belirle (Gelişmiş sürüm)
get_cpp_type() {
    local json_type="$1"
    local minimum="$2"
    local maximum="$3"
    local format="$4"
    
    # Eğer format belirtilmişse, doğrudan kullan
    if [ "$format" != "null" ] && [ -n "$format" ]; then
        case "$format" in
            "int8"|"byte")
                echo "int8_t"
                ;;
            "uint8"|"ubyte")
                echo "uint8_t"
                ;;
            "int16"|"short")
                echo "int16_t"
                ;;
            "uint16"|"ushort")
                echo "uint16_t"
                ;;
            "int32"|"int")
                echo "int32_t"
                ;;
            "uint32"|"uint")
                echo "uint32_t"
                ;;
            "int64"|"long")
                echo "int64_t"
                ;;
            "uint64"|"ulong")
                echo "uint64_t"
                ;;
            "float"|"float32")
                echo "float"
                ;;
            "double"|"float64")
                echo "double"
                ;;
            *)
                echo "std::string"
                ;;
        esac
        return
    fi
    
    # Format yoksa, tip ve range'e göre akıllı seçim yap
    case "$json_type" in
        "integer")
            if [ "$minimum" != "null" ] && [ "$maximum" != "null" ]; then
                # Önce unsigned olup olmadığını kontrol et
                if [ "$minimum" -ge 0 ] 2>/dev/null; then
                    # Unsigned integer ranges
                    if [ "$maximum" -le 255 ] 2>/dev/null; then
                        echo "uint8_t"     # 0 to 255
                    elif [ "$maximum" -le 65535 ] 2>/dev/null; then
                        echo "uint16_t"   # 0 to 65,535
                    elif [ "$maximum" -le 4294967295 ] 2>/dev/null; then
                        echo "uint32_t"   # 0 to 4,294,967,295
                    else
                        echo "uint64_t"   # Büyük unsigned değerler
                    fi
                else
                    # Signed integer ranges
                    if [ "$minimum" -ge -128 ] && [ "$maximum" -le 127 ] 2>/dev/null; then
                        echo "int8_t"     # -128 to 127
                    elif [ "$minimum" -ge -32768 ] && [ "$maximum" -le 32767 ] 2>/dev/null; then
                        echo "int16_t"    # -32,768 to 32,767
                    elif [ "$minimum" -ge -2147483648 ] && [ "$maximum" -le 2147483647 ] 2>/dev/null; then
                        echo "int32_t"    # -2,147,483,648 to 2,147,483,647
                    else
                        echo "int64_t"    # Büyük signed değerler
                    fi
                fi
            else
                # Range belirtilmemişse varsayılan
                echo "int64_t"
            fi
            ;;
        "number")
            if [ "$minimum" != "null" ] && [ "$maximum" != "null" ]; then
                # Float precision kontrolü
                local abs_min=$(echo "$minimum" | tr -d '-')
                local abs_max=$(echo "$maximum" | tr -d '-')
                
                # Float range: yaklaşık ±3.4e38, precision: 7 decimal digit
                # Double range: yaklaşık ±1.7e308, precision: 15 decimal digit
                
                # Basit heuristic: değer aralığı ve precision'a göre karar ver
                # Küçük değerler (1e6'dan az) için float yeterli olabilir
                if ([ "$abs_max" -lt 1000000 ] 2>/dev/null || echo "$abs_max" | grep -E '^[0-9]+(\.[0-9]{1,6})?$' >/dev/null); then
                    echo "float"
                else
                    echo "double"
                fi
            else
                # Range belirtilmemişse varsayılan double
                echo "double"
            fi
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
    
    # Tip kategorisine göre validation oluştur
    if [[ "$cpp_type" =~ ^(int8_t|int16_t|int32_t|int64_t)$ ]]; then
        # Signed integer types - uygun suffix seç
        local min_suffix="LL"
        local max_suffix="LL"
        
        # int8_t ve int16_t için suffix gereksiz
        if [[ "$cpp_type" =~ ^(int8_t|int16_t)$ ]]; then
            min_suffix=""
            max_suffix=""
        fi
        
        echo "    void validate${field_name}($cpp_type value) const {"
        echo "        if (value < ${minimum}${min_suffix} || value > ${maximum}${max_suffix}) {"
        echo "            throw std::out_of_range(\"${field_name} value is out of valid range: \" + std::to_string(value));"
        echo "        }"
        echo "    }"
        echo ""
    elif [[ "$cpp_type" =~ ^(uint8_t|uint16_t|uint32_t|uint64_t)$ ]]; then
        # Unsigned integer types - uygun suffix seç
        local max_suffix="ULL"
        
        # uint8_t ve uint16_t için suffix gereksiz
        if [[ "$cpp_type" =~ ^(uint8_t|uint16_t)$ ]]; then
            max_suffix=""
        elif [[ "$cpp_type" == "uint32_t" ]]; then
            max_suffix="U"
        fi
        
        echo "    void validate${field_name}($cpp_type value) const {"
        echo "        if (value > ${maximum}${max_suffix}) {"
        echo "            throw std::out_of_range(\"${field_name} value is out of valid range: \" + std::to_string(value));"
        echo "        }"
        echo "    }"
        echo ""
    elif [[ "$cpp_type" =~ ^(float|double)$ ]]; then
        # Floating point types
        echo "    void validate${field_name}($cpp_type value) const {"
        echo "        if (std::isnan(value) || value < $minimum || value > $maximum) {"
        echo "            throw std::out_of_range(\"${field_name} value is out of valid range: \" + std::to_string(value));"
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
    
    # Header ve source dosyalarını oluştur
    local header_file="$MODEL_DIR/${title}.hpp"
    local source_file="$MODEL_DIR/${title}.cpp"
    
    # x-service-metadata bilgilerini çıkar
    local multicast_address=$(jq -r '."x-service-metadata".multicast_address // "null"' "$json_file")
    local port=$(jq -r '."x-service-metadata".port // "null"' "$json_file")
    
    cat > "$header_file" << EOF
#pragma once
#include <string>
#include <cstdint>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <cstring>

/**
 * @brief $description
 * Auto-generated from ${filename}.json
 */
class $title {
public:
EOF

    # Network configuration constants ekle
    if [ "$multicast_address" != "null" ] && [ -n "$multicast_address" ]; then
        echo "    // Network configuration constants" >> "$header_file"
        echo "    static constexpr const char* MULTICAST_ADDRESS = \"$multicast_address\";" >> "$header_file"
    fi
    
    if [ "$port" != "null" ] && [ -n "$port" ]; then
        if [ "$multicast_address" == "null" ] || [ -z "$multicast_address" ]; then
            echo "    // Network configuration constants" >> "$header_file"
        fi
        echo "    static constexpr int PORT = $port;" >> "$header_file"
    fi
    
    if [ "$multicast_address" != "null" ] || [ "$port" != "null" ]; then
        echo "" >> "$header_file"
    fi

    cat >> "$header_file" << EOF
    // Constructor
    $title();
    
    // Destructor
    ~$title() = default;
    
    // Getters and Setters
EOF

    # Getter/Setter declarations
    jq -r '.properties | to_entries[] | "\(.key) \(.value.type) \(.value.minimum // "null") \(.value.maximum // "null") \(.value.format // "null")"' "$json_file" | while read -r field_name json_type minimum maximum format; do
        if [ "$minimum" = "null" ]; then minimum="0"; fi
        if [ "$maximum" = "null" ]; then maximum="1000000"; fi
        
        cpp_type=$(get_cpp_type "$json_type" "$minimum" "$maximum" "$format")
        field_name_cap="$(tr '[:lower:]' '[:upper:]' <<< ${field_name:0:1})${field_name:1}"
        
        # Getter declaration
        echo "    $cpp_type get${field_name_cap}() const;" >> "$header_file"
        
        # Setter declaration
        echo "    void set${field_name_cap}(const $cpp_type& value);" >> "$header_file"
        echo "" >> "$header_file"
    done
    
    # isValid method declaration
    cat >> "$header_file" << EOF
    // Validation
    bool isValid() const;

    // Binary Serialization
    std::vector<uint8_t> serialize() const;
    bool deserialize(const std::vector<uint8_t>& data);
    size_t getSerializedSize() const;

private:
EOF

    # Private member variables
    echo "    // Member variables" >> "$header_file"
    jq -r '.properties | to_entries[] | "\(.key) \(.value.type) \(.value.minimum // "null") \(.value.maximum // "null") \(.value.format // "null")"' "$json_file" | while read -r field_name json_type minimum maximum format; do
        if [ "$minimum" = "null" ]; then minimum="0"; fi
        if [ "$maximum" = "null" ]; then maximum="1000000"; fi
        
        cpp_type=$(get_cpp_type "$json_type" "$minimum" "$maximum" "$format")
        echo "    $cpp_type ${field_name}_;" >> "$header_file"
    done
    
    echo "" >> "$header_file"
    echo "    // Validation functions" >> "$header_file"
    
    # Validation function declarations
    jq -r '.properties | to_entries[] | "\(.key) \(.value.type) \(.value.minimum // "null") \(.value.maximum // "null") \(.value.format // "null")"' "$json_file" | while read -r field_name json_type minimum maximum format; do
        if [ "$minimum" = "null" ]; then minimum="0"; fi
        if [ "$maximum" = "null" ]; then maximum="1000000"; fi
        
        cpp_type=$(get_cpp_type "$json_type" "$minimum" "$maximum" "$format")
        field_name_cap="$(tr '[:lower:]' '[:upper:]' <<< ${field_name:0:1})${field_name:1}"
        
        if [ "$cpp_type" != "std::string" ]; then
            echo "    void validate${field_name_cap}($cpp_type value) const;" >> "$header_file"
        fi
    done
    
    cat >> "$header_file" << EOF
};
EOF

    # Source dosyası oluştur (.cpp)
    cat > "$source_file" << EOF
#include "${title}.hpp"

// Constructor
$title::$title() {
EOF

    # Constructor initialization
    jq -r '.properties | to_entries[] | "\(.key) \(.value.type) \(.value.format // "null")"' "$json_file" | while read -r field_name json_type format; do
        cpp_type=$(get_cpp_type "$json_type" "0" "1000000" "$format")
        if [[ "$cpp_type" =~ int.*_t|float|double ]]; then
            echo "    ${field_name}_ = 0;" >> "$source_file"
        else
            echo "    ${field_name}_ = \"\";" >> "$source_file"
        fi
    done
    
    cat >> "$source_file" << EOF
}

EOF

    # Validation functions implementation
    jq -r '.properties | to_entries[] | "\(.key) \(.value.type) \(.value.minimum // "null") \(.value.maximum // "null") \(.value.format // "null")"' "$json_file" | while read -r field_name json_type minimum maximum format; do
        if [ "$minimum" = "null" ]; then minimum="0"; fi
        if [ "$maximum" = "null" ]; then maximum="1000000"; fi
        
        cpp_type=$(get_cpp_type "$json_type" "$minimum" "$maximum" "$format")
        field_name_cap="$(tr '[:lower:]' '[:upper:]' <<< ${field_name:0:1})${field_name:1}"
        
        if [ "$cpp_type" != "std::string" ]; then
            create_validation_function "$cpp_type" "$field_name_cap" "$minimum" "$maximum" "$field_name" | sed "s/void validate/void $title::validate/" >> "$source_file"
        fi
    done

    # Getter/Setter implementations
    jq -r '.properties | to_entries[] | "\(.key) \(.value.type) \(.value.minimum // "null") \(.value.maximum // "null") \(.value.format // "null")"' "$json_file" | while read -r field_name json_type minimum maximum format; do
        if [ "$minimum" = "null" ]; then minimum="0"; fi
        if [ "$maximum" = "null" ]; then maximum="1000000"; fi
        
        cpp_type=$(get_cpp_type "$json_type" "$minimum" "$maximum" "$format")
        field_name_cap="$(tr '[:lower:]' '[:upper:]' <<< ${field_name:0:1})${field_name:1}"
        
        # Getter implementation
        echo "$cpp_type $title::get${field_name_cap}() const {" >> "$source_file"
        echo "    return ${field_name}_;" >> "$source_file"
        echo "}" >> "$source_file"
        echo "" >> "$source_file"
        
        # Setter implementation
        echo "void $title::set${field_name_cap}(const $cpp_type& value) {" >> "$source_file"
        if [ "$cpp_type" != "std::string" ]; then
            echo "    validate${field_name_cap}(value);" >> "$source_file"
        fi
        echo "    ${field_name}_ = value;" >> "$source_file"
        echo "}" >> "$source_file"
        echo "" >> "$source_file"
    done
    
    # isValid method implementation
    cat >> "$source_file" << EOF
bool $title::isValid() const {
    try {
EOF

    jq -r '.properties | to_entries[] | "\(.key) \(.value.type) \(.value.format // "null")"' "$json_file" | while read -r field_name json_type format; do
        cpp_type=$(get_cpp_type "$json_type" "0" "1000000" "$format")
        field_name_cap="$(tr '[:lower:]' '[:upper:]' <<< ${field_name:0:1})${field_name:1}"
        
        if [ "$cpp_type" != "std::string" ]; then
            echo "        validate${field_name_cap}(${field_name}_);" >> "$source_file"
        fi
    done
    
    cat >> "$source_file" << EOF
        return true;
    } catch (const std::exception&) {
        return false;
    }
}

// Binary Serialization Implementation
std::vector<uint8_t> $title::serialize() const {
    std::vector<uint8_t> buffer;
    buffer.reserve(getSerializedSize());
    
EOF

    # Her field için serialize kodu oluştur
    jq -r '.properties | to_entries[] | "\(.key) \(.value.type) \(.value.format // "null")"' "$json_file" | while read -r field_name json_type format; do
        cpp_type=$(get_cpp_type "$json_type" "0" "1000000" "$format")
        
        if [[ "$cpp_type" =~ int.*_t|float|double ]]; then
            cat >> "$source_file" << EOF
    // Serialize ${field_name}_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&${field_name}_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(${field_name}_));
    }
    
EOF
        elif [ "$cpp_type" = "std::string" ]; then
            cat >> "$source_file" << EOF
    // Serialize ${field_name}_ (string)
    {
        uint32_t length = static_cast<uint32_t>(${field_name}_.length());
        const uint8_t* length_ptr = reinterpret_cast<const uint8_t*>(&length);
        buffer.insert(buffer.end(), length_ptr, length_ptr + sizeof(length));
        buffer.insert(buffer.end(), ${field_name}_.begin(), ${field_name}_.end());
    }
    
EOF
        fi
    done
    
    cat >> "$source_file" << EOF
    return buffer;
}

bool $title::deserialize(const std::vector<uint8_t>& data) {
    if (data.size() < getSerializedSize()) {
        return false;
    }
    
    size_t offset = 0;
    
EOF

    # Her field için deserialize kodu oluştur
    jq -r '.properties | to_entries[] | "\(.key) \(.value.type) \(.value.format // "null")"' "$json_file" | while read -r field_name json_type format; do
        cpp_type=$(get_cpp_type "$json_type" "0" "1000000" "$format")
        
        if [[ "$cpp_type" =~ int.*_t|float|double ]]; then
            cat >> "$source_file" << EOF
    // Deserialize ${field_name}_
    if (offset + sizeof(${field_name}_) <= data.size()) {
        std::memcpy(&${field_name}_, &data[offset], sizeof(${field_name}_));
        offset += sizeof(${field_name}_);
    } else {
        return false;
    }
    
EOF
        elif [ "$cpp_type" = "std::string" ]; then
            cat >> "$source_file" << EOF
    // Deserialize ${field_name}_ (string)
    if (offset + sizeof(uint32_t) <= data.size()) {
        uint32_t length;
        std::memcpy(&length, &data[offset], sizeof(length));
        offset += sizeof(uint32_t);
        
        if (offset + length <= data.size()) {
            ${field_name}_.assign(reinterpret_cast<const char*>(&data[offset]), length);
            offset += length;
        } else {
            return false;
        }
    } else {
        return false;
    }
    
EOF
        fi
    done
    
    cat >> "$source_file" << EOF
    return true;
}

size_t $title::getSerializedSize() const {
    size_t size = 0;
    
EOF

    # Her field için size hesaplama
    jq -r '.properties | to_entries[] | "\(.key) \(.value.type) \(.value.format // "null")"' "$json_file" | while read -r field_name json_type format; do
        cpp_type=$(get_cpp_type "$json_type" "0" "1000000" "$format")
        
        if [[ "$cpp_type" =~ int.*_t|float|double ]]; then
            cat >> "$source_file" << EOF
    size += sizeof(${field_name}_);  // ${cpp_type}
EOF
        elif [ "$cpp_type" = "std::string" ]; then
            cat >> "$source_file" << EOF
    size += sizeof(uint32_t) + ${field_name}_.length();  // string length + data
EOF
        fi
    done
    
    cat >> "$source_file" << EOF
    
    return size;
}
EOF

    echo -e "${GREEN}✅ ${title}.hpp ve ${title}.cpp oluşturuldu${NC}"
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

# Source files
EOF

    # Tüm .cpp dosyalarını CMakeLists.txt'ye ekle
    echo "set(SOURCES" >> "$MODEL_DIR/CMakeLists.txt"
    for json_file in "$ZMQ_MESSAGES_DIR"/*.json; do
        if [ -f "$json_file" ]; then
            title=$(jq -r '.title // "UnknownClass"' "$json_file")
            echo "    ${title}.cpp" >> "$MODEL_DIR/CMakeLists.txt"
        fi
    done
    echo "    main.cpp" >> "$MODEL_DIR/CMakeLists.txt"
    echo ")" >> "$MODEL_DIR/CMakeLists.txt"
    
    cat >> "$MODEL_DIR/CMakeLists.txt" << 'EOF'

# Example executable
add_executable(model_example ${SOURCES})
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
            echo "#include \"${title}.hpp\"" >> "$MODEL_DIR/main.cpp"
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
            jq -r '.properties | to_entries[0:3][] | "\(.key) \(.value.type) \(.value.format // "null")"' "$json_file" | while read -r field_name json_type format; do
                field_name_cap="$(tr '[:lower:]' '[:upper:]' <<< ${field_name:0:1})${field_name:1}"
                cpp_type=$(get_cpp_type "$json_type" "0" "1000000" "$format")
                
                if [[ "$cpp_type" =~ int.*_t ]]; then
                    echo "        ${title,,}Obj.set${field_name_cap}(12345);" >> "$MODEL_DIR/main.cpp"
                elif [[ "$cpp_type" =~ float|double ]]; then
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
