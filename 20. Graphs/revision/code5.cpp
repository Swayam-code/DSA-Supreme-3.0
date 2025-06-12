#include <iostream>
#include <unordered_map>
#include<list>
#include <queue>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;

class Graph{
    public:
    // first int: u,
    // second int: v,
    // third int: wt
    unordered_map<int,list<pair<int,int> > >adjList;

    void addEdge(int u, int v, int weight, bool direction){
        // direction:1-> undirected graph(assumed, can take opposite also)
        // direction:0-> directed graph
        adjList[u].push_back({v,weight});
        if(direction==1){
            adjList[v].push_back({u,weight});
        }
    }

    void printAdjList(int n){
        for(int i = 0; i<n;i++){
            cout << i << ": ";
            cout << "{";
            list<pair<int,int> > temp = adjList[i];
            for(auto j:temp){
                // j is a pair here
                cout << "("<<j.first<<","<<j.second<<")";
            }
            cout << "}" << endl;
        }
    }

    void bellmanfordalgo(int src, int n){
        vector<int> dist(n, INT_MAX);

        //initial state
        dist[src] = 0;

        //n-1 times loop chalao
        for(int i=0; i<n-1; i++){
            //har edge pe jao aur relaxation perform karo
            for(auto edge: adjList){
                int u = edge.first; //source node
                for(auto neighbour: edge.second){
                    int v = neighbour.first; //destination node
                    int weight = neighbour.second; //weight of the edge

                    //if the distance to the destination can be minimized
                    if(dist[u] != INT_MAX && dist[u] + weight < dist[v]){
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }
        bool negativeCycle = false;
        //check for negative weight cycle
        
        //har edge pe jao aur relaxation perform karo
            for(auto edge: adjList){
                int u = edge.first; //source node
                for(auto neighbour: edge.second){
                    int v = neighbour.first; //destination node
                    int weight = neighbour.second; //weight of the edge

                    //if the distance to the destination can be minimized
                    if(dist[u] != INT_MAX && dist[u] + weight < dist[v]){
                        dist[v] = dist[u] + weight;
                        negativeCycle = true; //negative cycle detected
                        break;
                    }
                }
            }
        if(negativeCycle){
            cout << "Negative cycle detected!" << endl;
        } else {
            cout << "No negative cycle detected." << endl;
            cout << "Shortest distances from source node " << src << " are:" << endl;
            for(int i = 0; i < n; i++){
                cout << "Node " << i << ": " << dist[i] << endl;
            }
        }

    }

    void shortestDistanceDijkstra(int src, int n){
        vector<int> dist(n+1, INT_MAX);
        set<pair<int,int> > s; // {distance, node}

        //initial state
        dist[src] = 0;
        s.insert({0,src});

        //main logic
        while(!s.empty()){
            auto topElement = *(s.begin());
            int topNodeDistance = topElement.first;
            int topNode = topElement.second;

            //pop this node
            s.erase(s.begin());

            //visit all the neighbours of this node
            //nbr is a pair
            //nbr = {a,b}
            //a -> neighbour node
            //b -> edge weight
            for(auto neighbour: adjList[topNode]){
                int nbrNode = neighbour.first;
                int nbrDist = neighbour.second;

                //if the distance to the neighbour can be minimized
                if(dist[topNode] + nbrDist < dist[nbrNode]){
                    //distance array ko update karna hai
                    //set ko update karna hai
                    auto result = s.find({dist[nbrNode], nbrNode});
                    if(result != s.end()){
                        //if the node is already present in the set
                        s.erase(result);
                    }
                    dist[nbrNode] = dist[topNode] + nbrDist;
                    s.insert({dist[nbrNode], nbrNode});
                }
            }
        }

        cout << "Shortest distances from source node " << src << " are:" << endl;
        for(int i = 0; i < n; i++){
            cout << "Node " << i << ": " << dist[i] << endl;
        }
    }

    void floydWarshalAlgo(int n){
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        //step 1: Initialize the diagonal matrix with 0
        for(int i = 0; i < n; i++){
            dist[i][i] = 0;
        }

        //step2: copy all distances from graph to the matrix
        for(auto edge: adjList){
            int u = edge.first; //source node
            for(auto neighbour: edge.second){
                int v = neighbour.first; //destination node
                int weight = neighbour.second; //weight of the edge
                dist[u][v] = weight;
            }
        }

        //main logic
        for(int helper = 0; helper < n; helper++){
            for(int src = 0; src < n; src++){
                for(int dest = 0; dest < n; dest++){
                    //if the distance can be minimized
                    dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                }
            }
        }
        //print the distance matrix
        cout << "Shortest distances between all pairs of nodes by Floyd-Warshall algorithm:" << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][j] == 1e9){
                    cout << "INF ";
                } else {
                    cout << dist[i][j] << " ";
                }
            }
            cout << endl;
        }    
    }
};    

int main(){
    Graph g;
    
    //Dijkstra's algorithm
    // g.addEdge(0,5,9,1);
    // g.addEdge(0,3,6,1);
    // g.addEdge(5,4,2,1);
    // g.addEdge(4,3,11,1);
    // g.addEdge(5,1,14,1);
    // g.addEdge(4,1,9,1);
    // g.addEdge(4,2,10,1);
    // g.addEdge(3,2,15,1);
    // g.addEdge(2,1,7,1);

    //Bellman-Ford algorithm
    // g.addEdge(0,1,-1,0);
	// g.addEdge(1,4,2,0);
	// g.addEdge(0,2,4,0);
	// g.addEdge(3,2,5,0);
	// g.addEdge(4,3,-3,0);
	// g.addEdge(1,2,3,0);
	// g.addEdge(1,3,2,0);
	// g.addEdge(3,1,1,0);

    //-ve cycle case
    // g.addEdge(0,1,-1,0);
    // g.addEdge(1,0,-2,0);

    //floyd-warshall algorithm
    g.addEdge(0,2,-2,0);
    g.addEdge(1,0,4,0);
    g.addEdge(1,2,3,0);
    g.addEdge(3,1,-1,0);
    g.addEdge(2,3,2,0);

    // g.shortestDistanceDijkstra(0,6);
    // g.bellmanfordalgo(0,2);
    g.floydWarshalAlgo(4);

    return 0;
}