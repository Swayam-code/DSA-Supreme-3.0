#include<iostream>
#include<vector>
using namespace std;



bool search2DArray2 (vector<vector<int>> &arr1, int target){
    int rowSize = arr1.size();
    if(rowSize == 0) return false; // Check if the array is empty
    int colSize = arr1[0].size();
    for(int r=0; r< rowSize; r++){
        for(int c =0; c< colSize ; c++){
            if(arr1[r][c]== target){
                cout<<"Element found at arr["<<r<<"]["<<c<<"]"<<endl;
                return true;
            }
        }
    }
    return false;
}

int main(){

    vector<vector<int>> arr1(4, vector<int>(3, 0)); 
    int rowSize = arr1.size();
    int colSize = arr1[0].size();

    for(int r=0; r< rowSize; r++){
        for(int c=0; c< colSize; c++){
            cout << "Enter element at arr[" << r << "][" << c << "] : ";
            cin >> arr1[r][c];
        }
        cout<<endl;
    }

    int target =40;
    bool ans = search2DArray2(arr1, target);
    cout << "ans is: " << ans << endl;

    // int arr[3][4] = {{1, 2, 3, 4},
    //                  {5, 6, 7, 8},
    //                  {9, 10, 11, 12}};
    
    // int rowSize = 3;
    // int colSize = 4;
    // int target = 11;

    // bool ans = search2DArray(arr, rowSize, colSize, target);
    // cout << "ans is: " << ans << endl;
    

    return 0;
}