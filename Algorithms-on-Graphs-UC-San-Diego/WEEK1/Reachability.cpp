#include <iostream>
#include <vector>
using namespace std;
//A program to check if a vertix is reachable from another vertix both entered by the user
void Explore(int x,vector<vector<int> >& adj, vector<int>& visited )//Function to explore each vertex
{
	//int x is the source vertex from which we will mobe to our destination y
	//visited array to save 1 if a vertex is visited or 0 if not
	visited[x] = 1;//we start by the firt vertex and giving it a true value that it's explored,
	//this is also to assign a true value for other vertices once we get out of the for loop since we will call
	//this function recursively in the reach function
	for (int w: adj[x])//we ittereate about the row vector that exists in the adj 2D vector whose index is x
		//where x is the the vertix we concerned about to reach from it another vertix y entered by the user
		
	{
		if (visited[w] == 0) //if the next vertix in the row vector is not visited 
			Explore(w,adj, visited);//we explore it
	}

}

int reach(vector<vector<int> >& adj, int x, int y) {

	vector<int> visited(adj.size());//declaring the visited array to be passsed as a parameter to the Explore function
	Explore(x,adj, visited);
	return visited[y];//return the result of the destination vertix from the visited array


}

int main() {
	size_t n, m;
	cin >> n >> m;//n is the number of vertices,while m is the number of edges entered by the user
	vector<vector<int> > adj(n, vector<int>());//Multidimensional vector consists of "n" number of row vectors
	//input example
	//4 2 these are 4 vertices and 2 edges
	//since this program is about undirected graph 
	//therefor each edge can go in any way for exxample :
	//1 2  from 1 to 2 or from 2 to 1
	//3 2  same this is applied here
	//so the the adj 2D vector is for saving the reachable edges for each vertix

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		//if the input is 1 2
		//we push vertix to into the array of vertix 1
		//and we also push vertix 1 into the array of vertix 2
		//so that they can be reachable from each other
		//we subtract 1 from the vertices to make sure they are numbred from 0 as in the for loops
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	int x, y;
	cin >> x >> y;
	cout << reach(adj, x - 1, y - 1) << endl;
}
