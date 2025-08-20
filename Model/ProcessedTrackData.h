#pragma once
#include <string>
#include <cstdint>
#include <stdexcept>
#include <cmath>

/**
 * @brief İşlenmiş bir izin ECEF koordinat sistemindeki kinematik durumunu ve güncelleme zamanını içerir.
 * Auto-generated from ProcessedTrackData.json
 */
class ProcessedTrackData {
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
    void validateTrackId(int64_t value) const {
        if (value < -9223372036854775808LL || value > 9223372036854775807LL) {
            throw std::out_of_range("TrackId değeri geçerli aralık dışında: " + std::to_string(value));
        }
    }

    void validateXVelocityECEF(double value) const {
        if (std::isnan(value) || value < -1.0e+6 || value > 1.0e+6) {
            throw std::out_of_range("XVelocityECEF değeri geçerli aralık dışında: " + std::to_string(value));
        }
    }

    void validateYVelocityECEF(double value) const {
        if (std::isnan(value) || value < -1.0e+6 || value > 1.0e+6) {
            throw std::out_of_range("YVelocityECEF değeri geçerli aralık dışında: " + std::to_string(value));
        }
    }

    void validateZVelocityECEF(double value) const {
        if (std::isnan(value) || value < -1.0e+6 || value > 1.0e+6) {
            throw std::out_of_range("ZVelocityECEF değeri geçerli aralık dışında: " + std::to_string(value));
        }
    }

    void validateXPositionECEF(double value) const {
        if (std::isnan(value) || value < -9.9e+10 || value > 9.9e+10) {
            throw std::out_of_range("XPositionECEF değeri geçerli aralık dışında: " + std::to_string(value));
        }
    }

    void validateYPositionECEF(double value) const {
        if (std::isnan(value) || value < -9.9e+10 || value > 9.9e+10) {
            throw std::out_of_range("YPositionECEF değeri geçerli aralık dışında: " + std::to_string(value));
        }
    }

    void validateZPositionECEF(double value) const {
        if (std::isnan(value) || value < -9.9e+10 || value > 9.9e+10) {
            throw std::out_of_range("ZPositionECEF değeri geçerli aralık dışında: " + std::to_string(value));
        }
    }

    void validateUpdateTime(int64_t value) const {
        if (value < -9223372036854775808LL || value > 9223372036854775807LL) {
            throw std::out_of_range("UpdateTime değeri geçerli aralık dışında: " + std::to_string(value));
        }
    }

public:
    // Constructor
    ProcessedTrackData() {
        trackId_ = 0;
        xVelocityECEF_ = 0.0;
        yVelocityECEF_ = 0.0;
        zVelocityECEF_ = 0.0;
        xPositionECEF_ = 0.0;
        yPositionECEF_ = 0.0;
        zPositionECEF_ = 0.0;
        updateTime_ = 0;
    }
    
    // Destructor
    ~ProcessedTrackData() = default;
    
    // Getters and Setters
    int64_t getTrackId() const {
        return trackId_;
    }

    void setTrackId(const int64_t& value) {
        validateTrackId(value);
        trackId_ = value;
    }

    double getXVelocityECEF() const {
        return xVelocityECEF_;
    }

    void setXVelocityECEF(const double& value) {
        validateXVelocityECEF(value);
        xVelocityECEF_ = value;
    }

    double getYVelocityECEF() const {
        return yVelocityECEF_;
    }

    void setYVelocityECEF(const double& value) {
        validateYVelocityECEF(value);
        yVelocityECEF_ = value;
    }

    double getZVelocityECEF() const {
        return zVelocityECEF_;
    }

    void setZVelocityECEF(const double& value) {
        validateZVelocityECEF(value);
        zVelocityECEF_ = value;
    }

    double getXPositionECEF() const {
        return xPositionECEF_;
    }

    void setXPositionECEF(const double& value) {
        validateXPositionECEF(value);
        xPositionECEF_ = value;
    }

    double getYPositionECEF() const {
        return yPositionECEF_;
    }

    void setYPositionECEF(const double& value) {
        validateYPositionECEF(value);
        yPositionECEF_ = value;
    }

    double getZPositionECEF() const {
        return zPositionECEF_;
    }

    void setZPositionECEF(const double& value) {
        validateZPositionECEF(value);
        zPositionECEF_ = value;
    }

    int64_t getUpdateTime() const {
        return updateTime_;
    }

    void setUpdateTime(const int64_t& value) {
        validateUpdateTime(value);
        updateTime_ = value;
    }

    // Validation
    bool isValid() const {
        try {
            validateTrackId(trackId_);
            validateXVelocityECEF(xVelocityECEF_);
            validateYVelocityECEF(yVelocityECEF_);
            validateZVelocityECEF(zVelocityECEF_);
            validateXPositionECEF(xPositionECEF_);
            validateYPositionECEF(yPositionECEF_);
            validateZPositionECEF(zPositionECEF_);
            validateUpdateTime(updateTime_);
            return true;
        } catch (const std::exception&) {
            return false;
        }
    }
};
