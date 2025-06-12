#include<iostream>
#include<vector>
using namespace std;
void print2DArray(int arr[][3], int rowSize, int colSize){
    for(int r=0; r< rowSize;r++){
        for(int c=0; c<colSize;c++){
            cout<<arr[r][c]<<" ";
        }
        cout<<endl;
    }
}
int main(){

    //TAKING INPUT FROM USER
    int arr[2][3];
    int rowSize=2;
    int colSize=3;

    //row-wise
    // for(int r=0; r< rowSize;r++){
    //     for(int c=0; c<colSize;c++){
    //         cout<<"Enter element at arr["<<r<<"]["<<c<<"] : ";
    //         cin>>arr[r][c];
    //     }
    // }

    //col-wise : HW-2
    for(int c=0; c<colSize;c++){
        for(int r=0;r<rowSize;r++){
            cout<<"Enter element at arr["<<r<<"]["<<c<<"] : ";
            cin>>arr[r][c];
        }
    }

    print2DArray(arr, rowSize, colSize);
    
    //Creation of 2D-array
    // int nums[4][3];
    //garbage values -> static array
    // zero values -> dynamic array

    //Initialization of 2D-array
    // int arr[3][3]={{10,20,100},
    //                {30,40,200},
    //                {50,60,300}};

    // int arr[3][2] = {10,20,30,40,50,60};
    // int arr[3][2]={{10,20}}; //rest are 0s
    //Initialize using fill method
    // int brr[3][2];
    // int rowSize=3;
    // int colSize=2;
    // for (int i = 0; i < rowSize; i++) {
    //     fill(brr[i], brr[i] + colSize, 42); 
    // }
    // cout << arr[2][1] << endl; 

    // int rowSize =3;
    // int colSize =3;
    //printing 2D-array - row-wise
    // for(int rowIndex=0;rowIndex<rowSize;rowIndex++){
    //     for(int colIndex=0;colIndex<colSize;colIndex++){
    //         cout<<arr[rowIndex][colIndex]<<" ";
    //     }
    //     cout<<endl;
    // } 
    
    //col-wise
    // for(int c=0; c<colSize;c++){
    //     for(int r=0;r<rowSize;r++){
    //         cout<<arr[r][c]<<" ";
    //     }
    //     cout<<endl;
    // }
    //diagonal-wise
    //  Method-1
    // for(int r= 0; r< rowSize; r++ ){
    //     for(int c=0; c < colSize ; c++){
    //         if (r==c){ 
    //             cout << arr[r][c]<< " ";
    //         }
    //     }
    //     cout << endl;
    // }
    //Method-2
    // for(int r=0; r< rowSize;r++){
    //     cout << arr[r][r]<< endl;
    // }
    
    //HW-1
    //print opposite diagonal -> rowIndex + colIndex = rowSize - 1
    // for(int r=0; r< rowSize;r++){
    //     cout << arr[r][rowSize-1-r]<< endl;
    // }

    // //vector-array
    // vector<int> arr;
    // vector<int> arr1(10);
    // vector<int> arr2(10,-1);
 
    // //insertion in a vector-array
    // arr.push_back(10);
    // arr.push_back(20);
    // arr.push_back(30);
    // arr.push_back(40);
    // int n = arr.size();

    // for( int i=0;i<n;i++) {
    //     cout<<arr[i]<<" ";
    // }

    // //removal from a vector-array
    // arr.pop_back();

    // for( int i=0;i<n;i++) {
    //     cout<<arr[i]<<" ";
    // }

    return 0;
}