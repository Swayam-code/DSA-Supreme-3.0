#include<iostream>
using namespace std;

bool binarySearch(int arr[], int n, int target){
    int s =0, e = n-1;
    int mid  = (s+e)/2;
    while(s<=e){
        if(arr[mid]== target){
            return true;
        }
        if(target < arr[mid]){
            e = mid-1;
        }
        else if(target > arr[mid]){
            s = mid+1;
        }
        mid = (s+e)/2;
    }
    return false;
    
}

int main(){
    //Binary-search algorithm
    int arr[]={2,8,10,20,30,34,46,78};
    int n  = sizeof(arr)/sizeof(arr[0]);
    int target = 46;

    int ans = binarySearch(arr,n,target);
    cout<<"find target:"<<ans<<endl;

    return 0;
}