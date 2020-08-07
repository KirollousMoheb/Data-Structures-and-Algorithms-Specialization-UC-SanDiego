#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
//A program to calculate the shortest path from a given node to another in a Directed Graph
using namespace std;
long long int distance(vector <vector<int> >& adj, vector<vector<int> >& cost, int s, int t) {//s is the source node we travel from,t is the destination
    vector<long long int> dist(adj.size(), INT_MAX);//A vector to store the distances from the source and giving them maximum distance which is updated later
    dist[s] = 0;//the distance for the source node is zero

    //the commented below lines from stackoverflow to make the run time for extraction from the queue smaller
    //use it if you got a runtime exceeded problem during assignment submission
    //auto cmp = [](pair<int, long long int> left, pair<int, long long int> right) { return (((left.second) > (right.second)) || (((left.second) == (right.second)) && ((left.first) > (right.first)))); };
    //priority_queue<pair<int, long long int>,vector<pair<int, long long int>>, decltype(cmp)> Q(cmp);
    //--------------------------------------------------------------------------------------------------------------/

    //A priprity queue to store each node and it's corresponding distance from the source
    priority_queue < pair<int, long long int>Q;
    Q.push(make_pair(s, dist[s]));//pushes the first pair which is the source node and it's distance which is equal to zero
    while (!Q.empty())//while the queue is not empty we do the following
    {
        int u=Q.top().first;//we assign the top node in the queue to variable 'u'
        Q.pop();//and we remove this node from the queue
        for (int i = 0; i < adj[u].size(); i++)//then we itterate about the reachable nodes from node 'u' which is at the beginning is node s then updated
        {
            if (dist[adj[u][i]]>dist[u]+cost[u][i])//if the distance of a reachable node from u is larger than the cost plus the 'u' node's distance
                //notice that the distance will always be larger as they are all assigned to a maximum number
                //and the goal of this is to update the distance of each reachable node from 's' or 'u'
            {
                //then this means that this path is better to take as it's cost isn't expensive as the current distance
                dist[adj[u][i]] = dist[u] + cost[u][i];//so we assign this node a new distance
                Q.push(make_pair(adj[u][i], dist[adj[u][i]]));//and we push the node and its distance in a pair into the priority queue
            }
        }

    }
    if (dist[t]<INT_MAX)//if the distance of the distination is smaller tha the max number 
    {
        //then this node is reachable and we return it's distance
        return dist[t];
    }
    else//if it's unreachable
    {
        return -1;//we return -1 as mentioned in the assignment pdf
    }
}
//Input example for more explanation
//4 4    //4 nodes and 4 edges
//1 2 1  //A directed edge from 1 to 2 with cost 2
//4 1 2  //from 4 to 1 with cost 1
//2 3 2  // from 2 to 3 with cost 2 and so on
//1 3 5

//1 3 the source is 1 and 't' or the distanation is 3

//the resulting arrays from the input
//adj{[1][2][][0]}
//for  0  1  2 3   //which are the 4 nodes numbered from 0 to 3 and above are the row vectors in the 2D vector containing the reachable nodes for each node

//dist[max,max,max,max]
//since the source node is 0
//so the distance will be updated to be [0,max,max,max]
//and it's added to the priority queue in pairs (node,dist) to be (0,0)
//then going into the for loop to go through the adj[0] items which is in this case 1
//since the distance of 1 is max then the if condition is satisified
//and we update the distance of node 1 to be the distane  of node 0+the corresponding cost in the cost array
//and so on until the queue is empty
//notice in this input example we will not process node 3 as it's not reachable from the source node
//and the queue will be empty and we break the while loop



int main() {
    int n, m;//n is number of nodes ,m is number of edges
    cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > cost(n, vector<int>());//store the costs
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    int s, t;
    cin >> s >> t;
    s--, t--;
    cout << distance(adj, cost, s, t);
}
