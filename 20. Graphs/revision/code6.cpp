#include <iostream>
#include <unordered_map>
#include<list>
#include <queue>
#include <algorithm>
#include <climits>
#include <set>
#include <stack>
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

        void topoSortDfs(stack<int> &s, unordered_map<int, bool> &visited, int node) {
            visited[node] = true;
            for(auto neighbour : adjList[node]) {
                if(!visited[neighbour]) {
                    topoSortDfs(s, visited, neighbour);
                }
            }
            //backtrack
            s.push(node); // push the node after visiting all its neighbours
        }

        void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjNew) {
            visited[node] = true;
            cout << node << " "; // print the node or perform any operation
            for(auto neighbour : adjNew[node]) {
                if(!visited[neighbour]) {
                    dfs(neighbour, visited, adjNew);
                }
            }
        }

        //TC : O(V + E)
        //SC : O(V)
        int countSCC(int n){
            stack<int> s;
            unordered_map<int, bool> visited;
            for(int i = 0; i < n; i++) {
                if(!visited[i]) {
                    topoSortDfs(s, visited, i);
                }
            }
            //yaha stack mai topological order ready hai

            //step 2: reverse all the edges
            unordered_map<int, list<int>> adjNew;
            for(auto edge : adjList) {
                int u = edge.first; // source node
                for(auto neighbour : edge.second) {
                    int v = neighbour; // destination node
                    adjNew[v].push_back(u); // reverse the edge
                }
            }

            //traversal
            int count = 0;
            unordered_map<int, bool> visitedNew;

            while(!s.empty()) {
                int node = s.top();
                s.pop();

                if(!visitedNew[node]) {
                    //perform dfs on the reversed graph
                    cout << "SCC :" ;
                    dfs(node, visitedNew, adjNew);
                    //ek pura component mil gaya
                    cout << endl;
                    count++;
                }
            }
            return count;
        }

        void countBridges(int src, int parent, vector<int>&tin, vector<int>&low, unordered_map<int,bool>&vis, int timer){

            timer++;
            vis[src] = true;
            tin[src] = timer;
            low[src] = timer;

            //travel through all the neighbours
            for(auto neighbour : adjList[src]) {
                //undirected graph hai, toh nbr toh parent bhi ho skta hai
                if(neighbour == parent) {
                    continue; // skip the parent node
                }
                else if(!vis[neighbour]) {
                    //if the neighbour is not visited
                    countBridges(neighbour, src, tin, low, vis, timer);
                    //ye main bhul jaata hun
                    low[src] = min(low[src], low[neighbour]); // update low value

                    //check if the edge is a bridge
                    if(low[neighbour] > tin[src]) {
                        cout << "Bridge found: " << src << " - " << neighbour << endl;
                    }
                } else {
                    //if the neighbour is already visited and is not the parent
                    low[src] = min(low[src], low[neighbour]); // update low value
                }
            }

        }
};

int main(){
    Graph g;
    // g.addEdge(0,3,1);
    // g.addEdge(3,2,1);
    // g.addEdge(2,1,1);
    // g.addEdge(1,0,1);
    // g.addEdge(2,4,1);
    // g.addEdge(4,5,1);
    // g.addEdge(5,6,1);
    // g.addEdge(6,4,1);
    // g.addEdge(6,7,1);

    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(0,2,0);
    g.addEdge(1,3,0);
    g.addEdge(3,4,0);
    int n = 5; // number of vertices in the graph

    g.printAdjList(n);

    int timer = 0;
    int src = 0; // starting node for bridge finding
    vector<int> tin(n, -1); // time of entry for each node
    vector<int> low(n, -1); // lowest time reachable from each node
    unordered_map<int, bool> vis; // visited nodes

    g.countBridges(src, -1, tin, low, vis, timer);

    
    //stack mai topological order ready hai

    int sccCount = g.countSCC(n);
    cout << "Number of strongly connected components: " << sccCount << endl;

    return 0;
}