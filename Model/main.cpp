#include <iostream>
#include <vector>
#include <memory>

// Include all generated headers
#include "DelayCalcTrackData.hpp"
#include "ExtrapTrackData.hpp"
#include "FinalCalcTrackData.hpp"
#include "ProcessedTrackData.hpp"
#include "TrackStatics.hpp"

int main() {
    std::cout << "=== C++ Model Sınıfları Test Programı ===" << std::endl;
    
    try {
        
        // DelayCalcTrackData örneği
        std::cout << "\n--- DelayCalcTrackData ---" << std::endl;
        DelayCalcTrackData delaycalctrackdataObj;
        
        delaycalctrackdataObj.setTrackId(1234);
        delaycalctrackdataObj.setXVelocityECEF(123.45);
        delaycalctrackdataObj.setYVelocityECEF(123.45);
        
        std::cout << "Validation: " << (delaycalctrackdataObj.isValid() ? "Geçerli" : "Geçersiz") << std::endl;
        
        // ExtrapTrackData örneği
        std::cout << "\n--- ExtrapTrackData ---" << std::endl;
        ExtrapTrackData extraptrackdataObj;
        
        extraptrackdataObj.setTrackId(1234);
        extraptrackdataObj.setXVelocityECEF(123.45);
        extraptrackdataObj.setYVelocityECEF(123.45);
        
        std::cout << "Validation: " << (extraptrackdataObj.isValid() ? "Geçerli" : "Geçersiz") << std::endl;
        
        // Binary Serialization Test
        std::cout << "Binary Serialization Test:" << std::endl;
        std::vector<uint8_t> serializedData = extraptrackdataObj.serialize();
        std::cout << "Serialized size: " << serializedData.size() << " bytes" << std::endl;
        std::cout << "Expected size: " << extraptrackdataObj.getSerializedSize() << " bytes" << std::endl;
        
        // Test deserialization
        ExtrapTrackData deserializedObj;
        bool deserializeSuccess = deserializedObj.deserialize(serializedData);
        std::cout << "Deserialization: " << (deserializeSuccess ? "Başarılı" : "Başarısız") << std::endl;
        
        if (deserializeSuccess) {
            std::cout << "Original TrackId: " << extraptrackdataObj.getTrackId() << std::endl;
            std::cout << "Deserialized TrackId: " << deserializedObj.getTrackId() << std::endl;
            std::cout << "Data integrity: " << (extraptrackdataObj.getTrackId() == deserializedObj.getTrackId() ? "OK" : "FAILED") << std::endl;
        }
        
        // FinalCalcTrackData örneği
        std::cout << "\n--- FinalCalcTrackData ---" << std::endl;
        FinalCalcTrackData finalcalctrackdataObj;
        
        finalcalctrackdataObj.setTrackId(1234);
        finalcalctrackdataObj.setXVelocityECEF(123.45);
        finalcalctrackdataObj.setYVelocityECEF(123.45);
        
        std::cout << "Validation: " << (finalcalctrackdataObj.isValid() ? "Geçerli" : "Geçersiz") << std::endl;
        
        // ProcessedTrackData örneği
        std::cout << "\n--- ProcessedTrackData ---" << std::endl;
        ProcessedTrackData processedtrackdataObj;
        
        processedtrackdataObj.setTrackId(1234);
        processedtrackdataObj.setXVelocityECEF(123.45);
        processedtrackdataObj.setYVelocityECEF(123.45);
        
        std::cout << "Validation: " << (processedtrackdataObj.isValid() ? "Geçerli" : "Geçersiz") << std::endl;
        
        // TrackStatics örneği
        std::cout << "\n--- TrackStatics ---" << std::endl;
        TrackStatics trackstaticsObj;
        
        trackstaticsObj.setTrackId(1234);
        trackstaticsObj.setFirstHopDelayDataMean(123.45);
        trackstaticsObj.setFirstHopDelayDataStd(123.45);
        
        std::cout << "Validation: " << (trackstaticsObj.isValid() ? "Geçerli" : "Geçersiz") << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Hata: " << e.what() << std::endl;
        return 1;
    }
    
    std::cout << "\n🎉 Tüm testler tamamlandı!" << std::endl;
    return 0;
}
