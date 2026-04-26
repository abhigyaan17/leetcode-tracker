#include<iostream>
#include "../include/tracker.hpp"
#include "../include/analyzer.hpp"
using namespace std;

// void analyzerModule::typeCount() {
//     for(auto& it:main_problemMap){
//         prblmType_map[it.first]=it.second.type;
//     }
//     for(auto& it:prblmType_map){
//         cout<<it.first<<" : "<<it.second<<endl;
//     }    
// }

// void analyzerModule::statusCount() {
//     for(auto& it:main_problemMap){
//         prblmStatus_map[it.second.status]++;
//     }
//     for(auto& it:prblmStatus_map){
//         cout<<it.first<<" : "<<it.second<<endl;
//     }    
// }

unordered_map<pair<string,string>,int,map_hash> p_map{
    {{"easy","unsolved"},6},
    {{"medium","unsolved"},5},
    {{"hard","unsolved"},4},
    {{"easy","solved"},3},
    {{"medium","solved"},2},
    {{"hard","solved"},1}
};

void analyzerModule::diffCount() {
    for(auto& it:main_problemMap){
        max_typeHeap.push({it.first,it.second.status,it.second.difficulty});
    }  
    while(!max_typeHeap.empty()){
        cout<<get<0>(max_typeHeap.top())<<" "<<get<1>(max_typeHeap.top())<<" "<<get<2>(max_typeHeap.top())<<endl;
        max_typeHeap.pop();
    }
}