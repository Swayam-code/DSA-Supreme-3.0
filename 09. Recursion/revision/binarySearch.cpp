//Binary Search
#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int n, int s, int e, int target){
    //base-case
    if(s>e){
        return -1;
    }
    //processing
    //1-case mai solve karunga, baaki recursion karlega
    int mid = s + (e-s)/2;
    if(arr[mid] == target){
        return mid;
    }
    //recursion-case
    else if(arr[mid] > target){
        //left
        e = mid - 1;
        return binarySearchRecursive(arr, n, s, e, target);
    }
    else{
        // right
        s = mid + 1;
        return binarySearchRecursive(arr, n, s, e, target);
    }
}

int binarySearch(int arr[], int size, int key){
    //Using iterative approach
    int s =0;
    int e = size-1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            //right
            e = mid - 1;
        }
        else{
            // left
            s = mid + 1;
        }
        //bhul jata hun
        mid = s + (e-s)/2;
    }
}

int main (){

    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(int);
    int target = 5;
    int s = 0;
    int e = size - 1;
    
    int ans = binarySearchRecursive(arr, size, s, e, target);
    cout << "Element found at index : " << ans << endl;
    
    return 0;
}