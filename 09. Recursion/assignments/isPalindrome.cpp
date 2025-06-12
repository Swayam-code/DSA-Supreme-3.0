#include<iostream>
using namespace std;

int isPalindrome(string str, int s, int e){
    //base case
    if(s >= e){
        return 1;
    }

    //1 case khud kar do
    if(str[s] != str[e]){
        return 0;
    }

    //recursion ka ans
    return isPalindrome(str, s+1, e-1);
}

int main(){
    string s;
    
    cout << "Enter the string to check if it is a palindrome: ";
    cin >> s;

    int sIndex = 0;
    int eIndex = s.length() - 1;
    int ans = isPalindrome(s, sIndex, eIndex);
    if(ans == 1){
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}