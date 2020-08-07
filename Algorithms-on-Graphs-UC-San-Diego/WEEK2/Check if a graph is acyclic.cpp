#include <iostream>
#include <vector>
//A program to check if there are no cycles in a directed graph(acyclic) and return 1 if it's acyclic and return 0 otherwise
using namespace std;
bool Explore(int x, vector<vector<int> >& adj,vector<int>& visited, vector<int>& record)
{
    visited[x] = 1;//starting by the first node and giving a true valus so that it's visited
    record[x] = 1;//a record vector to store if there is any cycles
    for (int w : adj[x])//going through the reachable vertices from the first node
    {
        if (visited[w] != 1 && Explore(w, adj, visited, record) == false) {//if they arenot visited nor explored return false
            return false;
        }
        else
        {
            if (record[w]==1)
            {
                return false;
            }
        }

    }

    //if we already explored and visited a noed and passed by it again then there is a cycle and return true which is then passed in the acyclic function to return false from it
    record[x] = 0;
    return true;

}

int acyclic(vector<vector<int> >& adj) {
    vector<int> visited(adj.size());//store the visited vertices 1 for visited and 0 otherwise
    vector<int> record(adj.size());

    for (int i = 0; i < adj.size(); i++)//going through the vertices in the visited array 
    {
        if (visited[i]==0)//if one isnot visited
        {
            if (Explore(i,adj,visited,record)==false)//explore it if it's not explored
            {
                return 1;//return true
            }
        }
    }

    return 0;//else return 0 if the above condition isn't met
}

int main() {
    size_t n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
    cout << acyclic(adj);
}
//Input example
//4 4 
//1 2 
//4 1
//2 3
//3 1

 //adj{[1][2][0][0}
//nodes 0  1  2  3

//visited and record arrays output by steps
//visited[0,0,0,0]
//visited[1,0,0,0]
//visited[1,1,1,0]
