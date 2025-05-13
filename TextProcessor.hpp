#include "Processor.hpp"

class TextProcessor : public Processor {
    bool caseSensitive_ = false;
public:
    TextProcessor();
    void process(const std::string& data) override;
    void configure(const Configuration& config) override;
    
    // Optional: override batch processing if needed
    // void processBatch(const std::vector<std::string>& data) override;
};