#include<iostream>
using namespace std;

bool checkSorted(int arr[],int n, int index){
    //base case
    if(index== n-1) return true; //single element array treated as SORTED
    bool currAns= false;
    bool recursionAns = false;
    if(arr[index+1] > arr[index]){
        currAns = true;
    }
    //recursion ka Ans
    recursionAns= checkSorted(arr,n, index+1);
    //processing
    return (currAns && recursionAns);
}

void printSubSequences( string str, int i, string output){
    //base case
    if(i== str.length()){
        cout<< output << endl;
        return;
    }
    //recursion ka Ans
    char ch = str[i];
    //include ch
    printSubSequences(str,i+1,output+ch);
    //exclude ch
    printSubSequences(str,i+1,output);
}

int main(){
    
    int arr[]={10,20,30,40,50};
    int size= 5;
    int index= 0;
    bool ans= checkSorted(arr, size, index);

    cout<< "Array is sorted or not :"<< ans << endl;
    

    // string str= "abc";
    // string output= "";
    // int index= 0;
    // printSubSequences(str,index,output);

    return 0;
}

//leetcode 198 : House Robber

//leetcode 322 : Coin Change