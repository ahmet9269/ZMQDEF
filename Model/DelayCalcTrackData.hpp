#pragma once
#include <string>
#include <cstdint>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <cstring>

/**
 * @brief Bir izin ECEF koordinat sistemindeki durumunu ve çok adımlı (multi-hop) gecikme hesaplama bilgilerini içerir. Sadece teknik veri tipi limitleri uygulanmıştır.
 * Auto-generated from DelayCalcTrackData.json
 */
class DelayCalcTrackData {
public:
    // Network configuration constants
    static constexpr const char* MULTICAST_ADDRESS = "239.1.1.5";
    static constexpr int PORT = 9595;

    // Constructor
    DelayCalcTrackData();
    
    // Destructor
    ~DelayCalcTrackData() = default;
    
    // Getters and Setters
    uint16_t getTrackId() const;
    void setTrackId(const uint16_t& value);

    float getXVelocityECEF() const;
    void setXVelocityECEF(const float& value);

    double getYVelocityECEF() const;
    void setYVelocityECEF(const double& value);

    double getZVelocityECEF() const;
    void setZVelocityECEF(const double& value);

    double getXPositionECEF() const;
    void setXPositionECEF(const double& value);

    double getYPositionECEF() const;
    void setYPositionECEF(const double& value);

    double getZPositionECEF() const;
    void setZPositionECEF(const double& value);

    int64_t getOriginalUpdateTime() const;
    void setOriginalUpdateTime(const int64_t& value);

    int64_t getUpdateTime() const;
    void setUpdateTime(const int64_t& value);

    int64_t getFirstHopSentTime() const;
    void setFirstHopSentTime(const int64_t& value);

    int64_t getFirstHopDelayTime() const;
    void setFirstHopDelayTime(const int64_t& value);

    int64_t getSecondHopSentTime() const;
    void setSecondHopSentTime(const int64_t& value);

    // Validation
    bool isValid() const;

    // Binary Serialization
    std::vector<uint8_t> serialize() const;
    bool deserialize(const std::vector<uint8_t>& data);
    size_t getSerializedSize() const;

private:
    // Member variables
    uint16_t trackId_;
    float xVelocityECEF_;
    double yVelocityECEF_;
    double zVelocityECEF_;
    double xPositionECEF_;
    double yPositionECEF_;
    double zPositionECEF_;
    int64_t originalUpdateTime_;
    int64_t updateTime_;
    int64_t firstHopSentTime_;
    int64_t firstHopDelayTime_;
    int64_t secondHopSentTime_;

    // Validation functions
    void validateTrackId(uint16_t value) const;
    void validateXVelocityECEF(float value) const;
    void validateYVelocityECEF(double value) const;
    void validateZVelocityECEF(double value) const;
    void validateXPositionECEF(double value) const;
    void validateYPositionECEF(double value) const;
    void validateZPositionECEF(double value) const;
    void validateOriginalUpdateTime(int64_t value) const;
    void validateUpdateTime(int64_t value) const;
    void validateFirstHopSentTime(int64_t value) const;
    void validateFirstHopDelayTime(int64_t value) const;
    void validateSecondHopSentTime(int64_t value) const;
};
