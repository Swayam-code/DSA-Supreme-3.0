//RAT IN A MAZE PROBLEM
// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

    bool isSafe(int newx, int newy, vector<vector<int>>& m, vector<vector<bool>>& visited, int n){
        if(newx<0 || newy<0 || newx>= n|| newy >=n){
            //out of bound
            return false;
        }
        if(visited[newx][newy]==true){
            //already visited
            return false;
        }
        if(m[newx][newy] == 0){
            //blocked space
            return false;
        }
        //valid case
        return true;
    }
    
    void solve(vector<vector<int>>& m, vector<vector<bool>>& visited, int n, vector<string> &ans, int srcx, int srcy, int destx, int desty, string output){
        //base case
        if(srcx == destx && srcy == desty){
            ans.push_back(output);
            return;
        }
        
        int dx[] = {-1,1,0,0};
        int dy[]= {0,0,-1,1};
        char move[] = {'U','D','L','R'};
        for(int i = 0;i<4; i++){
            int newx = srcx + dx[i];
            int newy = srcy + dy[i];
            char movement = move[i];
            
             if(isSafe(newx, newy,m,visited , n)){
                visited[newx][newy] = true;
                solve(m,visited,n, ans,newx, newy, destx, desty, output + movement);
                //wapas aaunga - > visited - > revert
                //backtracking
                visited[newx][newy] = false;
             }
            
            
        }
        //1 case hum solve karnege -> rest recursion
        //UP
        // int newx = srcx-1;
        // int newy = srcy;
        // if(isSafe(newx, newy,m,visited , n)){
        //     visited[newx][newy] = true;
        //     solve(m,visited,n, ans,newx, newy, destx, desty, output + "U");
        //     //wapas aaunga - > visited - > revert
        //     //backtracking
        //     visited[newx][newy] = false;
        // }
        // //DOWN
        // newx = srcx+1;
        // newy = srcy;
        // if(isSafe(newx, newy,m,visited , n)){
        //     visited[newx][newy] = true;
        //     solve(m,visited,n, ans,newx, newy, destx, desty, output + "D");
        //     //wapas aaunga - > visited - > revert
        //     //backtracking
        //     visited[newx][newy] = false;
        // }
        
        // //LEFT 
        // newx = srcx;
        // newy = srcy-1;
        // if(isSafe(newx, newy,m,visited , n)){
        //     visited[newx][newy] = true;
        //     solve(m,visited,n, ans,newx, newy, destx, desty, output + "L");
        //     //wapas aaunga - > visited - > revert
        //     //backtracking
        //     visited[newx][newy] = false;
        // }
        // //RIGHT
        // newx = srcx;
        // newy = srcy+1;
        // if(isSafe(newx, newy,m,visited , n)){
        //     visited[newx][newy] = true;
        //     solve(m,visited,n, ans,newx, newy, destx, desty, output + "R");
        //     //wapas aaunga - > visited - > revert
        //     //backtracking
        //     visited[newx][newy] = false;
        // }
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        int n = maze.size();
        vector<vector<bool>> visited(n, vector<bool>(n,0));
        int srcx = 0;
        int srcy = 0;
        //main bhul gaya
        visited[0][0] =true;
        int destx = n-1;
        int desty = n-1;
        string output = "";
        
        //important case
        if(maze[0][0] == 0){
            //if starting position is blocked, then return empty
            return ans;
        }
        
        solve(maze, visited, n, ans, srcx, srcy, destx, desty, output);
        //lexographically sorted answer
        sort(ans.begin(), ans.end());

        return ans;
    }
int main(){
    vector<vector<int>> m = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 1, 1, 1}
    };
    vector<string> ans = ratInMaze(m);
    for(auto i: ans){
        cout<<i<<endl;
    }

    return 0;
}