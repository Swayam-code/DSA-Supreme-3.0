#include<iostream>
#include <string.h>
using namespace std;

int getLength(char arr[], int size) {
    int count = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] == '\0') {
            break;
        }
        count++;
    }
    return count;

    //using-while loop
    // int i = 0;
    // while(arr[i] != '\0') {
    //     count++;
    //     i++;
    // }
    // return count;
}

void replaceCharacter(char arr[], char oldChar, char newChar) {
    for(int i = 0; arr[i] != '\0'; i++) {
        if(arr[i] == oldChar) {
            arr[i] = newChar;
        }
    }
}

void convertIntoUpperCase(char arr[], int size) {
    for(int i = 0; i < size; i++) {
        if(arr[i] >= 'a' && arr[i] <= 'z') {
            //if only the character is in lower case
            //then convert it into upper case
            arr[i] = arr[i] - 'a' + 'A';
        }
    }
}

void convertIntoLowerCase(char arr[], int size) {
    for(int i = 0; i < size; i++) {
        if(arr[i] >= 'A' && arr[i] <= 'Z') {
            //if only the character is in upper case
            //then convert it into lower case
            arr[i] = arr[i] - 'A' + 'a';
        }
    }
}

void reverseCharArray(char arr[], int size) {
    int len = getLength(arr, size);
    int start = 0;
    int end = len - 1;
    while(start < end) {
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

bool isPalindrome(char arr[], int size) {
    int len = getLength(arr, size);
    int start = 0;
    int end = len - 1;
    while(start < end) {
        if(arr[start] != arr[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main(){

    char arr[100];
    cout <<"Enter the input "<< endl;
    cin >> arr;

    char arr2[100];
    cout << "Enter the input for arr2" << endl;
    cin >> arr2;

    cout << strcat(arr, arr2) << endl; //concatenation

    // char arr[1000];
    // cout << "enter your name : ";
    // cin >> arr;
    // isPalindrome(arr, 1000) ? cout << "yes" : cout << "no";
    // reverseCharArray(arr, 1000);
    // convertIntoLowerCase(arr, 1000);
    
    // convertIntoUpperCase(arr, 1000);
    // replaceCharacter(arr, '@', ' ');
    // cout << arr << endl;
    // cout << getLength(arr, 1000) << endl;

    // //creation
    // char arr[100];
    // cout << "enter your name : ";
    // // cin>> arr;
    // //multiples line input
    // cin.getline(arr, 80, '\t'); // '\t' is the delimiter: Tab key
    // cout << "your name is "<< arr<<endl;
    //printing ASCII values
    // cout << arr[0] << "->" << (int)arr[0] << endl;
    // cout << arr[1] << "->" << (int)arr[1] << endl;
    // cout << arr[2] << "->" << (int)arr[2] << endl;
    // cout << arr[3] << "->" << (int)arr[3] << endl;
    // cout << arr[4] << "->" << (int)arr[4] << endl;
    // cout << arr[5] << "->" << (int)arr[5] << endl;
    // cout << arr[6] << "->" << (int)arr[6] << endl;

     
    return 0;
}