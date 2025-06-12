//Exponential search for UNBOUNDED_ARRAY
#include<iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int start, int end, int x){
    while(start <= end){
        int mid = start + (end - start) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) start = mid + 1;
        else end = mid - 1;
    }
    return -1; // Element not found
}

//Brute force approach
int expSearchBruteForce(vector<int> arr, int n, int x){
    if(arr[0] == x) return 0;
    int i =1;
    while(1){
        if(arr[i] > x) break; 
        if(arr[i] == x) return i;
        i++;
    }
    return -1; // Element not found
}

//Two-pointer approach
int expSearch(vector<int> arr, int n, int x){
    if (arr[0] == x) return 0;
    int i = 0, j = 1;
    while(arr[j]< x){
        i = j;
        j = j * 2;
    }
    return binarySearch(arr, i, j, x);
}

int main(){
    vector<int> arr;
    int n = arr.size();
    int x = 15;
    int ans = expSearch(arr, n, x);

}