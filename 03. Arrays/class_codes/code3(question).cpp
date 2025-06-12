#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

void columnWiseSum(int arr[][4],int rowSize, int colSize){
    for(int j=0;j<colSize;j++){
        int sum=0;
        for(int i=0;i<rowSize;i++){
            sum += arr[i][j];
        }
        cout<<sum<<endl;
    }
}

void diagonalSum(int arr[][3],int rowSize,int colSize){
    int sum=0;
    for(int i=0;i<rowSize;i++){
        sum += arr[i][i];
    }
    cout<<"sum :"<<sum<<endl;
}

int findMaximum(int arr[][4],int rowSize, int colSize){
    int maxValue= INT_MIN;
    for(int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++){
            maxValue= max(arr[i][j],maxValue);
        }
    }
    return maxValue;
}

int findMinimum(int arr[][4],int rowSize, int colSize){
    int minValue= INT_MAX;
    for(int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++){
            minValue= min(arr[i][j],minValue);
        }
    }
    return minValue;
}

void rowWiseSum(int arr[][4],int rowSize, int colSize){
    for(int i=0;i<rowSize;i++){
        int sum=0;
        for(int j=0;j<colSize;j++){
            sum +=arr[i][j];
        }
        cout<< sum<< endl;
    }
}

bool search2DArray(int arr[][4], int rowSize, int colSize, int target){
    for(int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++){
            if(arr[i][j]== target){
                return true;
            }
        }
    }
    return false;
}

bool search2DArray2(vector<vector<int>>arr, int target){
    int rowSize= arr.size();
    int colSize= arr[0].size();
    
    for(int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++){
            if(arr[i][j]== target){
                return true;
            }
        }
    }
    return false;
}

void transposeMatrix(int arr[][3], int rowSize, int colSize){
    int ans[100][100]={0};
    for(int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++){
            ans[i][j]= arr[j][i];
        }
    }

    for(int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

void transposeMatrix2(int arr[][3], int rowSize, int colSize){
    for(int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }

    for(int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    // int arr[3][4]={{70,20,30,40},
    //                 {40,90,80,20},
    //                 {20,40,60,30}};
    // int rowSize= 3;
    // int colSize=4;

    int arr[3][3]={{10,20,30},
                   {20,80,20},
                   {20,40,30}};
    int rowSize=3;
    int colSize=3;

    // transposeMatrix(arr,rowSize,colSize);
    cout<<endl;
    transposeMatrix2(arr,rowSize,colSize);


    // vector<vector<int>> arr(4, vector<int>(3,0));
    // int rowSize= arr.size();
    // int colSize= arr[0].size();

    // for(int i=0;i<rowSize;i++){
    //     for(int j=0;j<colSize;j++){
    //         cin>>arr[i][j];
    //     }
    //     cout<<endl;
    // }
    // int target=40;
    // bool ans= search2DArray2(arr, target);
    // cout<<ans<<endl;
    
    
    // int target=40;
    // bool ans = search2DArray(arr,rowSize,colSize,target);

    // cout<<ans<<endl;

    // rowWiseSum(arr,rowSize,colSize);

    // int ans= findMaximum(arr,rowSize,colSize);
    // cout<<ans<<endl;
    // diagonalSum(arr,rowSize,colSize);
    // columnWiseSum(arr,rowSize,colSize);
    
    return 0;
}