#include<iostream>
#include<unordered_map>
#include<fstream>
#include<algorithm>
#include "../include/nlohmann/json.hpp"
using namespace std;

struct problemData{
    string id,name,type,difficulty,status;
};

class trackerModule{
public:
    nlohmann::json json_data;
    unordered_map<string,problemData> main_problemMap;
    
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
            problemData data_obj;
            data_obj.id=problem.at("id");  
            data_obj.name=problem.at("name");  
            data_obj.type=problem.at("type");  
            data_obj.difficulty=problem.at("difficulty");
            data_obj.status=problem.at("status");
            main_problemMap[data_obj.id]=data_obj;
        }
    }
};

int main(){
    trackerModule obj;
    obj.jsonReader();
    obj.problemMapper();
}