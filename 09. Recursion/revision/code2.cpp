#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//HW-1
void isSorted(int arr[], int size, int index, bool &ans){
    //base-case
    if(index==size-1){
        return;
    }
    //processing
    //1-case mai solve karunga
    if(arr[index] > arr[index+1]){
        ans = false;
    }
    
    //recursion-case
    //baaki recursion karlega
    isSorted(arr, size, index+1, ans);
}

void printDigits(int n){
    //base-case
    if(n==0){
        return;
    }
    //recursion-case
    int newNumber = n/10;
    printDigits(newNumber);
    
    //processing
    int digit = n%10;
    cout<<digit<<" ";
}

void printAllEvens(int arr[], int size, int index, vector<int> &ans){
    //base-case
    if(index==size){
        return;
    }
    //processing
    //1-case mai solve karunga
    if( !(arr[index]& 1)){
        // cout<<arr[index]<<" ";
        ans.push_back(arr[index]);
    }
    
    //recursion-case
    //baaki recursion karlega
    printAllEvens(arr, size, index+1, ans);
}

void printAllOdds(int arr[], int size, int index, vector<int> &ans){
    //base-case
    if(index==size){
        return;
    }
    //processing
    //1-case mai solve karunga
    if(arr[index]& 1){
        // cout << arr[index]<<" ";
        ans.push_back(arr[index]);
    }
    
    //recursion-case
    //baaki recursion karlega
    printAllOdds(arr, size, index+1, ans);
}

void mininArray(int arr[], int size, int index, int &ans){
    //base-case
    if(index==size){
        return;
    }
    //processing
    //1-case mai solve karunga
    ans = min(ans, arr[index]);
    
    //recursion-case
    //baaki recursion karlega
    mininArray(arr, size, index+1, ans);
}

void maxinArray(int arr[], int size, int index, int &ans){
    //base-case
    if(index==size){
        return;
    }
    //processing
    //1-case mai solve karunga
    if(arr[index]>ans){
        ans = arr[index];
    }
    
    //recursion-case
    //baaki recursion karlega
    maxinArray(arr, size, index+1, ans);
}

bool searchInArray(int arr[], int size, int index, int target){
    //base-case
    if(index==size){
        return false;
    }
    //processing
    //1-case mai solve karunga
    if(arr[index]==target){
        return true;
    }
    
    //recursion-case
    //baaki recursion karlega
    bool recursionkaAns = searchInArray(arr, size, index+1, target);
    return recursionkaAns;
}

void printArray(int arr[], int size, int index){
    //base-case
    if(index==size){
        return;
    }
    //processing
    //1-case mai solve karunga
    cout<<arr[index]<<" ";
    
    //recursion-case
    //baaki recursion karlega
    printArray(arr, size, index+1);
}

int main (){

    int arr[] = {10,20,30,60,40,50};
    int size = sizeof(arr)/sizeof(int);
    int index = 0;

    bool ans = true;
    isSorted(arr, size, index, ans);
    cout << "Array is sorted or not : " << ans << endl;

    // int n = 73652843;
    // cout << "Digits of " << n << " are: ";
    // printDigits(n);

    // int arr[] = {10,20,90,40,50,60};
    // int arr[] = {1,2,3,4,5,6,7,8,9};
    // int size = sizeof(arr)/sizeof(int);
    // int index = 0;
    // vector<int> ans;

    // printAllEvens(arr, size, index, ans);
    // for( auto num : ans){
    //     cout<<num<<" ";
    // }

    // printAllOdds(arr, size, index);
    // for( auto num : ans){
    //     cout<<num<<" ";
    // }
 
    // int ans = INT_MAX;
    // mininArray(arr, size, index, ans);
    // cout << "Minimum element is : " << ans << endl;

    // int ans = INT_MIN;
    // maxinArray(arr, size, index, ans);
    // cout << "Maximum element is : " << ans << endl;

    // int target = 50;
    // bool ans = searchInArray(arr, size, index, target);
    // cout << "Element found or not : " << ans << endl;

    // printArray(arr, size, index);
    // cout<<endl;

    return 0;
}