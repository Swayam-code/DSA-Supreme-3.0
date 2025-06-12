#include<iostream>
#include<climits>
// #include<algorithm>
using namespace std;

void reverseArray(int arr[],int n){
    int l=0, h=n-1;
    while(l<h){
        // swap(arr[l],arr[h]);
        // l++;
        // h--;
        swap(arr[l++],arr[h--]);

    }
}

void swap(auto a,auto b){
    // 1.temp variable
    // auto temp=0;
    // a =temp;
    // a=b;
    // b= temp;
    
    // 2.arithmetic method
    // a=a*b;
    // b= a/b;
    // a= a/b;

    // 3. XOR  bitwise method
    a=a^b; 
    b=a^b;
    a=a^b;
}

int main(){
          
    auto a= 4;
    auto b=32;
    swap(a,b);
    cout<<"a:"<<a<<"b:"<<b;
    // reverse array
    // int arr[]= {10,20,30,40,50,60,70,80};
    // int n=8;

    //method-1
    // reverseArray(arr,n);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<endl;
    // }
     

    //method-2
    // reverse(arr,arr+n);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<endl;
    // }

    return 0;
}