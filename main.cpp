#include "Configuration.hpp"
#include "ProcessorFactory.hpp"
#include <iostream>
#include <vector>

// Test helper function
void testProcessorCreation(const std::string& type) {
    try {
        std::cout << "=== Testing " << type << " Processor ===" << std::endl;
        
        // 1. Create configuration (simulated)
        Configuration config;
        // Normally you'd load from file, but we'll simulate for testing
        std::cout << "Setting Processor.Type = " << type << std::endl;
        
        // 2. Create processor using ONLY the factory's create method
        std::unique_ptr<Processor> processor = ProcessorFactory::createProcessor(type);
        
        // 3. Test processing
        std::cout << "Created processor successfully!" << std::endl;
        processor->process("SampleData123");
        
        // 4. Test batch processing
        std::vector<std::string> batch = {"First", "Second", "Third"};
        std::cout << "\nBatch processing:" << std::endl;
        processor->processBatch(batch);
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "------------------------\n";
}

int main() {
    // Test all supported processor types
    testProcessorCreation("Text");
    testProcessorCreation("Numeric");
    
    // Test error case
    testProcessorCreation("InvalidType");
    
    return 0;
}