//Topological Sort
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    void topoDfs(int src, unordered_map<int,bool>& vis, vector<vector<int>>& adj, vector<int> &ans){
        vis[src] = true;
        for(auto nbr: adj[src]){
            if(!vis[nbr]){
                topoDfs(nbr,vis, adj,ans);
            }
        }
        
        //backtrack
        ans.push_back(src);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        unordered_map<int,bool> visited;
        int n=V;
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                topoDfs(i, visited,adj,ans);
            }
        }
        
        //reverse the ordering
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

int main(){

    return 0;
}