#include <iostream>
#include<vector>
#include <limits.h>
using namespace std;

bool searchInArray(int arr[], int size, int index, int target){
    //base case
    if(index== size) return false;
    if(arr[index]== target) return true;
    //searchInArray--> recursion ka Ans
    bool ans = searchInArray(arr, size, index+1, target);
    return ans;
    //processing
}

void printArray(int arr[], int size, int index){
    //base case
    if(index==size) return ;
    //recursion ka Ans
    cout << arr[index]<<" ";
    //processing
    printArray(arr,size,index+1);
}

void maxInArray(int arr[], int size, int index, int &maxi){
    //base case
    if(index== size) return;
    //recursion ka Ans
    maxi= max(maxi, arr[index]);
    //processing
    maxInArray(arr, size, index+1, maxi);
}

void minInArray(int arr[], int size, int index, int &mini){
    //base case
    if(index == size) return;
    //recursion ka Ans
    mini = min( mini, arr[index]);
    //processing
    minInArray(arr, size, index+1, mini);
}

void printAllOdds(int arr[], int n, int index){
    //base case
    if(index== n) return ;
    //recursion ka Ans
    if((arr[index])&1) 
    cout << arr[index] << " ";
    //processing
    printAllOdds(arr,n,index+1);
}

void printAllEvens(int arr[], int n, int index){
    //base case
    if( index == n) return;
    //processing
    if (!(arr[index] & 1)) 
    cout << arr[index]<< endl;

    //recursion ka Ans
    printAllEvens(arr, n, index+1);

}

void printDigits(int n){
    //base case
    if(n==0) return ;
    //recursive ka Ans
    int newNumber = n/10;
    printDigits( newNumber);
    int digit = n% 10;
    cout << digit << " ";

}

int main(){
    
    int arr[]= {10, 11, 12, 13, 14, 15};
    int n = 6;
    int index = 0;

    int target = 22;
    cout<< searchInArray(arr, n, index, target) << endl;

    // printArray(arr, n, index);
    // cout<< endl;

    // int maxi= INT_MIN;
    // maxInArray(arr, n, index, maxi);
    // cout<< "Max No."<< maxi << endl;

    // int mini= INT_MAX;
    // minInArray(arr, n, index, mini);
    // cout<< "Min No."<< mini << endl;


    // printAllOdds(arr, n, index);
    // cout << endl;

    // printAllEvens(arr, n, index);
    // cout<< endl;

    // int n = 903245;
    // printDigits(n);

    return 0;
}