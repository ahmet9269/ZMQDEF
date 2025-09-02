#pragma once
#include <string>
#include <cstdint>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <cstring>

/**
 * @brief Bir izin ECEF koordinat sistemindeki extrapolation yapılmış kinematik durumunu ve detaylı zamanlama bilgilerini içerir.
 * Auto-generated from ExtrapTrackData.json
 */
class ExtrapTrackData {
public:
    // Network configuration constants
    static constexpr const char* MULTICAST_ADDRESS = "239.1.1.5";
    static constexpr int PORT = 9596;

    // Constructor
    ExtrapTrackData();
    
    // Destructor
    ~ExtrapTrackData() = default;
    
    // Getters and Setters
    uint32_t getTrackId() const;
    void setTrackId(const uint32_t& value);

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

    // Validation
    bool isValid() const;

    // Binary Serialization
    std::vector<uint8_t> serialize() const;
    bool deserialize(const std::vector<uint8_t>& data);
    size_t getSerializedSize() const;

private:
    // Member variables
    uint32_t trackId_;
    float xVelocityECEF_;
    double yVelocityECEF_;
    double zVelocityECEF_;
    double xPositionECEF_;
    double yPositionECEF_;
    double zPositionECEF_;
    int64_t originalUpdateTime_;
    int64_t updateTime_;
    int64_t firstHopSentTime_;

    // Validation functions
    void validateTrackId(uint32_t value) const;
    void validateXVelocityECEF(float value) const;
    void validateYVelocityECEF(double value) const;
    void validateZVelocityECEF(double value) const;
    void validateXPositionECEF(double value) const;
    void validateYPositionECEF(double value) const;
    void validateZPositionECEF(double value) const;
    void validateOriginalUpdateTime(int64_t value) const;
    void validateUpdateTime(int64_t value) const;
    void validateFirstHopSentTime(int64_t value) const;
};
