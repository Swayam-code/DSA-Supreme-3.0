#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArray(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void printArrayofArrays(vector<vector<int>>& arr){
    for(int i=0;i<arr.size();i++){
        vector<int> &temp = arr[i];
        int a = temp[0];
        int b = temp[1];
        cout<<a<<" "<<b<<endl;
    }
}

bool myComp(int a, int b){
    // return a < b; //for increasing order
    return a > b; //for decreasing order
}

bool myCompfor1stIndex(vector<int>& a, vector<int>& b){
    return a[1] < b[1]; //for increasing order
    // return a[1] > b[1]; //for decreasing order
}

int main(){
    //vector of vector sorting
    vector<vector<int>> arr;
    int n;
    cout << "Enter the size: ";
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int a, b;
        cout << "enter a,b "<< endl;
        cin >> a >> b;
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        arr.push_back(temp);
    }
    cout << "Before sorting: " << endl;
    printArrayofArrays(arr);
    cout << "Sorted by 1st index: " << endl;
    sort(arr.begin(), arr.end(), myCompfor1stIndex);
    printArrayofArrays(arr);
   

    // vector<int> arr = {5,3,0,-1,33,6,23};
    // sort(arr.begin(),arr.end());
    //using custom comparator
    // sort(arr.begin(),arr.end(),myComp);
    // printArray(arr);
    return 0;
}