#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
bool negative_cycle(vector<vector<int> >& adj, vector<vector<int> >& cost) {
    vector<int>dist(adj.size(), 9999999999);
    dist[0] = 0;
    bool relax;
    for (int i = 0; i < adj.size(); i++)
    {
        relax = false;
        for (int u = 0; u < adj.size(); u++)
        {
            for (int v = 0; v < adj[u].size(); v++)
            {
                if ( dist[u] + cost[u][v] <  dist[adj[u][v]] )
                {
                     dist[adj[u][v]] =dist[u] + cost[u][v];
                     relax = true;
                }
            }
        }
    }

    return relax;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > cost(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    cout << negative_cycle(adj, cost);
}
