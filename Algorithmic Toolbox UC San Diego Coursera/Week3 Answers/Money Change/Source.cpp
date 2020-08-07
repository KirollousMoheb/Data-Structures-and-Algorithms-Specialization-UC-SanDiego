#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long int gcd(int a, int b) {

	if (b == 0)
	{
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}


long long int lcm(int a, int b) {
	
	if (a==0 && b==0)
	{
		return 0;
	}
	else {
		return ( (long long) a * b) /  (gcd(a, b)); //needed to add long to both
	}




}



int main() {
	int a,b;
	cin >> a>>b;
	cout << lcm(a,b);
}