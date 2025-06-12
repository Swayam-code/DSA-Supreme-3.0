//--------WAVE PRINT A MATRIX--------
#include<iostream>
#include<vector>
using namespace std;

void wavePrintMatrix(vector<vector<int>> &matrix){
    int row = matrix.size();
    int col = matrix[0].size();

    for(int j=0; j<col; j++){
        if((j&1)== 0){
            // for even column, print from top to bottom
            for(int i=0; i<row; i++){
                cout<<matrix[i][j]<<" ";
            }
        }else{
            // for odd column, print from bottom to top
            for(int i=row-1; i>=0; i--){
                cout<<matrix[i][j]<<" ";
            }
        }
    }
}

int main (){
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    wavePrintMatrix(matrix);    
    cout<<endl;
    return 0;
}