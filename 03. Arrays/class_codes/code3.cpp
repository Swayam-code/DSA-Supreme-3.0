#include<iostream>
#include<vector>
using namespace std;
//initialization and declaration

//2D array
int main(){
    vector<vector<int>> arr(4,vector<int>(3,0));

    int rowSize= arr.size();
    int colSize= arr[0].size();

    for(int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    //  int arr[2][3];
    //  int rowSize=2;
    //  int colSize=3;

    //  for(int r=0;r<rowSize;r++){
    //     for(int c=0;c<colSize;c++){
    //         cout<<"enter the value for ("<<r <<","<< c<<"):";
    //         cin>>arr[r][c];
    //     }
    //  }

    //  for( int row=0;row<rowSize;row++){
    //     for(int col=0;col<colSize;col++){
    //         cout<<arr[row][col]<<" ";
    //     }
    //     cout<<endl;
    //  }

    //method-1
    // int arr[3][3]={
    //     {10,20,30},
    //     {30,40,200},
    //     {50,60,300}
    // };
     
    //method-2
    // int arr[3][2]={10,20,30,40,50,60};
    // int arr[3][2]={10,20}; //remaining will be 0

    // int rowSize= 3;
    // int colSize= 3;
    // //row-wise traversing
    // for(int rowIndex=0;rowIndex<rowSize;rowIndex++){
    //     for(int colIndex=0;colIndex<colSize;colIndex++){
    //         cout<< arr[rowIndex][colIndex]<<" ";
    //     }
    //     cout<<endl;
    // }
 
    // cout<<endl;
    // //col-wise traversing : square matrix
    // for(int rowIndex=0;rowIndex<rowSize;rowIndex++){
    //     for(int colIndex=0;colIndex<colSize;colIndex++){
    //         cout<< arr[colIndex][rowIndex]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    // //generalized
    // for(int col=0;col<colSize;col++){
    //     for(int row=0;row<rowSize;row++){
    //         cout<<arr[row][col]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    //diagonal
    // method-1
    // for(int rowIndex=0;rowIndex<rowSize;rowIndex++){
    //     for(int colIndex=0;colIndex<colSize;colIndex++){
    //         if(rowIndex==colIndex){
    //         cout<< arr[colIndex][rowIndex]<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }

    // for(int i=0;i<rowSize;i++){
    //     cout<<arr[i][i]<<" ";
    // }

    return 0;
}