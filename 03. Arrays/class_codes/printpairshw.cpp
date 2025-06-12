#include<iostream>
using namespace std;

void printAllPairs(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i]<<","<<arr[j]<<endl;
        }
    }
}

void printlowerTraingle(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<arr[i]<<","<<arr[j]<<endl;
        }
    }
}

void printUpperTraingle(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<arr[i]<<","<<arr[j]<<endl;
        }
    }
}

void printUpperTriangle22(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            cout<<arr[i]<<","<<arr[j]<<endl;
        }
    }
}

void printLowerTriangle22(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<arr[i]<<","<<arr[j]<<endl;
        }
    }
}

int main(){

    int arr[]={10,20,30,40};
    int size=4;
     
    printLowerTriangle22(arr,size);
    // printUpperTriangle22(arr,size); 
    // printUpperTraingle(arr,size);
    // printlowerTraingle(arr,size);
    // printAllPairs(arr,size);

    return 0;
}