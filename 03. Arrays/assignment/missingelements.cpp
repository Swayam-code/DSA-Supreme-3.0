#include<iostream>
using namespace std;

void findMissing(int *arr,int n){
    //1.visiting method
    for(int i=0;i<n;i++){
        int index= abs(arr[i]);

        if(arr[index-1]>0){
            arr[index-1] *=-1;
        }
    }

    for(int i=0;i<n;i++){
        if(arr[i]>0)
        cout<<i+1<<" ";
    }
}

void sortingAndSwapping(int *arr,int n){
    int i=0;
    while(i<n){
        int index= arr[i]-1;

        if(arr[i]!= arr[index]){
            swap(arr[i],arr[index]);
        }
        else{
            ++i;
        }
    }

    for(int i=0;i<n;i++){
        if(arr[i]!= i+1)
        cout<<i+1<<" ";
    }
    cout<<endl;

}

int main(){
    int arr[]={5,3,2,2,2,2,7};
    int n= sizeof(arr)/sizeof(arr[0]);

    // findMissing(arr,n);
    sortingAndSwapping(arr,n);
    return 0;
}