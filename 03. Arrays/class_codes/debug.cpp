#include<iostream>
using namespace std;

int linearSearch(int arr[], int n ,int val){
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            return i;
        }
    }
    return val;
}
int main(){
    
    int arr[]={1,2,3,4,5,6,7};
    int n=7;
    linearSearch(arr,n,7);
    // 1.
    // int n, sum=0;
    // cin >> n;
    // int input[n];
    // for(int i=0;i<n;i++){
    //     cin >> input[i];
    // }
    //  for(int i=0; i<n; i++){
    //      sum = sum + input[i];
    //  }
    // cout << sum << endl;
    // return 0;
}