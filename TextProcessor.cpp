#include "TextProcessor.hpp"
#include "Configuration.hpp"
#include <algorithm>
#include <cctype>
#include <stdexcept>

// Assuming TextProcessor inherits from Processor
TextProcessor::TextProcessor() : caseSensitive_(false) {}

void TextProcessor::process(const std::string& data) 
{
    std::string output = caseSensitive_ ? data : [&data]() 
    {
        std::string result;
        std::transform(data.begin(), data.end(), std::back_inserter(result),
                      [](unsigned char c){ return std::tolower(c); });
        return result;
    }();
    
    std::cout << "Processing text: " << output << "\n";
}

void TextProcessor::configure(const Configuration& config) 
{

    std::string caseSensitive = config.get("Text.CaseSensitive");
    
    std::transform(caseSensitive.begin(), caseSensitive.end(), 
                  caseSensitive.begin(), ::tolower);
    
    if (caseSensitive == "true" || caseSensitive == "1") {
        caseSensitive_ = true;
    } 
    else if (caseSensitive == "false" || caseSensitive == "0") {
        caseSensitive_ = false;
    } 
    else {
        throw std::invalid_argument("Invalid value for Text.CaseSensitive: " + caseSensitive);
    }
}