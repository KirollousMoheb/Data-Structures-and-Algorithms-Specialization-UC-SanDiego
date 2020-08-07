#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int major( vector<int> arr, int n) {
	int maj = arr[0];
	int counter = 1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == maj)
		{
			counter+=1;
		}
		else {
			counter-=1;
			if (counter == 0)
			{
				maj = arr[i];
				counter = 1;
			}
		}
	}

	if (counter + 1 > (n / 2))
	{
		return 1;
	}
	if (counter + 1 < (n / 2))
	{
		return 0;
	}


}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << major(arr, n);

}