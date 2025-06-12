#include <iostream>
#include <unordered_map>
#include <list>
#include<queue>
using namespace std;

class Graph {
    public :
        //first int -> u (source vertex)
        //second int -> v (destination vertex)
        //third int -> weight of the edge
        unordered_map<int, list<pair<int,int>>> adjList;

        //TC : O(1)
        //SC : O(1)
        void addEdge(int u, int v, int weight, bool direction ) {
            //direction 0 -> undirected graph
            //direction 1 -> directed graph
            if(direction == 0) {
                // undirected graph
                adjList[u].push_back({v, weight});
                adjList[v].push_back({u, weight});
            } else if(direction == 1) {
                // directed graph
                adjList[u].push_back({v, weight});
            }
        }

        //TC : O(V + E)
        //SC : O(V + E) for the adjacency list
        void printAdjList(int n){
            for(int i = 0; i < n; i++) {
                cout << i << " -> ";
                cout << " {";
                list<pair<int,int>> l = adjList[i];
                for(auto j : l) {
                    cout << "(" << j.first << ", " << j.second << "), ";
                }
                cout << "}" << endl;
            }
        }        
        
        //TC : O(V + E)
        //SC : O(V + E) for the visited map and queue
        void bfsTraversal(int src) {
            // BFS traversal from source vertex src
            cout << "BFS traversal from vertex " << src << endl;
            queue<int> q;
            unordered_map<int, bool> visited;

            //initialize the queue with the source vertex
            q.push(src);
            visited[src] = true;

            while(!q.empty()) {
                int front = q.front();
                q.pop();
                cout << front << ", ";

                // Traverse all adjacent vertices
                for(auto neighbor : adjList[front]) {
                    //neighbor -> pair
                    //first -> node
                    //second -> weight
                    int node = neighbor.first;
                    int weight = neighbor.second;
                    if(!visited[node]) {
                        visited[node] = true;
                        q.push(node);
                    }
                }
            }
        }

        // Helper function for DFS traversal
        void dfsHelper(int node, unordered_map<int, bool>& visited) {
            // Mark the current node as visited
            visited[node] = true;
            cout << node << ", ";

            // Traverse all adjacent vertices
            for(auto neighbor : adjList[node]) {
                int nextNode = neighbor.first;
                if(!visited[nextNode]) {
                    dfsHelper(nextNode, visited);
                }
            }
        }  
                
        // TC : O(V + E)
        // SC : O(V) for the visited map
        void dfsTraversal(int n){
            cout << "DFS traversal covering all vertices:" << endl;
            unordered_map<int,bool> visited;
            for(int src = 0; src < n; src++) {
                if(!visited[src]) {
                    if(src > 0) cout << " | "; // Separator for disconnected components
                    dfsHelper(src, visited);
                }
            }
        }
};

int main(){
    Graph g;
    //it should be 0 -indexed
    g.addEdge(0, 1, 10, 0);
    g.addEdge(0, 2, 20, 0);
    g.addEdge(1, 3, 30, 0);
    g.addEdge(1, 4, 40, 0);
    g.addEdge(2, 5, 50, 0);
    g.addEdge(3, 4, 60, 0);
    g.addEdge(4, 5, 70, 0);

    // number of vertices in the graph
    int n = 6; 

    // n should be the maximum vertex number + 1 if vertices are 0-indexed

    //print the adjacency list
    g.printAdjList(n);
    cout << "------------------------" << endl;   
     // Perform BFS traversal from vertex 0
    g.bfsTraversal(0);
    // bfs traversal from vertex 0 should print:
    // 0, 1, 2, 3, 4, 5,
    
    cout << "\n------------------------" << endl;
    // Perform DFS traversal covering all vertices
    g.dfsTraversal(n);
    // dfs traversal from vertex 0 should print:
    // 0, 1, 3, 4, 5, 2,

    return 0;
}