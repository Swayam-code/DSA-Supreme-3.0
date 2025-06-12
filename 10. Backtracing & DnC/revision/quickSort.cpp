#include<iostream>
using namespace std;

// Quick Sort
// Time Complexity: O(nlogn)
// Space Complexity: O(logn) for recursive stack space
void quickSort(int arr[], int start, int end){
    if(start >= end) return; // base case

    int pivot = arr[end]; // choose the last element as pivot
    int i = start - 1; // index of smaller element
    int j = start; // index for traversing the array

    while( j < pivot){
        if(arr[j] < pivot){
            i++; // increment index of smaller element
            swap(arr[i], arr[j]); // swap arr[i] and arr[j]
        }
        j++;
    }
    i++;
    swap(arr[i], arr[end]); // swap pivot with the element at index i
    // recursively sort the two halves
    quickSort(arr, start, i - 1); // sort the left half
    quickSort(arr, i + 1, end); // sort the right half
}

int main(){

    int arr[] = {2,1,3,4,5,7,6,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    int s = 0;
    int e = size - 1;
    cout << "Before sorting: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    quickSort(arr, s, e);
    cout << "After sorting: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
   

    return 0;
}