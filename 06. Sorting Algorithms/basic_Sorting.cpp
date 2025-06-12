// ---------------SORTING ALGORITHMS----------------

#include<iostream>
#include <vector>
using namespace std;

//Bubble Sort
// Time Complexity: O(n^2) in worst case
// Space Complexity: O(1)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) { // Last i elements are already sorted
            if(arr[j] > arr[j + 1]) { //for decreasing order, use arr[j] < arr[j + 1]
                // Swap arr[j] and arr[j + 1]
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort
// Time Complexity: O(n^2) in worst case
// Space Complexity: O(1)
void SelectionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        int minIndex = i; //ith element is the minimum
        // Find the minimum element in the unsorted array
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j; // Update the index of the minimum element
            }
        }
        swap(arr[i], arr[minIndex]); // Swap the found minimum element with the first element
    }
}

//Insertion Sort
// Time Complexity: O(n^2) in worst case
// Space Complexity: O(1)
void InsertionSort(vector<int>& arr) {
    int n = arr.size();
    //i = 0; is ignored as it is already assumed to be sorted
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(){
    
    vector<int> arr = {5,3,0,-1,33,6,23};
    int n = arr.size();
    // bubbleSort(arr);
    // SelectionSort(arr);
    InsertionSort(arr);
    // print the sorted array
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}