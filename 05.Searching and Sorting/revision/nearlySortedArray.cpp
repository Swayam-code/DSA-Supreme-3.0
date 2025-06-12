//GFG- Search in almost sorted array

//You are given a nearly sorted array[] of size N, some elements of array are moved to adjacent positions.,i.e., arr[i] may be at position i-1, i, or i+1. ,i.e., arr[i] can only be swapped with either arr[i+1] or arr[i-1]. The task is to search for an element in this array.

//Input : arr[] = {10,3,40,20,50,80,70} , key = 40
//Output : 2
//Explanation : 40 is present at index 2

//Input : arr[] = {10,3,40,20,50,80,70} , key = 90  
//Output : -1
//Explanation : 90 is not present in the array

#include <iostream>
using namespace std;

int applyBinarySearch(int arr[], int n, int key){
    int s = 0;
    int e = n-1;
    int mid = s + ((e-s)>>1);
    
    while(s<=e){
        if(arr[mid] == key){
            return mid;
        }
        if(mid-1 >= s && arr[mid-1] == key){
            return mid-1;
        }
        if(mid+1 <= e && arr[mid+1] == key){
            return mid+1;
        }
        
        if(key < arr[mid]){
            e = mid - 2; //because mid-1 is already checked
        }
        else{
            s = mid + 2; //because mid+1 is already checked
        }
        //bhul jaata hun
        mid = s + ((e-s)/1);
    }
    return -1;
}

int main(){
    int arr[] = {10,3,40,20,50,80,70};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 10;
    
    int  ans = applyBinarySearch(arr, n, key);
    cout << "find target: " << ans << endl;

    return 0;
}