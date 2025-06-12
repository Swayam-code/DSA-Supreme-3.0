#include<iostream>
#include<string>
using namespace std;

void reverseString(string &str, int s, int e){
    //base case
    if(s >= e){
        return;
    }

    //1 case khud kar do
    swap(str[s], str[e]);

    //recursion ka ans
    reverseString(str, s+1, e-1);
}

int main(){
    string str;
    cout << "Enter the string to reverse: ";
    cin>>str;

    int s = 0;
    int e = str.length()-1;
    reverseString(str, s, e);
    cout << "Reversed string: " << str << endl;


    return 0;
}