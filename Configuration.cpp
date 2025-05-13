#include "Configuration.hpp"    
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

void Configuration::loadFromFile(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open()) 
    {
        throw std::runtime_error("Could not open file: " + filename);
    }
    string line;
    while(getline(file, line))
    {
        line = trim(line);
        if(line.empty() || line[0] == '#') 
        {
            continue; // Skip empty lines and comments
        }

        size_t separator_pos = line.find('=');
        if(separator_pos == string::npos) 
        {
            continue; // Skip lines without '='
        }
        // Extract key and value
        string key = trim(line.substr(0, separator_pos));
        string value = trim(line.substr(separator_pos + 1));

        if(!key.empty() && !value.empty()) 
        {
            settings[key] = value;
        }
    }
}

string Configuration::get(const string& key) const
{
    auto it = settings.find(key);
    if(it != settings.end()) 
    {
        return it->second;
    }
    return ""; // Return empty string if key not found
}

void Configuration::set(const string& key, const string& value)
{
    settings[key] = value;
}


string Configuration::trim(const string& str) const
{
    size_t first = 0, last = str.size();
    
    while (first < last && isspace(str[first])) first++;
    while (last > first && isspace(str[last-1])) last--;
    
    return str.substr(first, last - first);
}