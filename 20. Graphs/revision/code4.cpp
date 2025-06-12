#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<stack>
#include<climits>
using namespace std;

class Graph {
    public :
      unordered_map<int, list<int>>  adjList;

      void addEdge(int u, int v, bool direction) {
          // direction = 0 -> undirected graph
          // direction = 1 -> directed graph
         
          if (direction == 0) {
              adjList[u].push_back(v);
              adjList[v].push_back(u);
          }
          else{
              adjList[u].push_back(v);
          }
      }

      void printAdjList(int n) {
          for (int i = 0; i < n; i++) {
              cout << i << " -> {";
              for (auto j : adjList[i]) {
                  cout << j;
              }
              cout << "}" << endl;
          }
      }

      //T.C. : O(V + E) 
      //S.C. : O(V) 
      void shortestPathBfs(int src, int dest) {
          unordered_map<int, int> parent;
          unordered_map<int, bool> visited;
          queue<int> q;

        // Initialize visited and parent maps
          q.push(src);
          visited[src] = true;
          parent[src] = -1;

          //main logic of BFS
          while (!q.empty()) {
              int front = q.front();
              q.pop();

              for (auto neighbour : adjList[front]) {
                  if (!visited[neighbour]) {
                      q.push(neighbour);
                      visited[neighbour] = true;
                      parent[neighbour] = front;
                  }
              }
          }

          // Print the path from src to dest
          vector<int> path;

          int node = dest;
          while(node != -1) {
              path.push_back(node);
              node = parent[node];
          }
          //reverse the path to get it from src to dest
          reverse(path.begin(), path.end());

          // Print the path
          cout << "Shortest path from " << src << " to " << dest << " is: ";
          for (auto p : path) {
              cout << p << " -> ";
          }
          cout << "end" << endl;
      }

};

int main(){
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);  
    g.addEdge(3, 4, 0);
    g.addEdge(4, 5, 0);
    //the graph looks like this:
    // 0 -- 1
    // |    |
    // 2 -- 3
    //      |
    //      4 -- 5

    int src = 0; 
    int dest = 3;
    g.shortestPathBfs(src,dest);
    
    return 0;

}