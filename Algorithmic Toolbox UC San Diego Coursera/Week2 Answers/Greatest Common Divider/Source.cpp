#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//greates common dividor
//the greatest number that can divide both elements  without remainder

int gcd(int a, int b) {

	if (b==0)//if b=0 then a can be divided by itself
	{
		return a; //so the gcd is a
	}
	//the gcd of a and b is the gcd of %a/b and b
	//but %a/b  is much smaller than a sp it will make the process faster
	//where we can call a'=%a/b
	else {
		return gcd(b, a % b);
	}
}



int main() {
	int a,b;
	cin >> a>>b;
	cout << gcd(a,b);
}