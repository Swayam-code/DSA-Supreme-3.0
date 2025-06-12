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
      unordered_map<int, list<pair<int,int>>>  adjList;

      void addEdge(int u, int v, int weight, bool direction) {
          // direction = 0 -> undirected graph
          // direction = 1 -> directed graph
          if (direction == 0) {
              adjList[u].push_back({v, weight});
              adjList[v].push_back({u, weight});
          }
          else{
              adjList[u].push_back({v, weight});
          }
      }      
      
      void topoSortDfs(int src, unordered_map<int,bool>& visited, stack<int>&s){
         visited[src] = true;

         for(auto neighbour : adjList[src]){
             if(!visited[neighbour.first]){
                 topoSortDfs(neighbour.first, visited, s);
             }
         }
         s.push(src);
      }

      void shortestPathDfs(int src){
            stack<int> topoOrder;
            unordered_map<int, bool> visited;
            unordered_map<int,int> parent;
            
            topoSortDfs(src, visited, topoOrder);

            //now I have topo order in stack s
            int n = adjList.size();
            vector<int> dist(n, INT_MAX);
            //initial state maintain

            src = topoOrder.top();
            topoOrder.pop();

            dist[src] = 0;
            parent[src] = -1; //to maintain the path
            //and src ke neighbours k min distance ko update karo
            for(auto nbr: adjList[src]){
                //nbr -> {a,b}
                //a-> node
                //b -> weight
                int node = nbr.first;
                int weightDist = nbr.second;
                if(dist[src] + weightDist < dist[node]){
                    dist[node] = dist[src] + weightDist;
                    parent[node] = src; //to maintain the path
                }
            }            
            
            //main logic -> topological ordering
            while(!topoOrder.empty()){
                int frontNode = topoOrder.top();
                topoOrder.pop();
                
                // Only process if this node is reachable (distance is not infinity)
                if(dist[frontNode] != INT_MAX) {
                    for(auto nbr: adjList[frontNode]){
                        //nbr -> {a,b}
                        //a-> node
                        //b -> weight
                        int node = nbr.first;
                        int weightDist = nbr.second;
                        if(dist[frontNode] + weightDist < dist[node]){
                            dist[node] = dist[frontNode] + weightDist;
                            parent[node] = frontNode; //to maintain the path
                        }
                    }
                }
            }

            cout << "Printing Distance Array" << endl;
            for(auto i: dist){
                cout << i << " ";
            }
            cout << endl;            
            
            int dest = 5;
            cout << "Path from " << src << " to " << dest << ": ";
            while (dest != -1){
                cout << dest;
                dest = parent[dest];
                if(dest != -1) cout << "<-";
            }
            cout << endl;
      }

};

int main(){
    Graph g;
    // g.addEdge(0, 1, 0);
    // g.addEdge(0, 2, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(2, 3, 0);  
    // g.addEdge(3, 4, 0);
    // g.addEdge(4, 5, 0);
    
    //this is a directed acyclic graph
    g.addEdge(0, 1, 5, 1);
    g.addEdge(0, 2, 3, 1);
    g.addEdge(1, 3, 6, 1);
    g.addEdge(1, 2, 2, 1);
    g.addEdge(2, 4, 4, 1);
    g.addEdge(3, 5, 1, 1);
    g.addEdge(4, 5, 2, 1);    
    
    //the graph looks like this (without weights):
    /*
        0
       / \
      v   v
      1-->2
      |  /|
      v v | 
      3   4 
       \ /
        v
        5
    */


    g.shortestPathDfs(0);

    return 0;

}