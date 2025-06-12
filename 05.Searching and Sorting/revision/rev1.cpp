#include<iostream>
#include<algorithm>
using namespace std;

int binarySearch(int arr[],int n,int target){
    int s=0;
    int e= n-1;
    int mid= s+(e-s)/2;

    while(s<=e){
        //update startingIndex
        if(arr[mid]== target){
            return mid;
            
        }
        if(arr[mid]<target){
            s=mid+1;
        }
        //update lastIndex
        else if(arr[mid]>target){
            e=mid-1;
        }
        //bhul jata hun
        mid=s+(e-s)/2;
    }
    return -1;
}

void findFirstOccurence(int arr[], int n, int target, int &ansIndex){
   int s = 0;
   int e = n-1;
   int mid  = s+ (e-s)/2;

   while(s<=e){
      if(arr[mid] == target){
        //ans may/mayn't be first occurence
        //store and compute
        ansIndex = mid;
        //first occurence ke liye we have to shift left
        e = mid -1;
      }

      if(target > arr[mid]){
        s = mid+1;
      }
      
      if(target < arr[mid]){
        e = mid -1 ;
      }
      //bhul jata hun
      mid  = s + (e-s)/2;
   }
}

void findLastOccurence(int arr[], int n, int target, int &ansIndex){
   int s = 0;
   int e = n-1;
   int mid  = s+ (e-s)/2;

   while(s<=e){
      if(arr[mid] == target){
        //ans may/mayn't be last occurence
        //store and compute
        ansIndex = mid;
        //last occurence ke liye we have to shift right
        s = mid +1;
      }

      if(target > arr[mid]){
        s = mid+1;
      }
      
      else if(target < arr[mid]){
        e = mid -1 ;
      }
      //bhul jata hun
      mid  = s + (e-s)/2;
   }
}

//HW-1
int findTotalOccurence(int arr[],int n, int target, int &firstIndex, int &lastIndex){
    firstIndex = -1;
    lastIndex = -1;
    findFirstOccurence(arr,n,target,firstIndex);
    findLastOccurence(arr,n,target,lastIndex);
    if(firstIndex != -1 && lastIndex != -1){
        return lastIndex - firstIndex + 1;
    }
    return 0;
}

int main(){

    int arr[]={1,2,2,3,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target= 3;
    //-1 ->index not found
    int ansIndex = -1;
    int firstIndex = -1;
    int lastIndex = -1;
    int ans = findTotalOccurence(arr,n,target,firstIndex,lastIndex);
    cout << "Total Occurence of " << target << " is : " << ans << endl;

    // findFirstOccurence(arr,n, target,ansIndex);
    // cout <<"find first occurence : " << ansIndex << endl;

    findLastOccurence(arr,n, target,ansIndex);
    cout <<"find last occurence : " << ansIndex << endl;

    // int ans= binarySearch(arr,n,target);
    // int ans = binary_search(arr,arr+n, target); //using-stl

    // cout<<"find target:"<<ans<<endl;
    return 0;
}