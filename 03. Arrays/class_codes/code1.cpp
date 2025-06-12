#include<iostream>
#include<climits>
using namespace std;
void print(int arr[],int size){
    for(int index=0;index<size;index++){
        cout<<arr[index]<<" ";
    }
}

void solve(int arr[],int size){
    for(int index=0;index<size;index++){
        arr[index]=arr[index]*10;
    }
}

bool findTarget(int arr[],int size,int target){
    //traverse the array
    for(int i=0;i<size;i++){
        int currentElement=arr[i];

        if(currentElement == target){
            //found
            return true;
        }
    }
    return false;
}

int findMax(int arr[],int size){
    int maxAns= INT_MIN;
    for(int i=0;i<size;i++){
        if(arr[i]>maxAns){
            maxAns=arr[i];
        }
    }
}

int extremePrint(int arr[],int n){
    int i=0;
    int j=n-1;
    //  while(i<=j){
    //     cout<<arr[i]<<" ";
    //     i++;
     
    //  if(j>i){
    //     cout<< arr[j]<<" ";
    //     j--;
    //  }
    // }

    while(i<=j){
        if(i<=j){
            if(i==j){
               cout<<arr[i]<<" ";
               break;
            }
            else{
                cout<<arr[i]<<" ";
                i++;
                cout<<arr[j]<<" ";
                j--;
            }
        }
    }
}

void printZeroesAndOnes(int arr[],int n){
    int zeroCount=0;
    int oneCount=0;

    for(int i=0;i<n;i++){
        int currentElement= arr[i];
        if(currentElement==0){
            zeroCount++;
        }

        if(currentElement==1){
            oneCount++;
        }
    }

    cout<<"total zeroes:"<<zeroCount<<endl;
    cout<<"total ones:"<<oneCount<<endl;
}

int main(){

    int arr[10];
    int size;
    cout<<"enter the number of elements :"<<endl;
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"enter the input value for index :"<<i<<endl;

        cin>>arr[i];
    }

    printZeroesAndOnes(arr,size);
    return 0;

    // int arr[]={10,20,30,40,50,60,70};
    // int size=7;
    // extremePrint(arr,size);
    
    // int arr[]={10,20,30,40,50};
    // int size=5;
    // int target= 40;
    // int arr[100];
    // int size;
    // cout<<"enter the number of elements :"<<endl;
    // cin>>size;

    // for(int i=0;i<size;i++){
    //     cout<<"enter the input value for index :"<<i<<endl;
    //     cin>> arr[i];
    // }

    // bool ans= findTarget(arr,size,target);

    // cout<<"max number is: "<<findMax(arr,size)<<endl;
    

    // solve(arr,size);
    // print(arr,size);

    //creation of array
    // int arr[10];

    //error
    // int brr[];

    // int crr[]={1,2,3,4};
    // int drr[4]={5};

    // indexing
    // cout<< drr[0]<<endl;
    // cout<< drr[1]<<endl;
    // cout<< crr[0]<<endl;
    // cout<< crr[1]<<endl;

    // cout<<drr[0]<<endl;
    // cout<<crr[4]<<endl;
    // fill(arr,arr+10,23);
    // cout<< arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[9]<<endl;

    // input
    // int arr[5];
    // for(int index=0;index<5;index++){
    //     cout<<"Enter the value for box index :"<< index << endl;
    //     cin>>arr[index];
    // }

    // //output
    // for(int index=0;index<5;index++){
    //     cout<<arr[index]<<" ";
    // }

    return 0;
}