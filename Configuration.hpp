#include <iostream>
#include <string>
#include <map>

using namespace std;

class Configuration {
    std::map<string, string> settings;
public:
    void loadFromFile(const string& filename);
    string get(const string& key) const;
    void set(const string& key, const string& value);
    string trim(const std::string& str) const;
    
};