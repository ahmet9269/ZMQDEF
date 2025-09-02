#pragma once

// MISRA C++ 2023 compliant includes
#include <string>
#include <cstdint>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <cstring>

/**
 * @brief İşlenmiş bir izin ECEF koordinat sistemindeki kinematik durumunu ve güncelleme zamanını içerir.
 * Auto-generated from ProcessedTrackData.json
 * MISRA C++ 2023 compliant implementation
 */
class ProcessedTrackData final {
public:
    // Network configuration constants
    static constexpr const char* MULTICAST_ADDRESS = "239.1.1.5";
    static constexpr int PORT = 9598;

    // MISRA C++ 2023 compliant constructors
    explicit ProcessedTrackData() noexcept;
    
    // Copy constructor
    ProcessedTrackData(const ProcessedTrackData& other) = default;
    
    // Move constructor
    ProcessedTrackData(ProcessedTrackData&& other) noexcept = default;
    
    // Copy assignment operator
    ProcessedTrackData& operator=(const ProcessedTrackData& other) = default;
    
    // Move assignment operator
    ProcessedTrackData& operator=(ProcessedTrackData&& other) noexcept = default;
    
    // Destructor
    ~ProcessedTrackData() = default;
    
    // Getters and Setters
    int64_t getTrackId() const noexcept;
    void setTrackId(const int64_t& value);

    double getXVelocityECEF() const noexcept;
    void setXVelocityECEF(const double& value);

    double getYVelocityECEF() const noexcept;
    void setYVelocityECEF(const double& value);

    double getZVelocityECEF() const noexcept;
    void setZVelocityECEF(const double& value);

    double getXPositionECEF() const noexcept;
    void setXPositionECEF(const double& value);

    double getYPositionECEF() const noexcept;
    void setYPositionECEF(const double& value);

    double getZPositionECEF() const noexcept;
    void setZPositionECEF(const double& value);

    int64_t getUpdateTime() const noexcept;
    void setUpdateTime(const int64_t& value);

    // Validation - MISRA compliant
    [[nodiscard]] bool isValid() const noexcept;

    // Binary Serialization - MISRA compliant
    [[nodiscard]] std::vector<uint8_t> serialize() const;
    bool deserialize(const std::vector<uint8_t>& data) noexcept;
    [[nodiscard]] std::size_t getSerializedSize() const noexcept;

private:
    // Member variables
    /// İz için benzersiz tam sayı kimliği
    int64_t trackId_;
    /// ECEF koordinatlarındaki X ekseni hızı (m/s)
    double xVelocityECEF_;
    /// ECEF koordinatlarındaki Y ekseni hızı (m/s)
    double yVelocityECEF_;
    /// ECEF koordinatlarındaki Z ekseni hızı (m/s)
    double zVelocityECEF_;
    /// ECEF koordinatlarındaki X ekseni konumu (metre)
    double xPositionECEF_;
    /// ECEF koordinatlarındaki Y ekseni konumu (metre)
    double yPositionECEF_;
    /// ECEF koordinatlarındaki Z ekseni konumu (metre)
    double zPositionECEF_;
    /// Son güncelleme zamanı (nanosaniye)
    int64_t updateTime_;

    // Validation functions - MISRA compliant
    void validateTrackId(int64_t value) const;
    void validateXVelocityECEF(double value) const;
    void validateYVelocityECEF(double value) const;
    void validateZVelocityECEF(double value) const;
    void validateXPositionECEF(double value) const;
    void validateYPositionECEF(double value) const;
    void validateZPositionECEF(double value) const;
    void validateUpdateTime(int64_t value) const;
};
