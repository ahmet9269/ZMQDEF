#pragma once
#include <string>
#include <cstdint>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <cstring>

/**
 * @brief Bir izin çok adımlı (multi-hop) gecikme verilerinin istatistiksel analizini (ortalama, standart sapma, min/max) içerir.
 * Auto-generated from TrackStatics.json
 */
class TrackStatics {
public:
    // Network configuration constants
    static constexpr const char* MULTICAST_ADDRESS = "239.1.1.5";
    static constexpr int PORT = 9599;

    // Constructor
    TrackStatics();
    
    // Destructor
    ~TrackStatics() = default;
    
    // Getters and Setters
    int64_t getTrackId() const;
    void setTrackId(const int64_t& value);

    double getFirstHopDelayDataMean() const;
    void setFirstHopDelayDataMean(const double& value);

    double getFirstHopDelayDataStd() const;
    void setFirstHopDelayDataStd(const double& value);

    double getFirstHopDelayDataMin() const;
    void setFirstHopDelayDataMin(const double& value);

    double getFirstHopDelayDataMax() const;
    void setFirstHopDelayDataMax(const double& value);

    double getSecondHopDelayDataMean() const;
    void setSecondHopDelayDataMean(const double& value);

    double getSecondHopDelayDataStd() const;
    void setSecondHopDelayDataStd(const double& value);

    double getSecondHopDelayDataMin() const;
    void setSecondHopDelayDataMin(const double& value);

    double getSecondHopDelayDataMax() const;
    void setSecondHopDelayDataMax(const double& value);

    double getTotalHopDelayDataMean() const;
    void setTotalHopDelayDataMean(const double& value);

    double getTotalHopDelayDataStd() const;
    void setTotalHopDelayDataStd(const double& value);

    double getTotalHopDelayDataMin() const;
    void setTotalHopDelayDataMin(const double& value);

    double getTotalHopDelayDataMax() const;
    void setTotalHopDelayDataMax(const double& value);

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
    double firstHopDelayDataMean_;
    double firstHopDelayDataStd_;
    double firstHopDelayDataMin_;
    double firstHopDelayDataMax_;
    double secondHopDelayDataMean_;
    double secondHopDelayDataStd_;
    double secondHopDelayDataMin_;
    double secondHopDelayDataMax_;
    double totalHopDelayDataMean_;
    double totalHopDelayDataStd_;
    double totalHopDelayDataMin_;
    double totalHopDelayDataMax_;
    int64_t updateTime_;

    // Validation functions
    void validateTrackId(int64_t value) const;
    void validateFirstHopDelayDataMean(double value) const;
    void validateFirstHopDelayDataStd(double value) const;
    void validateFirstHopDelayDataMin(double value) const;
    void validateFirstHopDelayDataMax(double value) const;
    void validateSecondHopDelayDataMean(double value) const;
    void validateSecondHopDelayDataStd(double value) const;
    void validateSecondHopDelayDataMin(double value) const;
    void validateSecondHopDelayDataMax(double value) const;
    void validateTotalHopDelayDataMean(double value) const;
    void validateTotalHopDelayDataStd(double value) const;
    void validateTotalHopDelayDataMin(double value) const;
    void validateTotalHopDelayDataMax(double value) const;
    void validateUpdateTime(int64_t value) const;
};
