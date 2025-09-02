#include "TrackStatics.hpp"

// Constructor
TrackStatics::TrackStatics() {
    trackId_ = 0;
    firstHopDelayDataMean_ = 0;
    firstHopDelayDataStd_ = 0;
    firstHopDelayDataMin_ = 0;
    firstHopDelayDataMax_ = 0;
    secondHopDelayDataMean_ = 0;
    secondHopDelayDataStd_ = 0;
    secondHopDelayDataMin_ = 0;
    secondHopDelayDataMax_ = 0;
    totalHopDelayDataMean_ = 0;
    totalHopDelayDataStd_ = 0;
    totalHopDelayDataMin_ = 0;
    totalHopDelayDataMax_ = 0;
    updateTime_ = 0;
}

    void TrackStatics::validateTrackId(int64_t value) const {
        if (value < -9223372036854775808LL || value > 9223372036854775807LL) {
            throw std::out_of_range("TrackId value is out of valid range: " + std::to_string(value));
        }
    }

    void TrackStatics::validateFirstHopDelayDataMean(double value) const {
        if (std::isnan(value) || value < 0 || value > 1.0E+6) {
            throw std::out_of_range("FirstHopDelayDataMean value is out of valid range: " + std::to_string(value));
        }
    }

    void TrackStatics::validateFirstHopDelayDataStd(double value) const {
        if (std::isnan(value) || value < 0 || value > 1.0E+6) {
            throw std::out_of_range("FirstHopDelayDataStd value is out of valid range: " + std::to_string(value));
        }
    }

    void TrackStatics::validateFirstHopDelayDataMin(double value) const {
        if (std::isnan(value) || value < 0 || value > 1.0E+6) {
            throw std::out_of_range("FirstHopDelayDataMin value is out of valid range: " + std::to_string(value));
        }
    }

    void TrackStatics::validateFirstHopDelayDataMax(double value) const {
        if (std::isnan(value) || value < 0 || value > 1.0E+6) {
            throw std::out_of_range("FirstHopDelayDataMax value is out of valid range: " + std::to_string(value));
        }
    }

    void TrackStatics::validateSecondHopDelayDataMean(double value) const {
        if (std::isnan(value) || value < 0 || value > 1.0E+6) {
            throw std::out_of_range("SecondHopDelayDataMean value is out of valid range: " + std::to_string(value));
        }
    }

    void TrackStatics::validateSecondHopDelayDataStd(double value) const {
        if (std::isnan(value) || value < 0 || value > 1.0E+6) {
            throw std::out_of_range("SecondHopDelayDataStd value is out of valid range: " + std::to_string(value));
        }
    }

    void TrackStatics::validateSecondHopDelayDataMin(double value) const {
        if (std::isnan(value) || value < 0 || value > 1.0E+6) {
            throw std::out_of_range("SecondHopDelayDataMin value is out of valid range: " + std::to_string(value));
        }
    }

    void TrackStatics::validateSecondHopDelayDataMax(double value) const {
        if (std::isnan(value) || value < 0 || value > 1.0E+6) {
            throw std::out_of_range("SecondHopDelayDataMax value is out of valid range: " + std::to_string(value));
        }
    }

    void TrackStatics::validateTotalHopDelayDataMean(double value) const {
        if (std::isnan(value) || value < 0 || value > 1.0E+6) {
            throw std::out_of_range("TotalHopDelayDataMean value is out of valid range: " + std::to_string(value));
        }
    }

    void TrackStatics::validateTotalHopDelayDataStd(double value) const {
        if (std::isnan(value) || value < 0 || value > 1.0E+6) {
            throw std::out_of_range("TotalHopDelayDataStd value is out of valid range: " + std::to_string(value));
        }
    }

    void TrackStatics::validateTotalHopDelayDataMin(double value) const {
        if (std::isnan(value) || value < 0 || value > 1.0E+6) {
            throw std::out_of_range("TotalHopDelayDataMin value is out of valid range: " + std::to_string(value));
        }
    }

    void TrackStatics::validateTotalHopDelayDataMax(double value) const {
        if (std::isnan(value) || value < 0 || value > 1.0E+6) {
            throw std::out_of_range("TotalHopDelayDataMax value is out of valid range: " + std::to_string(value));
        }
    }

    void TrackStatics::validateUpdateTime(int64_t value) const {
        if (value < -9223372036854775808LL || value > 9223372036854775807LL) {
            throw std::out_of_range("UpdateTime value is out of valid range: " + std::to_string(value));
        }
    }

int64_t TrackStatics::getTrackId() const {
    return trackId_;
}

void TrackStatics::setTrackId(const int64_t& value) {
    validateTrackId(value);
    trackId_ = value;
}

double TrackStatics::getFirstHopDelayDataMean() const {
    return firstHopDelayDataMean_;
}

void TrackStatics::setFirstHopDelayDataMean(const double& value) {
    validateFirstHopDelayDataMean(value);
    firstHopDelayDataMean_ = value;
}

double TrackStatics::getFirstHopDelayDataStd() const {
    return firstHopDelayDataStd_;
}

void TrackStatics::setFirstHopDelayDataStd(const double& value) {
    validateFirstHopDelayDataStd(value);
    firstHopDelayDataStd_ = value;
}

double TrackStatics::getFirstHopDelayDataMin() const {
    return firstHopDelayDataMin_;
}

void TrackStatics::setFirstHopDelayDataMin(const double& value) {
    validateFirstHopDelayDataMin(value);
    firstHopDelayDataMin_ = value;
}

double TrackStatics::getFirstHopDelayDataMax() const {
    return firstHopDelayDataMax_;
}

void TrackStatics::setFirstHopDelayDataMax(const double& value) {
    validateFirstHopDelayDataMax(value);
    firstHopDelayDataMax_ = value;
}

double TrackStatics::getSecondHopDelayDataMean() const {
    return secondHopDelayDataMean_;
}

void TrackStatics::setSecondHopDelayDataMean(const double& value) {
    validateSecondHopDelayDataMean(value);
    secondHopDelayDataMean_ = value;
}

double TrackStatics::getSecondHopDelayDataStd() const {
    return secondHopDelayDataStd_;
}

void TrackStatics::setSecondHopDelayDataStd(const double& value) {
    validateSecondHopDelayDataStd(value);
    secondHopDelayDataStd_ = value;
}

double TrackStatics::getSecondHopDelayDataMin() const {
    return secondHopDelayDataMin_;
}

void TrackStatics::setSecondHopDelayDataMin(const double& value) {
    validateSecondHopDelayDataMin(value);
    secondHopDelayDataMin_ = value;
}

double TrackStatics::getSecondHopDelayDataMax() const {
    return secondHopDelayDataMax_;
}

void TrackStatics::setSecondHopDelayDataMax(const double& value) {
    validateSecondHopDelayDataMax(value);
    secondHopDelayDataMax_ = value;
}

double TrackStatics::getTotalHopDelayDataMean() const {
    return totalHopDelayDataMean_;
}

void TrackStatics::setTotalHopDelayDataMean(const double& value) {
    validateTotalHopDelayDataMean(value);
    totalHopDelayDataMean_ = value;
}

double TrackStatics::getTotalHopDelayDataStd() const {
    return totalHopDelayDataStd_;
}

void TrackStatics::setTotalHopDelayDataStd(const double& value) {
    validateTotalHopDelayDataStd(value);
    totalHopDelayDataStd_ = value;
}

double TrackStatics::getTotalHopDelayDataMin() const {
    return totalHopDelayDataMin_;
}

void TrackStatics::setTotalHopDelayDataMin(const double& value) {
    validateTotalHopDelayDataMin(value);
    totalHopDelayDataMin_ = value;
}

double TrackStatics::getTotalHopDelayDataMax() const {
    return totalHopDelayDataMax_;
}

void TrackStatics::setTotalHopDelayDataMax(const double& value) {
    validateTotalHopDelayDataMax(value);
    totalHopDelayDataMax_ = value;
}

int64_t TrackStatics::getUpdateTime() const {
    return updateTime_;
}

void TrackStatics::setUpdateTime(const int64_t& value) {
    validateUpdateTime(value);
    updateTime_ = value;
}

bool TrackStatics::isValid() const {
    try {
        validateTrackId(trackId_);
        validateFirstHopDelayDataMean(firstHopDelayDataMean_);
        validateFirstHopDelayDataStd(firstHopDelayDataStd_);
        validateFirstHopDelayDataMin(firstHopDelayDataMin_);
        validateFirstHopDelayDataMax(firstHopDelayDataMax_);
        validateSecondHopDelayDataMean(secondHopDelayDataMean_);
        validateSecondHopDelayDataStd(secondHopDelayDataStd_);
        validateSecondHopDelayDataMin(secondHopDelayDataMin_);
        validateSecondHopDelayDataMax(secondHopDelayDataMax_);
        validateTotalHopDelayDataMean(totalHopDelayDataMean_);
        validateTotalHopDelayDataStd(totalHopDelayDataStd_);
        validateTotalHopDelayDataMin(totalHopDelayDataMin_);
        validateTotalHopDelayDataMax(totalHopDelayDataMax_);
        validateUpdateTime(updateTime_);
        return true;
    } catch (const std::exception&) {
        return false;
    }
}

// Binary Serialization Implementation
std::vector<uint8_t> TrackStatics::serialize() const {
    std::vector<uint8_t> buffer;
    buffer.reserve(getSerializedSize());
    
    // Serialize trackId_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&trackId_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(trackId_));
    }
    
    // Serialize firstHopDelayDataMean_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&firstHopDelayDataMean_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(firstHopDelayDataMean_));
    }
    
    // Serialize firstHopDelayDataStd_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&firstHopDelayDataStd_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(firstHopDelayDataStd_));
    }
    
    // Serialize firstHopDelayDataMin_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&firstHopDelayDataMin_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(firstHopDelayDataMin_));
    }
    
    // Serialize firstHopDelayDataMax_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&firstHopDelayDataMax_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(firstHopDelayDataMax_));
    }
    
    // Serialize secondHopDelayDataMean_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&secondHopDelayDataMean_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(secondHopDelayDataMean_));
    }
    
    // Serialize secondHopDelayDataStd_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&secondHopDelayDataStd_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(secondHopDelayDataStd_));
    }
    
    // Serialize secondHopDelayDataMin_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&secondHopDelayDataMin_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(secondHopDelayDataMin_));
    }
    
    // Serialize secondHopDelayDataMax_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&secondHopDelayDataMax_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(secondHopDelayDataMax_));
    }
    
    // Serialize totalHopDelayDataMean_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&totalHopDelayDataMean_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(totalHopDelayDataMean_));
    }
    
    // Serialize totalHopDelayDataStd_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&totalHopDelayDataStd_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(totalHopDelayDataStd_));
    }
    
    // Serialize totalHopDelayDataMin_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&totalHopDelayDataMin_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(totalHopDelayDataMin_));
    }
    
    // Serialize totalHopDelayDataMax_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&totalHopDelayDataMax_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(totalHopDelayDataMax_));
    }
    
    // Serialize updateTime_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&updateTime_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(updateTime_));
    }
    
    return buffer;
}

bool TrackStatics::deserialize(const std::vector<uint8_t>& data) {
    if (data.size() < getSerializedSize()) {
        return false;
    }
    
    size_t offset = 0;
    
    // Deserialize trackId_
    if (offset + sizeof(trackId_) <= data.size()) {
        std::memcpy(&trackId_, &data[offset], sizeof(trackId_));
        offset += sizeof(trackId_);
    } else {
        return false;
    }
    
    // Deserialize firstHopDelayDataMean_
    if (offset + sizeof(firstHopDelayDataMean_) <= data.size()) {
        std::memcpy(&firstHopDelayDataMean_, &data[offset], sizeof(firstHopDelayDataMean_));
        offset += sizeof(firstHopDelayDataMean_);
    } else {
        return false;
    }
    
    // Deserialize firstHopDelayDataStd_
    if (offset + sizeof(firstHopDelayDataStd_) <= data.size()) {
        std::memcpy(&firstHopDelayDataStd_, &data[offset], sizeof(firstHopDelayDataStd_));
        offset += sizeof(firstHopDelayDataStd_);
    } else {
        return false;
    }
    
    // Deserialize firstHopDelayDataMin_
    if (offset + sizeof(firstHopDelayDataMin_) <= data.size()) {
        std::memcpy(&firstHopDelayDataMin_, &data[offset], sizeof(firstHopDelayDataMin_));
        offset += sizeof(firstHopDelayDataMin_);
    } else {
        return false;
    }
    
    // Deserialize firstHopDelayDataMax_
    if (offset + sizeof(firstHopDelayDataMax_) <= data.size()) {
        std::memcpy(&firstHopDelayDataMax_, &data[offset], sizeof(firstHopDelayDataMax_));
        offset += sizeof(firstHopDelayDataMax_);
    } else {
        return false;
    }
    
    // Deserialize secondHopDelayDataMean_
    if (offset + sizeof(secondHopDelayDataMean_) <= data.size()) {
        std::memcpy(&secondHopDelayDataMean_, &data[offset], sizeof(secondHopDelayDataMean_));
        offset += sizeof(secondHopDelayDataMean_);
    } else {
        return false;
    }
    
    // Deserialize secondHopDelayDataStd_
    if (offset + sizeof(secondHopDelayDataStd_) <= data.size()) {
        std::memcpy(&secondHopDelayDataStd_, &data[offset], sizeof(secondHopDelayDataStd_));
        offset += sizeof(secondHopDelayDataStd_);
    } else {
        return false;
    }
    
    // Deserialize secondHopDelayDataMin_
    if (offset + sizeof(secondHopDelayDataMin_) <= data.size()) {
        std::memcpy(&secondHopDelayDataMin_, &data[offset], sizeof(secondHopDelayDataMin_));
        offset += sizeof(secondHopDelayDataMin_);
    } else {
        return false;
    }
    
    // Deserialize secondHopDelayDataMax_
    if (offset + sizeof(secondHopDelayDataMax_) <= data.size()) {
        std::memcpy(&secondHopDelayDataMax_, &data[offset], sizeof(secondHopDelayDataMax_));
        offset += sizeof(secondHopDelayDataMax_);
    } else {
        return false;
    }
    
    // Deserialize totalHopDelayDataMean_
    if (offset + sizeof(totalHopDelayDataMean_) <= data.size()) {
        std::memcpy(&totalHopDelayDataMean_, &data[offset], sizeof(totalHopDelayDataMean_));
        offset += sizeof(totalHopDelayDataMean_);
    } else {
        return false;
    }
    
    // Deserialize totalHopDelayDataStd_
    if (offset + sizeof(totalHopDelayDataStd_) <= data.size()) {
        std::memcpy(&totalHopDelayDataStd_, &data[offset], sizeof(totalHopDelayDataStd_));
        offset += sizeof(totalHopDelayDataStd_);
    } else {
        return false;
    }
    
    // Deserialize totalHopDelayDataMin_
    if (offset + sizeof(totalHopDelayDataMin_) <= data.size()) {
        std::memcpy(&totalHopDelayDataMin_, &data[offset], sizeof(totalHopDelayDataMin_));
        offset += sizeof(totalHopDelayDataMin_);
    } else {
        return false;
    }
    
    // Deserialize totalHopDelayDataMax_
    if (offset + sizeof(totalHopDelayDataMax_) <= data.size()) {
        std::memcpy(&totalHopDelayDataMax_, &data[offset], sizeof(totalHopDelayDataMax_));
        offset += sizeof(totalHopDelayDataMax_);
    } else {
        return false;
    }
    
    // Deserialize updateTime_
    if (offset + sizeof(updateTime_) <= data.size()) {
        std::memcpy(&updateTime_, &data[offset], sizeof(updateTime_));
        offset += sizeof(updateTime_);
    } else {
        return false;
    }
    
    return true;
}

size_t TrackStatics::getSerializedSize() const {
    size_t size = 0;
    
    size += sizeof(trackId_);  // uint32_t
    size += sizeof(firstHopDelayDataMean_);  // float
    size += sizeof(firstHopDelayDataStd_);  // float
    size += sizeof(firstHopDelayDataMin_);  // float
    size += sizeof(firstHopDelayDataMax_);  // float
    size += sizeof(secondHopDelayDataMean_);  // float
    size += sizeof(secondHopDelayDataStd_);  // float
    size += sizeof(secondHopDelayDataMin_);  // float
    size += sizeof(secondHopDelayDataMax_);  // float
    size += sizeof(totalHopDelayDataMean_);  // float
    size += sizeof(totalHopDelayDataStd_);  // float
    size += sizeof(totalHopDelayDataMin_);  // float
    size += sizeof(totalHopDelayDataMax_);  // float
    size += sizeof(updateTime_);  // uint32_t
    
    return size;
}
