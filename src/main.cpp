#include<iostream>
#include<fstream>
#include "../include/tracker.hpp"
#include "../include/analyzer.hpp"
using namespace std;


int main(){
    trackerModule tracker_obj;
    analyzerModule analyzer_obj;
    tracker_obj.jsonReader();
    tracker_obj.problemMapper();
    analyzer_obj.diffCount();
    // analyzer_obj.statusCount();
    return 0;
}