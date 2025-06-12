#include<iostream>
#include<vector>
using namespace std;

void wavePrintMatrix(vector<vector<int>>v){
    int m = v.size();
    int n = v[0].size();
     //for even no. of col --> we print top to bottom
     
     //for odd no. of col --> we print bottom to top
    for(int startCol = 0;startCol<n;startCol++){
        //even no. --> Top to bottom
        if((startCol& 1)==0){
            for(int i =0;i<m;i++){
                cout << v[i][startCol]<<" ";
            }
        }
        else{
            //odd no. --> Bottom to Top
            for(int i= m-1;i>=0;i--){
                cout<< v[i][startCol]<<" ";
            }
        }
    }
}

int main(){
    vector<vector<int>> v{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    int m = v.size();
    int n = v[0].size();
    
    for(int a =0;a<n;a++){
       for(int i = 0 ;i< m ;i++){
        cout << v[a][i] << " ";
       }
    }
    cout << endl;

    wavePrintMatrix(v);
    return 0;
}
