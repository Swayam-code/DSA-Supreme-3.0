#include<iostream>
#include<vector>
using namespace std;

// void solve(int *arr[],int size){
//     cout<<sizeof(arr)<<endl;
// }

void solve(vector<int>v){
    cout<<sizeof(v)<<endl;
}

int main(){
    // vector<int>v;
    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);
    // int arr[]={10,20,30,40,50};
    // int size=5;

    // // solve(arr,size);
    // solve(v);

    int a=10;
    int *p=&a;
    int **q= &p;
    int **r=q;

    cout<< **r<<endl;
    return 0;
}