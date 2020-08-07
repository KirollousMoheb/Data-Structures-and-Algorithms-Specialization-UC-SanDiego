#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//The goal of this program is to arrange the vertices in Topological order
//And what is meant by that is to arrange the vertices in an order where :
//The vertices that doesn't depend on other vertices is in the begining
//In another meaning the vertices which there is no other vertices pointing at it
//Consider the following input example we will discuss the code on it
//4 3  4 vertices and 3 edges
//The following 3 lines are the edges in directed graoh
//1 2 from vertix 1 to 2
//4 1 from 4 to 1
//3 1 and from 3 to 1

//To make things easier to understand I will write the edges input again but subtracting 1 from the vertices
//As this is the indexing of the for loops etc,..
//0 1
//3 1
//2 1
//These are the three edges of 4 vertices numbered from 0 to 3


vector<int> toposort(vector<vector<int> > adj) {//The main function to sort the graph
    vector<int>visited(adj.size());//visited array of size adj.size which is = n-1 which is number of vertices
    //to indicate if the vertix is visited or not
    vector<int> order;//The array to store the output
    for (int i = 0; i < adj.size(); i++)//for loop goes from 0 to n-1 where n is the number of vertices
    {
        if (visited[i]==0)//if the corresponding index to the vertix in the visited array=0
        {
            Explore(i, adj, visited,order);//we explore this vertix 

        }
    }
    //at the end we reverse the ordere array and return it
    //We will understand why we reverse it in the Explore function
    reverse(order.begin(), order.end());
    return order;
}
void Explore(int x, vector<vector<int> >& adj, vector<int>& visited, vector<int>& order)//Function to explore each vertex
{
    //Based on the example mentioned at the beginning
    //The arrays for each vertex will be as following
        //adj[0]=[1]
        //adj[1]=[]
        //adj[2]=[0]
        //adj[3]=[0]
    //Starting from vertex 0 we will assign 1 to it's index in visited array to mark it as visited
    visited[x] = 1;
    for (int w : adj[x])//Then we go through it's array to visit the vertices reachable from it

    {
        if (visited[w] == 0)//if these vertices are not visited we explore them recursively
            Explore(w, adj, visited, order);//so here from vertix 0 we will pass w=1 as it's the first element
        //in the array of vertix 0 adj[0]=[1]
        //since there are no more reachable vertices from vertix 0 we go out of the for loop
    }
    order.push_back(x);//and push back the last reachable vertix into order
    //doing this over and over until all the vertices are visited 
    //We will have a postorder stored in the order array
    //We can just reverse it to get the topological order
    //As the postorder traversal pushes the vertix when it can't reach no more vertices
    //Which is exactly opposite to the topological order
    //Where the topological order gets the vertices that can't be reached
    //The postorder get the vertices that's lastly reached
}

int main() {
    size_t n, m;
    cin >> n >> m;//n vertices and m edges
    vector<vector<int> > adj(n, vector<int>());//2D vector consists of n number of row vectors
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
    //since the "toposort" function returns a vector
    vector<int> order = toposort(adj);//we equate it to vector order to print it
    for (size_t i = 0; i < order.size(); i++) {
        cout << order[i] + 1 << " ";//since we subtracted 1 from the vertices to be numbered from 0 to n
        //we will increment each output from the order array by 1
    }
}
