#pragma once
#include <string>
#include <cstdint>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <cstring>

/**
 * @brief İşlenmiş bir izin ECEF koordinat sistemindeki kinematik durumunu ve güncelleme zamanını içerir.
 * Auto-generated from ProcessedTrackData.json
 */
class ProcessedTrackData {
public:
    // Network configuration constants
    static constexpr const char* MULTICAST_ADDRESS = "239.1.1.5";
    static constexpr int PORT = 9598;

    // Constructor
    ProcessedTrackData();
    
    // Destructor
    ~ProcessedTrackData() = default;
    
    // Getters and Setters
    int64_t getTrackId() const;
    void setTrackId(const int64_t& value);

    double getXVelocityECEF() const;
    void setXVelocityECEF(const double& value);

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

    int64_t getUpdateTime() const;
    void setUpdateTime(const int64_t& value);

    // Validation
    bool isValid() const;

    // Binary Serialization
    std::vector<uint8_t> serialize() const;
    bool deserialize(const std::vector<uint8_t>& data);
    size_t getSerializedSize() const;

private:
    // Member variables
    int64_t trackId_;
    double xVelocityECEF_;
    double yVelocityECEF_;
    double zVelocityECEF_;
    double xPositionECEF_;
    double yPositionECEF_;
    double zPositionECEF_;
    int64_t updateTime_;

    // Validation functions
    void validateTrackId(int64_t value) const;
    void validateXVelocityECEF(double value) const;
    void validateYVelocityECEF(double value) const;
    void validateZVelocityECEF(double value) const;
    void validateXPositionECEF(double value) const;
    void validateYPositionECEF(double value) const;
    void validateZPositionECEF(double value) const;
    void validateUpdateTime(int64_t value) const;
};
