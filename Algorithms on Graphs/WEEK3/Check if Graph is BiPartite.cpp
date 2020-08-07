#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
//The program aims to check if a graph is bipartite or not
//And to check that we give a random node a color and the reachable adjacent nodes from it give them another color
//and from these adjacent reachable nodes we then give their reachable adjacent nodes a different color which is usually the first node's color at the start
//and so on so basically we have 2 colors and we give one of the node a color and continue altering it
//if at the end we found two adjacent nodes with the same color then the graph isnot bipartit
int bipartite(vector<vector<int> >& adj) {
    vector<int>color(adj.size());//stor the color for each node
    vector<int>visited(adj.size());//store which node is visited 

    for (int i = 0; i < adj.size(); i++)
    {
        //giving a max value to all the nodes to use it in if conditions if the node isnot marked visited nor colored
        //the value can be -1 also 
        color[i] = INT_MAX;
        visited[i] = INT_MAX;

    }
    //We have 2 colors 0 and 1
    color[0] = 0;//we assign the first node color 0
    queue<int> Q;//declare a queue to store the nodes into
    Q.push(0);//push this node to the queue
    visited[0] = 1;//mark the first node as visited
    while (!Q.empty())//while the queue containing unprocesssed nodes
    {
        int u = Q.front();//we save the top node into u
        Q.pop();//and remove it from the queue
        for (int v : adj[u])//for loop iterates about the reachable nodes
        {
            if (visited[v] == INT_MAX)//if the reachable nodes are not visited
            {
                Q.push(v);//we push it into the queue to be visited at the top of the while loop
                color[v] =1- color[u] ;//and give it an alternating color which is 1

            }
            if (color[v]==color[u])//if the parent node and the reachable adjacent node to it have the same color we return false
            {
                return false;
            }
        }
    }
    //else if we got out of the while loop with no returns
    //the nwe return true
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    cout << bipartite(adj);
}
