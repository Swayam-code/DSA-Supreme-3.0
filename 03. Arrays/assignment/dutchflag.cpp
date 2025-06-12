#include<iostream>
#include<vector>
using namespace std;

void moveAllNegtoLeft(int *arr,int n){
    int l=0,h= n;
    while(l<h){
     if(arr[l]<0){
        l++;
     }
     else if(arr[h]>0){
        h--;
     }
     else{
        swap(arr[l],arr[h]);
     }
    }

}
int main(){
    int arr[]={2,3,4,5,-1,-29,-6,0,4};
    
    int n=9 ;
    moveAllNegtoLeft(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}