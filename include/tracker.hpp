#ifndef TRACKER_HPP
#define TRACKER_HPP
#include<unordered_map>
#include<string>
#include "../include/nlohmann/json.hpp"
using namespace std;

struct problemData{
    string id,name,type,difficulty,status;
};

extern unordered_map<string,problemData> main_problemMap;

class trackerModule{
public:
    nlohmann::json json_data;
    
    void jsonReader();
    void problemMapper();
};

#endif