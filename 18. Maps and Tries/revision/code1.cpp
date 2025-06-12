#include<iostream>
#include <unordered_map>
#include<map>
using namespace std;


int main(){
    //creation of map
    unordered_map<int, string> uMap;
    map<int, string> oMap;

    //insertion
    uMap[2] = "Scorpio";
    uMap[1] = "Fortuner";
    uMap[3] = "Baleno";

    oMap[2] = "Scorpio";
    oMap[1] = "Fortuner";
    oMap[3] = "Baleno";

    //printing unordered_map
    cout << "Unordered Map:" << endl;
    for(auto i: uMap){
        cout << i.first << " : " << i.second << endl;
    }

    //printing ordered_map
    cout << "Ordered Map:" << endl;
    for(auto i: oMap){
        cout << i.first << " : " << i.second << endl;
    }
    cout << endl;

    //search or find
    //count() and find() are used to search for a key in the map

    cout << uMap.count(2) << endl; // returns 1 if key is found, else returns 0

    if(uMap.count(3) > 0){
        cout << "Key 3 found with value: " << uMap[3] << endl;
    } else {
        cout << "Key 3 not found" << endl;
    }

    // if(uMap.find(1) == uMap.end()){
    //     cout << "Key 1 not found in unordered_map" << endl;
    // } else {
    //     cout << "Key 1 found in unordered_map with value: " << uMap[1] << endl;
    // }

    return 0;
}