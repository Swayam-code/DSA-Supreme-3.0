#include <iostream>
#include <unordered_map>
#include <list>
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
};

int main(){
    Graph g;
    //it should be 0 -indexed
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(1, 4, 0);
    g.addEdge(2, 5, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(4, 5, 0);
    //graph looks like this:
    // 0
    // | \
    // 1  2
    // |  |
    // 3  5
    // | /
    // 4
    
    int n = 6; // number of vertices in the graph
    // n should be the maximum vertex number + 1 if vertices are 0-indexed
    //print the adjacency list
    g.printAdjList(n);
    return 0;
}