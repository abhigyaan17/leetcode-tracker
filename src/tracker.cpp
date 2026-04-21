#include<iostream>
#include<unordered_map>
#include<fstream>
#include<algorithm>
#include "../include/nlohmann/json.hpp"
using namespace std;

class trackerModule{
public:
    unordered_map<string,int> trackerMap;
    unordered_map<string,int> arrayMap;
    unordered_map<string,int> stringMap;
    unordered_map<string,int> stackMap;
    unordered_map<string,int> queueMap;
    unordered_map<string,int> recursionMap;

    nlohmann::json json_data;
    void jsonReader(){
        fstream jsonFile("../data/problems.json");
        if(!jsonFile.is_open()){
            cerr<<"Error occured during file opening"<<endl;
        }
        jsonFile>>json_data;
        if(!json_data.is_array()){
            cerr<<"Error:Expected a array of objects from JSON file"<<endl;
        }
    }
    void problemMapper(){
        for(const auto& problem:json_data){
            if(problem["type"]=="array"){
                arrayMap[problem["name"]]++;
                trackerMap["array"]++;
            }
            else if(problem["type"]=="string"){
                stringMap[problem["name"]]++;
                trackerMap["string"]++;
            }
            else if(problem["type"]=="stack"){
                stackMap[problem["name"]]++;
                trackerMap["string"]++;
            }
            else if(problem["type"]=="queue"){
                queueMap[problem["name"]]++;
                trackerMap["string"]++;
            }
            else if(problem["type"]=="recursion"){
                recursionMap[problem["name"]]++;
                trackerMap["recursion"]++;
            }
        }
    }
};

int main(){
    trackerModule obj;
    obj.jsonReader();
    obj.problemMapper();
}