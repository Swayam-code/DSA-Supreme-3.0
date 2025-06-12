#include<iostream>
using namespace std;

int binarySearch(int a[], int start, int end, int x){
    while(start <= end){
        int mid = start + (end - start) / 2;
        //condition
        if (a[mid] == x) return mid;
        //condition for start
        if (a[mid] < x) start = mid + 1;
        //condition for end
        else end = mid - 1;
    }
}

int expSearch(int a[], int n, int x){
    if (a[0] == x) return 0;
    int i = 1;
    while (i < n && a[i] <= x) {
        i = i * 2;
    }
    return binarySearch(a, i / 2, min(i, n - 1), x);
}

int main(){
    int arr[]={3,4,5,6,11,13,14,15,56,79};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x= 15;
    int ans  = expSearch(arr,n,x);
    cout << "Element found at index: " << ans << endl;
    return 0;
}
// Time Complexity: O(log i) + O(log(2^(logm-1)) 
// Space Complexity: O(1)