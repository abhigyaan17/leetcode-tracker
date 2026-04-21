#include<iostream>
#include<fstream>
#include "../include/nlohmann/json.hpp"
using namespace std;


int main(){
    nlohmann::json json_data;
    fstream file("../data/problems.json");
    if(!file.is_open()){
        cerr<<"Error opening file"<<endl;
    }
    file>>json_data;
    if(!json_data.is_array()){
        cout<<"Expected a json array object"<<endl;
    }
    for(const auto& problem:json_data){
        string name=problem["name"];
        string type=problem["type"];
        string difficulty=problem["difficulty"];
        string status=problem["status"];

        cout<<"Name of problem : "<<name<<endl;
        cout<<"type of problem : "<<type<<endl;
        cout<<"difficulty of problem : "<<difficulty<<endl;
        cout<<"status : "<<status<<"\n"<<endl;
    }
    return 0;
}

