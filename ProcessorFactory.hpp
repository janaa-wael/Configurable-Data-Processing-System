#ifndef PROCESSORFACTORY_HPP
#define PROCESSORFACTORY_HPP

#include <iostream>
#include "Processor.hpp"    
#include "TextProcessor.hpp"
using namespace std;

class ProcessorFactory {
public:
    static std::unique_ptr<Processor> createProcessor(const std::string& type);
};

#endif // PROCESSORFACTORY_HPP