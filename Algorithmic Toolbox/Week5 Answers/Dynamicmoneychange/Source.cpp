#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
int changes[3] = { 1,3,4 };
int number;
int Dynamicchange(int money) {
	vector<int>MinCoins(money + 1, INT_MAX);
	MinCoins[0] = 0;
	for (int m = 1; m <= money; m++)
	{

		for (int i = 0; i < 3; i++)
		{
			if (m >= changes[i])
			{
				number = MinCoins[m - changes[i]] + 1;
				if (number < MinCoins[m])
				{
					MinCoins[m] = number;
				}

			}

		}
	}
	return MinCoins[money];

}

int main() {
	int money;
	cin >> money;
	cout << Dynamicchange(money);



}
