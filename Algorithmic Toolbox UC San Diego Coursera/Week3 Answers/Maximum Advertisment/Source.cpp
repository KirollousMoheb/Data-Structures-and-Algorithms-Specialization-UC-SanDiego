#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	long long sum = 0;
	long long n;
	cin >> n;
	vector<long long >profits(n);
	vector <long long> clicks(n);

	for (int i = 0; i < n; i++)
	{
		cin >> profits[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> clicks[i];
	}

	
		sort(profits.begin(), profits.end());
		sort(clicks.begin(), clicks.end());
		for (int i = 0; i < n; i++)
		{
			sum = sum + (profits[i] * clicks[i]);
		}
		cout << sum;
	

	

}