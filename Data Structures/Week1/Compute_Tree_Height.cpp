
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int root = 0;
int main()
{
	int nodesnumber; //declaring number of nodes
	cin >> nodesnumber; //get number of nodes from the user 
	vector< vector<int> >nodes(nodesnumber);
	queue<int>q;//queue named q
	vector <int> a (nodesnumber);//vector to store the nodes into

	//get the nodes in one line from the user
	//the second line contain numbers range from -1 to (number of nodes)-1
	for (int i = 0; i < nodesnumber; i++)
	{
		cin >> a[i];//get serial input of the nodes
		//if an element is equal to -1 assign its index to be the root at the top of the tree
		//It is guarentied in the Assignment PDF that there is one root node to be -1
		if(a[i] == -1) {
			root = i;
		}
		//otherwise push the element to 
		else {
			nodes[a[i]].push_back(i); //push each node's index in the input related to it's corresponding value in input vector into a multidimensional vector
		}
	}


	q.push(root);//push the root found to be -1 into a queue
	int height = 0;//declare and initialize the height
	while (true)
	{
		int nodecount = q.size();//get queue size 
		if (nodecount == 0) {//if number of nodes in the queue is equal zero we print the height
			cout << height << endl;
			return 0;
		}
		//otherwise we increment the height as we move to another node
		height += 1;
		while (nodecount > 0) {
			int node = q.front();//assign the next node in the queue to a variable named node

			//it means we are dequing every node after saving it 
			q.pop();//remove the assigned element above from the queue but it is still saved in node 
			if (!nodes[node].empty()) {
				for (int i = 0; i < nodes[node].size(); i++)
					q.push(nodes[node][i]);//enqueue the children of the previous dequeued node
			}
			nodecount--;
		}
	}
	return 0;
}