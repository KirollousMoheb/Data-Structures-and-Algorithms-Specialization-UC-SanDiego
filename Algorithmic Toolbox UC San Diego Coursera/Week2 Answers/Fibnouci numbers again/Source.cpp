#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// since the fib numbers start always witha 0 and 1
long long int fib(int n) {
	vector <long long> nums(n + 1);//initialize an array with size n+1 where n is entered by the user which is the required fib number
	//we assign the first two elements of the array to 0 and 1 
	nums[0] = 0;//first element to 0
	nums[1] = 1;//second element to 1
	for (int i = 2; i <=n; i++)//a for loop starting from the third element
		//notice the for loop ends at n not n+1 
	
	{
		nums[i] = nums[i - 1] + nums[i - 2]; //assign the sum of the first two elements to the third element in the array
		//then the for loop counts again and assign the two elements before the 4th element to it and so on
	}
	return nums[n];//returning the required fib number from the array created
}

//I think the runtime is n


int main() {
	int n;
	cin >> n;
	cout << fib(n);
}