#include "FinalCalcTrackData.hpp"

// Constructor
FinalCalcTrackData::FinalCalcTrackData() {
    trackId_ = 0;
    xVelocityECEF_ = 0;
    yVelocityECEF_ = 0;
    zVelocityECEF_ = 0;
    xPositionECEF_ = 0;
    yPositionECEF_ = 0;
    zPositionECEF_ = 0;
    originalUpdateTime_ = 0;
    updateTime_ = 0;
    firstHopSentTime_ = 0;
    firstHopDelayTime_ = 0;
    secondHopSentTime_ = 0;
    secondHopDelayTime_ = 0;
    totalDelayTime_ = 0;
    thirdHopSentTime_ = 0;
}

    void FinalCalcTrackData::validateTrackId(int64_t value) const {
        if (value < -9223372036854775808LL || value > 9223372036854775807LL) {
            throw std::out_of_range("TrackId value is out of valid range: " + std::to_string(value));
        }
    }

    void FinalCalcTrackData::validateXVelocityECEF(double value) const {
        if (std::isnan(value) || value < -1.0E+6 || value > 1.0E+6) {
            throw std::out_of_range("XVelocityECEF value is out of valid range: " + std::to_string(value));
        }
    }

    void FinalCalcTrackData::validateYVelocityECEF(double value) const {
        if (std::isnan(value) || value < -1.0E+6 || value > 1.0E+6) {
            throw std::out_of_range("YVelocityECEF value is out of valid range: " + std::to_string(value));
        }
    }

    void FinalCalcTrackData::validateZVelocityECEF(double value) const {
        if (std::isnan(value) || value < -1.0E+6 || value > 1.0E+6) {
            throw std::out_of_range("ZVelocityECEF value is out of valid range: " + std::to_string(value));
        }
    }

    void FinalCalcTrackData::validateXPositionECEF(double value) const {
        if (std::isnan(value) || value < -9.9E+10 || value > 9.9E+10) {
            throw std::out_of_range("XPositionECEF value is out of valid range: " + std::to_string(value));
        }
    }

    void FinalCalcTrackData::validateYPositionECEF(double value) const {
        if (std::isnan(value) || value < -9.9E+10 || value > 9.9E+10) {
            throw std::out_of_range("YPositionECEF value is out of valid range: " + std::to_string(value));
        }
    }

    void FinalCalcTrackData::validateZPositionECEF(double value) const {
        if (std::isnan(value) || value < -9.9E+10 || value > 9.9E+10) {
            throw std::out_of_range("ZPositionECEF value is out of valid range: " + std::to_string(value));
        }
    }

    void FinalCalcTrackData::validateOriginalUpdateTime(int64_t value) const {
        if (value < -9223372036854775808LL || value > 9223372036854775807LL) {
            throw std::out_of_range("OriginalUpdateTime value is out of valid range: " + std::to_string(value));
        }
    }

    void FinalCalcTrackData::validateUpdateTime(int64_t value) const {
        if (value < -9223372036854775808LL || value > 9223372036854775807LL) {
            throw std::out_of_range("UpdateTime value is out of valid range: " + std::to_string(value));
        }
    }

    void FinalCalcTrackData::validateFirstHopSentTime(int64_t value) const {
        if (value < -9223372036854775808LL || value > 9223372036854775807LL) {
            throw std::out_of_range("FirstHopSentTime value is out of valid range: " + std::to_string(value));
        }
    }

    void FinalCalcTrackData::validateFirstHopDelayTime(int64_t value) const {
        if (value < -9223372036854775808LL || value > 9223372036854775807LL) {
            throw std::out_of_range("FirstHopDelayTime value is out of valid range: " + std::to_string(value));
        }
    }

    void FinalCalcTrackData::validateSecondHopSentTime(int64_t value) const {
        if (value < -9223372036854775808LL || value > 9223372036854775807LL) {
            throw std::out_of_range("SecondHopSentTime value is out of valid range: " + std::to_string(value));
        }
    }

    void FinalCalcTrackData::validateSecondHopDelayTime(int64_t value) const {
        if (value < -9223372036854775808LL || value > 9223372036854775807LL) {
            throw std::out_of_range("SecondHopDelayTime value is out of valid range: " + std::to_string(value));
        }
    }

    void FinalCalcTrackData::validateTotalDelayTime(int64_t value) const {
        if (value < -9223372036854775808LL || value > 9223372036854775807LL) {
            throw std::out_of_range("TotalDelayTime value is out of valid range: " + std::to_string(value));
        }
    }

    void FinalCalcTrackData::validateThirdHopSentTime(int64_t value) const {
        if (value < -9223372036854775808LL || value > 9223372036854775807LL) {
            throw std::out_of_range("ThirdHopSentTime value is out of valid range: " + std::to_string(value));
        }
    }

int64_t FinalCalcTrackData::getTrackId() const {
    return trackId_;
}

void FinalCalcTrackData::setTrackId(const int64_t& value) {
    validateTrackId(value);
    trackId_ = value;
}

double FinalCalcTrackData::getXVelocityECEF() const {
    return xVelocityECEF_;
}

void FinalCalcTrackData::setXVelocityECEF(const double& value) {
    validateXVelocityECEF(value);
    xVelocityECEF_ = value;
}

double FinalCalcTrackData::getYVelocityECEF() const {
    return yVelocityECEF_;
}

void FinalCalcTrackData::setYVelocityECEF(const double& value) {
    validateYVelocityECEF(value);
    yVelocityECEF_ = value;
}

double FinalCalcTrackData::getZVelocityECEF() const {
    return zVelocityECEF_;
}

void FinalCalcTrackData::setZVelocityECEF(const double& value) {
    validateZVelocityECEF(value);
    zVelocityECEF_ = value;
}

double FinalCalcTrackData::getXPositionECEF() const {
    return xPositionECEF_;
}

void FinalCalcTrackData::setXPositionECEF(const double& value) {
    validateXPositionECEF(value);
    xPositionECEF_ = value;
}

double FinalCalcTrackData::getYPositionECEF() const {
    return yPositionECEF_;
}

void FinalCalcTrackData::setYPositionECEF(const double& value) {
    validateYPositionECEF(value);
    yPositionECEF_ = value;
}

double FinalCalcTrackData::getZPositionECEF() const {
    return zPositionECEF_;
}

void FinalCalcTrackData::setZPositionECEF(const double& value) {
    validateZPositionECEF(value);
    zPositionECEF_ = value;
}

int64_t FinalCalcTrackData::getOriginalUpdateTime() const {
    return originalUpdateTime_;
}

void FinalCalcTrackData::setOriginalUpdateTime(const int64_t& value) {
    validateOriginalUpdateTime(value);
    originalUpdateTime_ = value;
}

int64_t FinalCalcTrackData::getUpdateTime() const {
    return updateTime_;
}

void FinalCalcTrackData::setUpdateTime(const int64_t& value) {
    validateUpdateTime(value);
    updateTime_ = value;
}

int64_t FinalCalcTrackData::getFirstHopSentTime() const {
    return firstHopSentTime_;
}

void FinalCalcTrackData::setFirstHopSentTime(const int64_t& value) {
    validateFirstHopSentTime(value);
    firstHopSentTime_ = value;
}

int64_t FinalCalcTrackData::getFirstHopDelayTime() const {
    return firstHopDelayTime_;
}

void FinalCalcTrackData::setFirstHopDelayTime(const int64_t& value) {
    validateFirstHopDelayTime(value);
    firstHopDelayTime_ = value;
}

int64_t FinalCalcTrackData::getSecondHopSentTime() const {
    return secondHopSentTime_;
}

void FinalCalcTrackData::setSecondHopSentTime(const int64_t& value) {
    validateSecondHopSentTime(value);
    secondHopSentTime_ = value;
}

int64_t FinalCalcTrackData::getSecondHopDelayTime() const {
    return secondHopDelayTime_;
}

void FinalCalcTrackData::setSecondHopDelayTime(const int64_t& value) {
    validateSecondHopDelayTime(value);
    secondHopDelayTime_ = value;
}

int64_t FinalCalcTrackData::getTotalDelayTime() const {
    return totalDelayTime_;
}

void FinalCalcTrackData::setTotalDelayTime(const int64_t& value) {
    validateTotalDelayTime(value);
    totalDelayTime_ = value;
}

int64_t FinalCalcTrackData::getThirdHopSentTime() const {
    return thirdHopSentTime_;
}

void FinalCalcTrackData::setThirdHopSentTime(const int64_t& value) {
    validateThirdHopSentTime(value);
    thirdHopSentTime_ = value;
}

bool FinalCalcTrackData::isValid() const {
    try {
        validateTrackId(trackId_);
        validateXVelocityECEF(xVelocityECEF_);
        validateYVelocityECEF(yVelocityECEF_);
        validateZVelocityECEF(zVelocityECEF_);
        validateXPositionECEF(xPositionECEF_);
        validateYPositionECEF(yPositionECEF_);
        validateZPositionECEF(zPositionECEF_);
        validateOriginalUpdateTime(originalUpdateTime_);
        validateUpdateTime(updateTime_);
        validateFirstHopSentTime(firstHopSentTime_);
        validateFirstHopDelayTime(firstHopDelayTime_);
        validateSecondHopSentTime(secondHopSentTime_);
        validateSecondHopDelayTime(secondHopDelayTime_);
        validateTotalDelayTime(totalDelayTime_);
        validateThirdHopSentTime(thirdHopSentTime_);
        return true;
    } catch (const std::exception&) {
        return false;
    }
}

// Binary Serialization Implementation
std::vector<uint8_t> FinalCalcTrackData::serialize() const {
    std::vector<uint8_t> buffer;
    buffer.reserve(getSerializedSize());
    
    // Serialize trackId_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&trackId_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(trackId_));
    }
    
    // Serialize xVelocityECEF_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&xVelocityECEF_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(xVelocityECEF_));
    }
    
    // Serialize yVelocityECEF_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&yVelocityECEF_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(yVelocityECEF_));
    }
    
    // Serialize zVelocityECEF_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&zVelocityECEF_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(zVelocityECEF_));
    }
    
    // Serialize xPositionECEF_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&xPositionECEF_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(xPositionECEF_));
    }
    
    // Serialize yPositionECEF_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&yPositionECEF_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(yPositionECEF_));
    }
    
    // Serialize zPositionECEF_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&zPositionECEF_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(zPositionECEF_));
    }
    
    // Serialize originalUpdateTime_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&originalUpdateTime_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(originalUpdateTime_));
    }
    
    // Serialize updateTime_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&updateTime_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(updateTime_));
    }
    
    // Serialize firstHopSentTime_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&firstHopSentTime_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(firstHopSentTime_));
    }
    
    // Serialize firstHopDelayTime_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&firstHopDelayTime_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(firstHopDelayTime_));
    }
    
    // Serialize secondHopSentTime_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&secondHopSentTime_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(secondHopSentTime_));
    }
    
    // Serialize secondHopDelayTime_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&secondHopDelayTime_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(secondHopDelayTime_));
    }
    
    // Serialize totalDelayTime_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&totalDelayTime_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(totalDelayTime_));
    }
    
    // Serialize thirdHopSentTime_
    {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&thirdHopSentTime_);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(thirdHopSentTime_));
    }
    
    return buffer;
}

bool FinalCalcTrackData::deserialize(const std::vector<uint8_t>& data) {
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
    
    // Deserialize xVelocityECEF_
    if (offset + sizeof(xVelocityECEF_) <= data.size()) {
        std::memcpy(&xVelocityECEF_, &data[offset], sizeof(xVelocityECEF_));
        offset += sizeof(xVelocityECEF_);
    } else {
        return false;
    }
    
    // Deserialize yVelocityECEF_
    if (offset + sizeof(yVelocityECEF_) <= data.size()) {
        std::memcpy(&yVelocityECEF_, &data[offset], sizeof(yVelocityECEF_));
        offset += sizeof(yVelocityECEF_);
    } else {
        return false;
    }
    
    // Deserialize zVelocityECEF_
    if (offset + sizeof(zVelocityECEF_) <= data.size()) {
        std::memcpy(&zVelocityECEF_, &data[offset], sizeof(zVelocityECEF_));
        offset += sizeof(zVelocityECEF_);
    } else {
        return false;
    }
    
    // Deserialize xPositionECEF_
    if (offset + sizeof(xPositionECEF_) <= data.size()) {
        std::memcpy(&xPositionECEF_, &data[offset], sizeof(xPositionECEF_));
        offset += sizeof(xPositionECEF_);
    } else {
        return false;
    }
    
    // Deserialize yPositionECEF_
    if (offset + sizeof(yPositionECEF_) <= data.size()) {
        std::memcpy(&yPositionECEF_, &data[offset], sizeof(yPositionECEF_));
        offset += sizeof(yPositionECEF_);
    } else {
        return false;
    }
    
    // Deserialize zPositionECEF_
    if (offset + sizeof(zPositionECEF_) <= data.size()) {
        std::memcpy(&zPositionECEF_, &data[offset], sizeof(zPositionECEF_));
        offset += sizeof(zPositionECEF_);
    } else {
        return false;
    }
    
    // Deserialize originalUpdateTime_
    if (offset + sizeof(originalUpdateTime_) <= data.size()) {
        std::memcpy(&originalUpdateTime_, &data[offset], sizeof(originalUpdateTime_));
        offset += sizeof(originalUpdateTime_);
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
    
    // Deserialize firstHopSentTime_
    if (offset + sizeof(firstHopSentTime_) <= data.size()) {
        std::memcpy(&firstHopSentTime_, &data[offset], sizeof(firstHopSentTime_));
        offset += sizeof(firstHopSentTime_);
    } else {
        return false;
    }
    
    // Deserialize firstHopDelayTime_
    if (offset + sizeof(firstHopDelayTime_) <= data.size()) {
        std::memcpy(&firstHopDelayTime_, &data[offset], sizeof(firstHopDelayTime_));
        offset += sizeof(firstHopDelayTime_);
    } else {
        return false;
    }
    
    // Deserialize secondHopSentTime_
    if (offset + sizeof(secondHopSentTime_) <= data.size()) {
        std::memcpy(&secondHopSentTime_, &data[offset], sizeof(secondHopSentTime_));
        offset += sizeof(secondHopSentTime_);
    } else {
        return false;
    }
    
    // Deserialize secondHopDelayTime_
    if (offset + sizeof(secondHopDelayTime_) <= data.size()) {
        std::memcpy(&secondHopDelayTime_, &data[offset], sizeof(secondHopDelayTime_));
        offset += sizeof(secondHopDelayTime_);
    } else {
        return false;
    }
    
    // Deserialize totalDelayTime_
    if (offset + sizeof(totalDelayTime_) <= data.size()) {
        std::memcpy(&totalDelayTime_, &data[offset], sizeof(totalDelayTime_));
        offset += sizeof(totalDelayTime_);
    } else {
        return false;
    }
    
    // Deserialize thirdHopSentTime_
    if (offset + sizeof(thirdHopSentTime_) <= data.size()) {
        std::memcpy(&thirdHopSentTime_, &data[offset], sizeof(thirdHopSentTime_));
        offset += sizeof(thirdHopSentTime_);
    } else {
        return false;
    }
    
    return true;
}

size_t FinalCalcTrackData::getSerializedSize() const {
    size_t size = 0;
    
    size += sizeof(trackId_);  // uint32_t
    size += sizeof(xVelocityECEF_);  // float
    size += sizeof(yVelocityECEF_);  // float
    size += sizeof(zVelocityECEF_);  // float
    size += sizeof(xPositionECEF_);  // float
    size += sizeof(yPositionECEF_);  // float
    size += sizeof(zPositionECEF_);  // float
    size += sizeof(originalUpdateTime_);  // uint32_t
    size += sizeof(updateTime_);  // uint32_t
    size += sizeof(firstHopSentTime_);  // uint32_t
    size += sizeof(firstHopDelayTime_);  // uint32_t
    size += sizeof(secondHopSentTime_);  // uint32_t
    size += sizeof(secondHopDelayTime_);  // uint32_t
    size += sizeof(totalDelayTime_);  // uint32_t
    size += sizeof(thirdHopSentTime_);  // uint32_t
    
    return size;
}
