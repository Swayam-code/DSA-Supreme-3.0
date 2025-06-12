#include<iostream>
#include<vector>
using namespace std;

// Merge Sort
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

void merge(int arr[], int start, int mid, int end){
    int n1 = mid - start + 1; // size of left half
    int n2 = end - mid; // size of right half

    // create temporary arrays
    int *leftArr = new int[n1];
    int *rightArr = new int[n2];

    // copy data to temporary arrays
    int index = start;
    for(int i = 0; i < n1; i++){
        leftArr[i] = arr[index];
        index++;
    }

    index = mid+1;
    for(int j = 0; j < n2; j++){
        rightArr[j] = arr[index];
        index++;
    }

    // merge the temporary arrays back into arr
    int leftIndex = 0, rightIndex = 0, mainArrayIndex = start;
    while(leftIndex < n1 && rightIndex < n2){
        if(leftArr[leftIndex] <= rightArr[rightIndex]){
            arr[mainArrayIndex] = leftArr[leftIndex];
            leftIndex++;
            mainArrayIndex++;
        } else {
            arr[mainArrayIndex] = rightArr[rightIndex];
            rightIndex++;
            mainArrayIndex++;
        }
    }
    // copy remaining elements of leftArr if any
    while(leftIndex < n1){
        arr[mainArrayIndex] = leftArr[leftIndex];
        leftIndex++;
        mainArrayIndex++;
    }
    // copy remaining elements of rightArr if any
    while(rightIndex < n2){
        arr[mainArrayIndex] = rightArr[rightIndex];
        rightIndex++;
        mainArrayIndex++;
    }
    // free the temporary arrays
    delete[] leftArr;
    delete[] rightArr;

}

void mergeSort(int arr[],int start, int end){
    if(start >= end) return; // base case

    int mid = start + (end - start) / 2; // find the mid index
    mergeSort(arr, start, mid); // sort the left half
    mergeSort(arr, mid + 1, end); // sort the right half
    merge(arr, start, mid, end); // merge the two halves


}

void mergeSortedArrays(int arr[], int sizeArr, int brr[], int sizeBrr, vector<int> &ans){
    int i = 0, j = 0; // i -> index for arr, j -> index for brr
    
    //while i and j are within bounds of arr and brr
    while(i < sizeArr && j < sizeBrr){
        if(arr[i] < brr[j]){
            ans.push_back(arr[i]);
            i++;
        } else {
            ans.push_back(brr[j]);
            j++;
        }
    }
    //if any elements are left in arr , add them to ans
    while(i < sizeArr){
        ans.push_back(arr[i]);
        i++;
    }
    //if any elements are left in brr , add them to ans
    while(j < sizeBrr){
        ans.push_back(brr[j]);
        j++;
    }
}

int main(){

    int arr[] = {10,80,110,90,70,30,50,20};
    int size = sizeof(arr)/sizeof(arr[0]);
    int s = 0;
    int e = size - 1;

    cout << "Before sorting: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, s, e);
    cout << "After sorting: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    // int arr[] = {10,30,50,70,90};
    // int sizeArr = sizeof(arr)/sizeof(arr[0]);

    // int brr[] = {20,40,60,80,100};
    // int sizeBrr = sizeof(brr)/sizeof(brr[0]);

    // vector<int> ans;
    // mergeSortedArrays(arr, sizeArr, brr, sizeBrr, ans);
    // cout << "Merged array: ";
    // for(int num : ans){
    //     cout << num << " ";
    // }

    return 0;
}