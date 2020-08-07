#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int knapsack(int weight,int n,const vector<int>& wi) {
	vector<vector<int>> value ((weight + 1), vector<int>(n + 1));
	int val;

	for (int i = 0; i < weight+1; i++)
	{
		value[i][0] = 0;
	}

	for (int j = 0; j < n+1; j++)
	{
		value[0][j] = 0;

	}

	for (int i = 1; i < n+1; i++)
	{
		for (int w = 1; w < weight+1; w++)
		{
			int val1= value[w][i - 1];
			int val2 = 0;
			if (w >= wi[i - 1]) { 
				val2 = value[w - wi[i - 1]] [i - 1] + wi[i - 1];
			}
			if (val1 > val2)
			{
				value[w][i] = val1;
			}
			else
			{
				value[w][i] = val2;
			}
		}

	}

	return value[weight][n];
}

int main() {
	int weight, n;
	cin >> weight >> n;
	vector<int> barsw(n);

	for (int i = 0; i < n; i++)
	{
		cin >> barsw[i];
	}
	cout <<knapsack(weight,n, barsw)<<" ";


}