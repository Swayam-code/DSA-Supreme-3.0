#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    
    unordered_map<int, int> desk_map; //roll no., desk no.

    //insertion
    desk_map[1] = 53; //desk_map key = 1, value = 53
    desk_map[2] = 54; //desk_map key = 2, value = 54
    desk_map[3] = 55; //desk_map key = 3, value = 55
    
    desk_map[2] = 57; //reassign 
    //iterate
    //I have to iterate over 3 entries
    //for loop
    unordered_map<int, int>::iterator it;
    for(it = desk_map.begin(); it != desk_map.end(); it++){
        int key = it->first; //key
        int value = it->second; //value
        cout << "Roll No: " << key << ", Desk No: " << value << endl;
    }

    //using for each loop
    // for(auto it : desk_map){
    //     int key = it.first; //key
    //     int value = it.second; //value
    //     cout << "Roll No: " << key << ", Desk No: " << value << endl;
    // }  
    
    //find? //table/map (Avg case complexity O(1))
    if(desk_map.find(2) != desk_map.end()){ //syntax
        //found
        int val = desk_map[2]; //value
        cout << val << endl;
    }
    else{
        //not found
        cout << "Roll No 2 is not present" << endl;
    }

    //deletion
    desk_map.erase(2); //delete key 2
    //after deletion
    cout << "After deletion" << endl;
    for(it = desk_map.begin(); it != desk_map.end(); it++){
        int key = it->first; //key
        int value = it->second; //value
        cout << "Roll No: " << key << ", Desk No: " << value << endl;
    }
    //find after deletion
    cout << "Find after deletion" << endl;
    if(desk_map.find(2) != desk_map.end()){ //syntax
        //found
        int val = desk_map[2]; //value
        cout << val << endl;
    }
    else{
        //not found
        cout << "Roll No 2 is not present" << endl;
    }

    return 0;
    
}