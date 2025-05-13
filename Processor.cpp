#include "Processor.hpp"
using namespace std;

void Processor::processBatch(const std::vector<std::string>& data) 
{
    for (const auto& item : data) 
    {
        process(item);
    }
}