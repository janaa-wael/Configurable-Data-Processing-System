#include "TextProcessor.hpp"
#include "Configuration.hpp"
#include <iostream>

int main() {
    TextProcessor textProcessor;
    Configuration config;

    // Test 1: Case-Insensitive (default or configured to false)
    std::cout << "--- Test 1: Case-Insensitive Processing ---\n";
    config.set("Text.CaseSensitive", "false");
    textProcessor.configure(config);
    textProcessor.process("Hello World and C++ Programming");  
    // Expected Output: "Processing text: hello world and c++ programming"

    // Test 2: Case-Sensitive (configured to true)
    std::cout << "\n--- Test 2: Case-Sensitive Processing ---\n";
    config.set("Text.CaseSensitive", "true");
    textProcessor.configure(config);
    textProcessor.process("Hello World and C++ Programming");  
    // Expected Output: "Processing text: Hello World and C++ Programming"

    // Test 3: Invalid Configuration (should throw exception)
    std::cout << "\n--- Test 3: Invalid Configuration ---\n";
    try {
        config.set("Text.CaseSensitive", "yes");  // Invalid value
        textProcessor.configure(config);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";  
        // Expected Output: "Error: Invalid value for case_sensitive: yes"
    }

    return 0;
}