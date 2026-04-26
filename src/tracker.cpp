#include<fstream>
#include<iostream>
#include<unordered_map>
#include "../include/tracker.hpp"
using namespace std;

unordered_map<string,problemData> main_problemMap;

void trackerModule::jsonReader(){
    fstream jsonFile("data/problems.json");
    if(!jsonFile.is_open()){
        cerr<<"Error occured during file opening"<<endl;
    }
    jsonFile>>json_data;
    if(!json_data.is_array()){
        cerr<<"Error:Expected a array of objects from JSON file"<<endl;
    }
}
    
void trackerModule::problemMapper(){
    for(const auto& problem:json_data){
        problemData data_obj;
        data_obj.id=problem.at("id");  
        data_obj.name=problem.at("name");  
        data_obj.type=problem.at("type");  
        data_obj.difficulty=problem.at("difficulty");
        data_obj.status=problem.at("status");
        main_problemMap[data_obj.id]=data_obj;
    }
    // for(auto it:main_problemMap){
    //     cout<<it.first<<" : "
    //     <<it.second.name<<" : "
    //     <<it.second.type<<" : "
    //     <<it.second.difficulty<<" : "
    //     <<it.second.status<<endl;
    // }
}