#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarysearch(vector<int> array, int n, int key) {
	int mid;
	int low = 0;
	int high = n - 1;
	while (low<=high)
	{
		mid = low+ ((high - low) / 2);
		if (array[mid] == key)
		{
			return mid;
		}
		else if (key<array[mid]) {
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}


	}
	return -1;
}

void compare(vector<int> array, int n, vector<int>keys, int k) {
	for (int i = 0; i < k; i++)
	{
		cout << binarysearch(array , n, keys[i] )<<" ";
	}

}

int main() {
	int n;

	cin >> n;
	vector<int> elements(n);

	for (int i = 0; i < n; i++)
	{
		cin >> elements[i];
	}
	int k;

	cin >> k;
	vector <int> keys(k);

	for (int i = 0; i < k; i++)
	{
		cin >> keys[i];
	}

	compare(elements, n, keys, k);

}