//GFG - Find the odd appearing element

//Given an array where all elements appear even number of times except one. All repeating occurrences of elements appear in pairs and these pairs are not adjacent (there cannot be more than two consecutive occurrences of any element). Find the element that appears odd number of times. 

// Input: arr[] = {1, 1, 2, 2, 1, 1, 2, 2, 13, 1, 1, 40, 40, 13, 13}
// Output: 13

// Input: arr[] = {1, 1, 2, 2, 3, 3, 4, 4, 3, 600, 600, 4, 4}
// Output: 3

#include<iostream>
using namespace std;

int findOddOccuringElement(int arr[], int n){
    int s = 0;
    int e = n-1;
    int mid = s + ((e-s)>>1);

    while(s<=e){
        //single element found
        if(s == e){
            return s;
        }

         //duplicate doesn't exist
         if(mid-1>=0 && arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]){
            return mid;
         }

        //duplicate exists in left index
        if(mid-1>=0 && arr[mid] == arr[mid-1]){
            int pairStartingIndex = mid-1;
            if(pairStartingIndex%2 == 0){
                //pair starting index is even
                //move to right side
                s = mid + 1;
            }
            else{
                //pair starting index is odd
                //move to left side
                e = mid - 2;
            }
        }
        //duplicate exists in right index
        if(mid+1<n && arr[mid] == arr[mid+1]){
            int pairStartingIndex = mid;
            if(pairStartingIndex%2 == 0){
                //pair starting index is even
                //move to right side
                s = mid + 2;
            }
            else{
                //pair starting index is odd
                //move to left side
                e = mid - 1;
            }
        }
        //bhul jata hun
        mid = s + ((e-s)>>1);
    }
    return -1; //no ans found
}
int main(){
    int arr[] = {2,2,1,3,3,1,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    
    //findOddOccuringElement
    int ansIndex = findOddOccuringElement(arr, size);
    if(ansIndex == -1) {
        cout << "No odd occurring element found." << endl;
    } else {
        cout << "find odd occuring element: " << ansIndex << endl;
        cout << "odd occuring element: " << arr[ansIndex] << endl;
    }

    return 0;
}