#include<iostream>
#include<vector>
using namespace std;

void printSubArrays(vector<int> &arr, int n, int s, int e){
    //base case
    if(s == n){
        return;
    }
    if(e == n){
        printSubArrays(arr, n, s+1, s+1);
        return;
    }
    
    //print
    cout << "[ ";
    for(int i = s; i <= e; i++){
        cout << arr[i] << " ";
    }
    cout << "]" << endl;

    //recursion
    printSubArrays(arr, n, s, e+1);
}

int main(){
    vector<int> nums = {1, 2, 3,4, 5};
    int n = nums.size();
    int s = 0;
    int e = 0;
    printSubArrays(nums, n, s, e);
    cout << "All subarrays printed." << endl;
    

    return 0;
}