#ifndef ANALYZER_H
#define ANALYZER_H

#include "../include/tracker.hpp"
#include <unordered_map>
#include <queue>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

// Hash function for pair<string,string>
struct map_hash {
    size_t operator()(const pair<string,string>& p) const {
        size_t h1 = hash<string>()(p.first);
        size_t h2 = hash<string>()(p.second);
        return h1 ^ (h2 << 1);
    }
};

// extern declaration
extern unordered_map<pair<string,string>, int, map_hash> p_map;

// Comparator for priority_queue
struct Compare {
    bool operator()(const tuple<string,string,string>& p1, const tuple<string,string,string>& p2) {
        return p_map[{get<2>(p1), get<1>(p1)}] < p_map[{get<2>(p2), get<1>(p2)}];
    }
};

class analyzerModule {
public:
    priority_queue<tuple<string,string,string>, vector<tuple<string,string,string>>, Compare> max_typeHeap;
    void diffCount();
};

#endif