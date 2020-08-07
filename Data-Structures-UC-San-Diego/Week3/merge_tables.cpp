#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
//The goal of this program is to implement disjoint sets datastructure and path compression concept
//The first line of input contains the number of tables and the number of queries the user want to perform on them
//the second line contain number of rows in each table(Size of table or tree)
//the preceding line contains the destination table and source table to be entered separated by spaces

//The goal is to print the size of the Resulting table from the merge queries entered by the user
struct DisjointSetsElement {
	//A structure to store the data of each table 
	//a strcture various information about something by declaring different variables in it for the element 
	//Instead of defining these variables multiple times for different elements
	int size, parent, rank;//declaring the size of the table ,its parent and its rank
	//by rank here we mean its height

	DisjointSetsElement(int size = 0, int parent = -1, int rank = 0) :
		size(size), parent(parent), rank(rank) {}
};

struct DisjointSets {
	int size;
	int max_table_size; //an int to store the output of the max size in
	vector <DisjointSetsElement> sets;

	DisjointSets(int size) : size(size), max_table_size(0), sets(size) {
		for (int i = 0; i < size; i++)
			sets[i].parent = i;
	}
	//get the parent of each table function by path compression
	//By path compression we means that going from the selected node if it's not the table's parent 
	//We move up until we find the table's parent
	//and on our way up we do the same for the nodes in our path and assign their parent too
	//Doing so we will have multiple nodes assigned to their table's parent so we won't have to do the same step each time we enter a query
	//To check if the queries have the same parent or not
	int getParent(int i) {//Where int i is the table

		if (i != sets[i].parent) {//if the selected node is not the parent
			sets[i].parent = getParent(sets[i].parent);//we call the function recursively to find the parent of this node
		}
		//Until we get the parent's index and return it
		return sets[i].parent;
	}


	void Update(int i_id, int j_id) {
		sets[i_id].size += sets[j_id].size;//updating the table after merging is done by adding the size of the tables to each other
		sets[j_id].size = 0;//and setting the other table's size to zero
		if (this->max_table_size < sets[i_id].size)
			this->max_table_size = sets[i_id].size;
	}

	void Union(int i, int j) {//int i and j are the two tables to be merged
		int i_id = getParent(i);//get the parent of the first table in the inputted query
		int j_id = getParent(j);//get the parent of the second table in the inputted query
		if (i_id == j_id)//if the two tables have the same id(parent)
		{
			return;//Do nothing as they are in the same table
		}
		if (i_id != j_id) {//if the two tables doesn't have the same parent

			if (sets[j_id].rank > sets[i_id].rank) {//if the height (rank) of the second tree is larger than the first
				//since the tree with larger height will be the Parent of the two trees as discussed in class
				//And that's because by that we decrease the depth(rank) or height of the resulting tree or table
				//to reduce the run time of merging as it is O(Tree Height)
				//So if the condition is met and the second tree have larger rank
				sets[i_id].parent = sets[j_id].parent;//we assign the first tree's parent to be as of the Secpnd tree
				int temp = j_id;//store parent of second tree in a temporarly variable
				j_id = i_id;//assign the first tree's parent to the second tree
				i_id = temp;
			}
			else
			{
				//else we do the opposite if it's the other way around
				sets[j_id].parent = sets[i_id].parent;
				//But if both trees(Tables) have the same rank it doesn't matter so we move any of them to the other
				if (sets[j_id].rank == sets[i_id].rank)
				{
					sets[i_id].rank++;//increase the rank of the parent's resulting tree by one
				}
			}
			Update(i_id, j_id);//and we update our Resulting table
		}
	}
};

int main() {
	int n, m;
	cin >> n >> m;//n is the number of tables in the database and m is the number of queries to be done 

	DisjointSets tables(n); //initializing dusjointsets structure to tables entered by the user whose number is n
	for (auto& table : tables.sets) { //auto for loop as in Javascript's For of loop
		//Going through the tables number decided by the user
		cin >> table.size;//And accesing the structure size's property to define number of rows in each table
		tables.max_table_size = max(tables.max_table_size, table.size);
	}

	vector<int> destinations(m), sources(m);//declaring two vectors to store the destination and source queries in the respectively

	for (int i = 0; i < m; i++) {

		cin >> destinations[i] >> sources[i];//input the merge queries as in union(2,3)
		//which means to the second and the third table
		--destinations[i];
		--sources[i];
	}
	for (int i = 0; i < m; i++) {

		tables.Union(destinations[i], sources[i]);//using the merge function to merge the two tables by extracting the queries from the destination and sources vectors
		cout << tables.max_table_size << endl; //Printing the maximum size of each table corresponding to each query
	}

	return 0;
}