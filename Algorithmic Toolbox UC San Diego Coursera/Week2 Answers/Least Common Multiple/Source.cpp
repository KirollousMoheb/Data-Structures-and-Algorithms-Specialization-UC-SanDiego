#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//lowest common multiple

long long int gcd(int a, int b) {
	//the greatest common divider function 

	if (b == 0)
	{
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}


long long int lcm(int a, int b) {
	//the least common multiple
	//is the smallest number divisble by two numbers 
	//for example 6 and 3 their gcd is 3
	//their product is 18
	//so 18/3=6 which is the smallest number divisble by 6 and 3
	
	if (a==0 && b==0)//if both numbers are zero there is no lcm
	{
		return 0;
	}
	else {
		return ( (long long) a * b) /  (gcd(a, b)); //not needed to add long to both
	}




}



int main() {
	int a,b;
	cin >> a>>b;
	cout << lcm(a,b);
}