#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
//The program calculate the distance between two vertices in an undirected graph using Breadth first search
int distance(vector<vector<int> >& adj, int s, int t) {//s is the source vertix and t is the destination
    vector<int>dist(adj.size());//a vector to store the distance for each corrsponding vertix according to the array's index
    for (int i = 0; i < adj.size(); i++)
    {
        dist[i] = INT_MAX;//Initializing a maximum distance for all the vertices which will be changed if the vertix is reachable
    }
    dist[s] = 0;//initializing the source vertix to be of distance(level) zero
    queue<int> Q;//A queue datastructure first in first out to store the discovered vertices
    Q.push(s);//Initializing the queue with the origin(source) vertix

    //The queue is empty when all the vertices are processed
    while (!Q.empty())//while they are not
    {
        int u = Q.front();//we get the vertix to be processed from the queue
        Q.pop();//and remove it from it
        for (int v : adj[u])//for loop itterate about the vertices reachable from vertix u extracted from the queue
            //all these vertices are present in the row vector corresponding to this vertix present in the 2D vector "adj"
        {
            if (dist[v]==INT_MAX)//if we didn't update the distance
            {
                Q.push(v);//push this vertix into the queue
                dist[v] = dist[u] + 1;//and increment the parent's vertix distance by 1 and assign this value to the new vertix reached from vertix 'u'
                //which in the start if it's the origin with distance 0 then will be 1

            }
            //after we have updated the distance of all the vertices of the origin vertix
            //we will go again to the top of the while loop and store one of these level 1 vertices into 'u' and start all over again
            //it doesn't matter which vertix is poped out and stored in 'u' as they will be of the same level
        }
    }
    if (dist[t]==INT_MAX)//if the distance is maximum then there is no path to the "t" vertix
    {
        return -1;
    }
    else
    {
        return dist[t];//return corresponding distance for vertex t(destiation)
    }
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
    int s, t;
    cin >> s >> t;
    s--, t--;
    cout << distance(adj, s, t);
}
