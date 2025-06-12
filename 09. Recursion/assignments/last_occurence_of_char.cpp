#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

//right to left
void lastOccurenceRTL(string str, char ch, int &ans, int i){
    //base case
    if(i < 0){
        return;
    }

    //1 case khud kar do
    if(str[i] == ch){
        ans = i;
        return; //found the last occurrence, no need to check further
    }

    //recursion ka ans
    lastOccurenceRTL(str, ch, ans, i-1);
}

//left to right
void lastOccurenceLTR(string str, char ch, int &ans, int i){
    //base case
    if(i == str.length()){
        return;
    }

    //1 case khud kar do
    if(str[i] == ch){
        ans = i;
    }

    //recursion ka ans
    lastOccurenceLTR(str, ch, ans, i+1);
}

int main(){
    string s;
    cout << "Enter the string: ";
    cin >> s;

    char ch;
    cout << "Enter the character to find last occurrence: ";
    cin >> ch;

    //using stl
    int ans = s.find_last_of(ch);

    // int ans = -1;
    // lastOccurenceLTR(s,ch, ans ,0);
    // lastOccurenceRTL(s,ch, ans ,s.length()-1);
    cout << "Last occurrence of " << ch << " is at index: " << ans << endl;
    return 0;
}