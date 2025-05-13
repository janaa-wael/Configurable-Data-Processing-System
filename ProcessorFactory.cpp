#include <iostream>
#include "Processor.hpp"
#include "TextProcessor.hpp"
#include "ProcessorFactory.hpp"

std::unique_ptr<Processor> ProcessorFactory::createProcessor(const std::string& type) {
    if (type == ProcessorTypes::TEXT) {
        return std::make_unique<TextProcessor>();
    } 
    // Add other processor types here
    else 
    {
        throw std::invalid_argument("Unknown processor type: " + type);
    }
}