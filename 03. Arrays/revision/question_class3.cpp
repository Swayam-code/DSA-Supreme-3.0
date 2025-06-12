#include <iostream>
#include<climits>

using namespace std;

int findMinimumin2DArray ( int arr[][3], int rowSize, int colSize){
    int minValue = INT_MAX;
    for(int r=0; r< rowSize; r++){
        for(int c=0; c< colSize ; c++){
            minValue = min(arr[r][c], minValue);
        }
    }
    //overall T.C.-> o(colSize * rowSize)
    //overall S.C.-> o(1)
    return minValue;
}

int findMaximumin2DArray ( int arr[][3], int rowSize, int colSize){
    int maxValue = INT_MIN;
    for(int r=0; r< rowSize; r++){
        for(int c=0; c< colSize ; c++){
            maxValue = max(arr[r][c], maxValue);
        }
    }
    //overall T.C.-> o(colSize * rowSize)
    //overall S.C.-> o(1)
    return maxValue;
}

//row-wise-sum
void printRowSum (int arr[][3], int rowSize, int colSize){
    for(int r=0; r< rowSize; r++){
        int sum = 0;
        for(int c=0; c< colSize ; c++){
            sum += arr[r][c];
        }
        cout << "Sum of row " << r << " is: " << sum << endl;
    }
    //overall T.C.-> o(colSize * rowSize)
    //overall S.C.-> o(1)
}

//column-wise sum
void printColumnSum (int arr[][3], int rowSize, int colSize){
    for(int c=0; c< colSize; c++){
        int sum = 0;
        for(int r=0; r< rowSize ; r++){
            sum += arr[r][c];
        }
        cout << "Sum of column " << c << " is: " << sum << endl;
    }
    //overall T.C.-> o(colSize * rowSize)
    //overall S.C.-> o(1)
}

//diagonal sum
void printDiagonalSum (int arr[][3], int rowSize, int colSize){
    int sum = 0;
    for(int r=0; r< rowSize; r++){
        sum = arr[r][r] + sum; //for square matrix only
    }
    cout << "Sum of diagonal is: " << sum << endl;
    //overall T.C.-> o(rowSize)
    //overall S.C.-> o(1)
}

//reverse diagonal sum - HW-1
void printReverseDiagonalSum (int arr[][3], int rowSize, int colSize){
    int sum = 0;
    for(int r=0; r< rowSize; r++){
        sum = arr[r][colSize - 1 - r] + sum; //for square matrix only
    }
    cout << "Sum of reverse diagonal is: " << sum << endl;
    //overall T.C.-> o(rowSize)
    //overall S.C.-> o(1)
}

void transposeMatrix(int arr[][3], int rowSize, int colSize){
    //Method-2
    for(int r=0; r< rowSize; r++){
        for(int c=r; c< colSize ; c++){
            swap(arr[r][c], arr[c][r]);
        }
    }
    
    for(int r=0; r< colSize; r++){
        for(int c=0; c< rowSize ; c++){
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }

    //Method-1
    // int ans[100][100]={0};

    // for(int r=0; r< rowSize; r++){
    //     for(int c=0; c< colSize ; c++){
    //         ans[c][r] = arr[r][c];
    //     }
    // }

    // for(int r=0; r< colSize; r++){
    //     for(int c=0; c< rowSize ; c++){
    //         cout << ans[r][c] << " ";
    //     }
    //     cout << endl;
    // }
}

int main(){
    int arr[3][3] = {{1, 28, 39},
                     {5, 60, 7},
                     {9, 10, -2}};
    
    int rowSize = 3;
    int colSize = 3;

    transposeMatrix(arr, rowSize, colSize);

    // printRowSum(arr, rowSize, colSize);
    // printColumnSum(arr, rowSize, colSize);
    // printDiagonalSum(arr, rowSize, colSize);
    // printReverseDiagonalSum(arr, rowSize, colSize);
    // int ans = findMaximumin2DArray(arr, rowSize, colSize);
    // cout << "Maximum value in the array is: " << ans << endl;

    // int ans = findMinimumin2DArray(arr, rowSize, colSize);
    // cout << "Minimum value in the array is: " << ans << endl;
    
    return 0;

}   