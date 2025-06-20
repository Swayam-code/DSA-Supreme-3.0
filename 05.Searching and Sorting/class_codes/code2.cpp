#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int peakIndexInMountainArray(vector<int>&arr){
   //method-1
        // int max = INT_MIN;
        // int maxIndex = -1;
        //O(N)
        // for(int i=0; i<arr.size();i++){
        //     if(arr[i]>max){
        //         max=arr[i];
        //         maxIndex=i;
        //     }
        // }

        //O(logn):binary search
        int s=0;
        int n=arr.size();
        int e=n-1;
        int mid=s + (e-s)/2;
        while(s<e){
            if(arr[mid]< arr[mid+1]){
                s=mid+1;
            }
            else{
                e=mid;
            }
            mid=s+(e-s)/2;
        }
        return e;
}

int main(){
    vector<int> arr={1,2,3,0,6,3,2};
    int n= arr.size();
     
    int ans= peakIndexInMountainArray(arr);
    cout<< ans<<endl;
    return 0;
}