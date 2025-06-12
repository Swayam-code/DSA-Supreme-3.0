#include <iostream>
#include <climits>
using namespace std;

void print (int arr[], int size) {
    for (int index = 0; index < size; index++) {
        cout << arr[index] << " ";
    }
    cout << endl;
}

void solve(int arr[], int n){
    for(int i=0;i< n ;i++){
        arr[i]=arr[i] * 10;
    }
}

bool findTarget(int arr[], int size, int target) {
    //Method-2- reverse loop
    for(int i= size-1; i>=0; i--){
        if(arr[i]==target){
            return true;
        }
    }
    return false;
    
    //Method-1- normal loop
    // for (int i = 0; i < size; i++) {
    //     int currentElement = arr[i];
    //     if (currentElement == target) {
    //         // found
    //         return true;
    //     }
    // }
    // return false;
}

int findMax (int arr[], int size) {
    int maxAns = INT_MIN;
    for (int i = 0; i < size; i++) {
        maxAns = max(maxAns, arr[i]);
        // if (arr[i] > maxAns) {
        //     maxAns = arr[i];
        // }
    }
    return maxAns;
}

int findMin (int arr[], int size) {
    int minAns = INT_MAX;
    for (int i = 0; i < size; i++) {
        minAns = min(minAns, arr[i]);
        // if (arr[i] < minAns) {
        //     minAns = arr[i];
        // }
    }
    return minAns;
}

//extreme priniting - 2 pointer approach
void extremePrint(int arr[], int n) {
    int i = 0;
    int j = n - 1;
    //Method-1
    // while (i <= j) {
    //     if (i == j) {
    //         cout << arr[i] << " ";
    //         break;
    //     } else {
    //         cout << arr[i] << " ";
    //         i++;
    //         cout << arr[j] << " ";
    //         j--;
    //     }
    // }
    
    //Method-2
    while(i<=j){
        cout << arr[i] << " ";
        i++;
        if(j>i){
            cout << arr[j] << " ";
            j--;
        }
    }
}

void printZeroesAndOnes (int arr[], int n) {
    int zeroCount = 0;
    int oneCount = 0;

    for (int i = 0; i < n; i++) {
        int currentElement = arr[i];
        if (currentElement == 0) {
            zeroCount++;
        }

        if (currentElement == 1) {
            oneCount++;
        }
    }

    cout << "total zeroes: " << zeroCount << endl;
    cout << "total ones: " << oneCount << endl;
}

//HW-1
void swap(int arr[], int i, int j) {
    //Method-1- swap using temp variable
    // int temp = arr[i];
    // arr[i] = arr[j];
    // arr[j] = temp;

    //Method-2- swap using arithmetic operations
    // arr[i] = arr[i] + arr[j];
    // arr[j] = arr[i] - arr[j];
    // arr[i] = arr[i] - arr[j];

    //Method-3 - XOR swap
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[i] ^ arr[j];
    arr[i] = arr[i] ^ arr[j];
}

void reverseArray(int arr[], int n) {
    int i = 0;
    int j = n - 1;
    while (i < j) {
        swap(arr, i, j);
        i++;
        j--;
    }
}

int main () {

    int arr[] ={10,20,30,40,50,60,70};
    int size=7;
    
    reverseArray(arr, size);
    print(arr, size);

    // cout << "Before swap: " << arr[0] << " " << arr[1] << endl;
    // swap(arr, 0, 1);
    // cout << "After swap: " << arr[0] << " " << arr[1] << endl;
    
    // extremePrint(arr,size);
    //array creation
    // int arr[10000];
    // bool arr[10];
    // char arr[15];
    //error
    // int arr[];

    //initialization of array
    // int arr[10] = {10, 20, 30, 40, 50};
    // int brr[4] ={0}; // all elements are initialized to 0

    // cout << arr[0] << endl; // 10
    // cout << arr[3] << endl; // 30

    //indexing
    // int marks[6];
    // marks[0];
    
    // //fill
    // int drr[3] ={10,20,30};
    // fill(drr, drr + 3, 23); // fill all elements with 23
    // cout << drr[0] << " " << drr[1] << " " << drr[2] << endl; 

    // //input
    // int arr[10];
    // for (int index =0; index<5; index++){
    //     cout << "Enter box element " << index << ": ";
    //     cin >> arr[index]; // input 10 elements
    // }
    // //output
    // for (int index =0; index<5; index++){
    //     cout << arr[index] << " "; // output 10 elements
    // }
    
    // int arr[]= {10,20,30,40,50};
    // int size= 5;
    
    // int arr[100];
    // int size;
    // // int target;

    // cout << "Enter the number of elements: " << endl;
    // cin >> size;

    // for(int i=0;i<size;i++){
    //     cout<<"Enter the input value for index :"<<i<<endl;
    //     cin>> arr[i];
    // }

    // printZeroesAndOnes(arr,size);
    
    // cout << "Min number is: " << findMin(arr, size) << endl;
    // cout << "Max number is: " << findMax(arr, size) << endl; 
    // cout << "Enter the target value: " << endl;
    // cin >> target;

    // bool ans= findTarget(arr,size,target);
    // cout <<"ans: "<< ans << endl; // true or false
    
    // solve(arr,size);
    // print(arr,size);


    
    

}