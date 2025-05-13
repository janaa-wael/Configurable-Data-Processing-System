#pragma once
#include <string>
#include <memory>
#include <vector>
#include <stdexcept>

/**
 * @brief Abstract base class for all data processors
 * 
 * Defines the common interface that all concrete processors must implement
 */
class Processor {
public:
    virtual ~Processor() = default;
    virtual void process(const std::string& data) = 0;
    virtual void configure(const class Configuration& config) = 0;
    virtual void processBatch(const std::vector<std::string>& data);
};


template <typename T>
void processTypedCollection(Processor& processor, const std::vector<T>& data) {
    for (const auto& item : data) {
        processor.process(std::to_string(item));
    }
}


namespace ProcessorTypes {
    constexpr auto TEXT = "Text";
    constexpr auto NUMERIC = "Numeric";
    constexpr auto IMAGE = "Image";
    constexpr auto AUDIO = "Audio";
}