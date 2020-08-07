#include <iostream>
#include <vector>
#include <string>
using namespace std;

//vector of structs
//vector func to  return vector
struct Query {   //Creating a data structure for each query entered by the user
	string type, name; //type of operation(add,del,find) and the name of contact
	int number;//the number of contact
};

vector<Query> read_queries() {//A function to read the input from the user with type vector to return a vector
	int n; //n is the first input entered by the user indicating the number of queries will be entered
	cin >> n;
	vector<Query> queries(n); //creating a vector of structures "Query" with n number
	for (int i = 0; i < n; ++i) {
		//the query is entered as this example (add 911 police)
		cin >> queries[i].type;//so the user enter the type of the query called from the structure by a pointer
		if (queries[i].type == "add") {//if the user enters add or Add 
			cin >> queries[i].number >> queries[i].name;//take the number and the name of the contact,We can also take the name first it doesn't matter 
		//but this's as mentioned in the assignment's Pdf
		}
		else {
			//otherwise for the del and find queries 
			cin >> queries[i].number;//we only need the number
		}
	}
	return queries;//return the vector of structures for each query
}

void write_responses(const vector<string>& result) {//A function to print the result of each query respictevly in the same order the user entered them
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] <<endl;//A result array
}


vector<string> Process(const vector<Query>& queries) {//The main function with type vector whose type is string as we will return the result
	vector<string> result;//A string array of results
	//Since from the constraint's in the Assignment's Pdf that the numbered enter by the user is at most have 7 digits
	//We can hash integers now by assigning the hash table's size to a number which is 
	//Prime and larger than 2 power L where L is the number of digits of the user's phone number
	const int Size = 10000019;//size of contact array
	vector<string> contacts(Size);//contacts string array

	for (int i = 0; i < queries.size(); ++i)//for loop iterate about the queries returned from the 'read_queries' function which is passed as a parameter
		if (queries[i].type == "add") {//if the type of each structure which is inside the vector parameter is add or Add
			//Instead of implementing a function that generates a hash key for each contact and that also will not be specified
			//We can use the contact's number to be the key 
			//Where the key here is the index where the user's name will be stored in the contact array
			contacts[queries[i].number] = queries[i].name;//So we add the name to the contact's array
		}
		else if (queries[i].type == "del") {
			contacts[queries[i].number] = "";// we delete the number 
		}
		else {
			if (contacts[queries[i].number] == "")
				result.push_back("not found");//push back the string statement not found in the hash doesn's have a number
			else
				result.push_back(contacts[queries[i].number]);
		}
		//---------------------------------Note----------------------------------------------
		//The user search for contacts by their number and we extract teh corresponding name and print it
		//So that's why in this case the Contacts vector is for storing names
		//We then wether update the name if the user entered the same number for another name in the same index
	    //since the index is equal to the number and it's the hash key
		//Or we delete a name existing in an index equal to the name's number
	    //Or we find a name by its number since  the number is the hash key
	return result;//return the result array which will be passed as a parameter for the write response function
}


int main() {
	//The 'write_responses' Function is responsible for printing out the output from the results vector
	//The result vector is passed into it as a parameter
	//We get the result vector from the function 'Process' where it's declared at the beginning of it
	//It takes a vector parameter containing all the queries structures which is returned from the 'read_queries' function
	//The 'read_queries' function is thr function responsible for taking the data from the user and storing each query in a structure and storing these structures into a vector
	//Which is then passed as a parameter for the 'Process' Function
	write_responses(Process(read_queries()));
	return 0;
}