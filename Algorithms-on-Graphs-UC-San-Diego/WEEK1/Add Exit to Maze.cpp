#include <iostream>
#include <vector>
//A program to calculate how many connected components are there in a graph
using namespace std;
void Explore(int x, vector<vector<int> >& adj, vector<int>& visited)//Explore function same as the first problem
{
	visited[x] = 1;
	for (int w : adj[x])
	{
		if (visited[w] == 0) {
			Explore(w, adj, visited);
		}
	}

}

int DFS(vector<vector<int> >& adj) {

	vector<int> visited(adj.size());//declaring visited array to be passed as a parameter to the Explore function 
	int cc = 0;//initializing the counter 
	for (int i = 0; i < adj.size(); i++)
	{
		if (visited[i] == 0) {//if a vertex is not visited
			Explore(i, adj, visited);//we explore it
			//So it's in a different component
			cc++;//so we increment the counter by 1
		}

	}
	return cc;

}
//The main difference from that problem and the previous one
//That in the first one we only cared about the source vertix and it's array
//now we care about the whole graph to check if we reached a dead end for a vertex 
//Then this is the end of this component and we move to another vertex and check the same thing again
int main() {
	size_t n, m;
	cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	cout << DFS(adj);
}
