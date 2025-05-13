#include <iostream>
#include <string>
#include <vector>
#include "Configuration.hpp"
#include "Processor.hpp"
#include "TextProcessor.hpp"

int main()
{
    // Load configuration
    Configuration config;
    try {
        config.loadFromFile("config.txt");
    } catch (const std::exception& e) {
        std::cerr << "Error loading configuration: " << e.what() << std::endl;
        return 1;
    }

    // Create a TextProcessor instance
    TextProcessor textProcessor;

    // Configure the processor
    try {
        textProcessor.configure(config);
    } catch (const std::exception& e) {
        std::cerr << "Error configuring processor: " << e.what() << std::endl;
        return 1;
    }

    // Process some data
    std::vector<std::string> data = {"Hello World", "C++ Programming"};
    textProcessor.processBatch(data);

    return 0;
}