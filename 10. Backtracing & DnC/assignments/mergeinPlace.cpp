//merge two sorted arrays in place (using gap method)
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, vector<int> &brr){
    int n = arr.size();
    int m = brr.size();
    int total_length = n + m;
    int gap = (total_length)/2 +(total_length)%2;
    
    while(gap > 0){
        int i = 0;
        int j = gap;
        while(j < total_length){
            if(j < n && i < n){
                if( j< n && arr[i] > arr[j]){
                    swap(arr[i], arr[j]);
                }
            }
            else if(i < n && j >= n && arr[i] > brr[j-n]){  
                if(arr[i] > brr[j-n]){
                    swap(arr[i], brr[j-n]);
                }
            }
            else{
                if( j>=n && i>=n && brr[i-n] > brr[j-n]){
                    swap(brr[i-n], brr[j-n]);
                }
            }
            ++i;
            ++j;
        }
        gap = gap <=1 ? 0 : (gap/2) + (gap % 2);
    }
}

int main(){

    vector<int> arr = {7,6,8,9,4,5};
    vector<int> brr= {1,3,2,0};
    cout << "Array before merging: ";
    for(int i=0; i< arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Array 2 before merging: ";
    for(int i=0; i< brr.size(); i++){
        cout << brr[i] << " ";
    }
    cout << endl;

    merge(arr, brr);
    cout << "Array after merging: ";
    for(int i=0; i< arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Array 2 after merging: ";
    for(int i=0; i< brr.size(); i++){
        cout << brr[i] << " ";
    }
    cout << endl;
    cout << "Merged array: ";
    for(int i=0; i< arr.size(); i++){
        cout << arr[i] << " ";
    }
    for(int i=0; i< brr.size(); i++){
        cout << brr[i] << " ";
    }

    return 0;
}