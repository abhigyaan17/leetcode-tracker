#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,string,string,int> mp;
    mp["name","type","difficulty"]+=1;
    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}