#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void findFirstOccurence( int arr[],int n, int target, int &ansIndex){
    int s=0;
    int e= n-1;
    int mid= s+(e-s)/2;

    while(s<=e){
        if(arr[mid]== target){
            //store and compute
            ansIndex= mid;
            //we want find first Occurence
            e= mid-1;
        }

        if(target> arr[mid]){
            s= mid+1;
        }
        if(target< arr[mid]){
            e= mid-1;
        }
        //mai bhul jata hun
        mid= s+(e-s)/2;
    }
}


void findLastOccurence(int arr[],int n, int target, int &ansIndex){
    int s=0;
    int e= n-1;
    int mid= s+ (e-s)/2;

    while(s<=e){
        if(arr[mid]== target){
            ansIndex = mid;
            s= mid+1;
        }

        if(target> arr[mid]){
            s= mid+1;
        }

        if(target< arr[mid]){
            e= mid-1;
        }
        //bhul jata hun
        mid= s+(e-s)/2;
    }
}

int missingNumber(vector<int>& arr) {
        sort(arr.begin(),arr.end());

        int ansIndex= -1;
        int n= arr.size();
        int s=0, e=n-1;
        int mid= s+(e-s)/2;

        while(s<=e){
            int number= arr[mid];
            int index= mid;
            int diff= number- index;

            if(diff==0){
                //right
                s= mid+1;
            }

            else if(diff==1){
                //index may or mayn't be ans
                ansIndex= index;
                e= mid-1;
            }
            //bhul jata hun
            mid= s+(e-s)/2;
        }

        //extreme right case
        if(ansIndex == -1){
            return n;
        }

        return ansIndex;
    }

int main(){

    vector<int> arr={1,2,5,3,7,9,6,8};

    int ans= missingNumber(arr);
    cout<< ans<<endl;
    // int arr[]={10,20,20,20,20,20,20,30,40,50,60};
    // int n=11;
    // int target= 500;
    // int ansIndex= -1;

    // bool ans= binary_search(arr,arr+n,target);
    // cout<< ans<< endl;
    
    // findFirstOccurence(arr,n,target,ansIndex);
    // findLastOccurence(arr,n,target,ansIndex);

    // cout<<"last occurence index: "<< ansIndex<<endl;
    return 0;
}