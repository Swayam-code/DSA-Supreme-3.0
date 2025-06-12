#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Graph {
    public :
        unordered_map<int, list<int>> adjList;

        void addEdge(int u, int v, bool direction ) {
            //direction 0 -> undirected graph
            //direction 1 -> directed graph
            if(direction == 0) {
                // undirected graph
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            } else if(direction == 1) {
                // directed graph
                adjList[u].push_back(v);
            }
        }

        void printAdjList(int n){
            for(int i = 0; i < n; i++) {
                cout << i << " -> ";
                cout << " {";
                list<int> l = adjList[i];
                for(auto j : l) {
                    cout << j << ", ";
                }
                cout << "}" << endl;
            }
        }

        bool cycleDetectionUndirectedBFS(int src, unordered_map<int, bool>& visited) {
            queue <int> q;
            unordered_map<int, int> parent;
            // unordered_map<int, bool> visited;

            //initial state
            q.push(src);
            visited[src] = true;
            parent[src] = -1; // No parent for the source node

            //main logic
            while(!q.empty()){
                int front = q.front();
                q.pop();

                // Traverse all adjacent vertices
                for(auto neighbor : adjList[front]) {
                    if(!visited[neighbor]) {
                        visited[neighbor] = true;
                        parent[neighbor] = front;
                        q.push(neighbor);
                    } 
                    //cycle detection logic
                    // If the neighbor is visited and is not the parent of the current node, a cycle is detected
                    else if(visited[neighbor] && parent[front] != neighbor) {
                        return true;
                    }
                }
            }
            return false; // No cycle detected
        }
};

int main(){
    Graph g;
    //it should be 0 -indexed
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(1, 4, 0);
    g.addEdge(2, 5, 0);
    // g.addEdge(3, 4, 0);
    // g.addEdge(4, 5, 0);
    
    int n = 6; 
    g.printAdjList(n);

    // bool ans = false;
    unordered_map<int, bool> visited; 
      bool hasCycle = false;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            bool cycleDetected = g.cycleDetectionUndirectedBFS(i, visited);
            if(cycleDetected){
                cout << "Cycle detected in the graph." << endl;
                hasCycle = true;
                break;
            }
        }
    }
    // Only print "No cycle detected" if we didn't find any cycles
    if(!hasCycle) {
        cout << "No cycle detected in the graph." << endl;
    }
    return 0;
}