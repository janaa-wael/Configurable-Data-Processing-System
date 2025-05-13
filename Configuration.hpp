#include <iostream>
#include <string>
#include <map>

using namespace std;

class Configuration {
    std::map<string, string> settings;
public:
    void loadFromFile(const string& filename);
    string get(const string& key) const;
    string trim(const std::string& str) const;
};