#include<iostream>
using namespace std;
void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void dutchFlag(int arr[],int n){
    //Dutch National Flag Algorithm
    int l=0, h= n-1;
    while(l <=h){
        if(arr[l] < 0){
            l++;
        }
        else if(arr[h] > 0){
            h--;
        }
        else{
            swap(arr[l], arr[h]);
            l++;
            h--;
        }
    }
}
int main(){
    int arr[]={1,2,-3,4,-5,6,-7,8,-9,10};
    int n=10;
    dutchFlag(arr,n);
    printArray(arr,n);
}