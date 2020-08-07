#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
pair<int, int> partition(vector<int>& a, int l, int r) {
	int x = a[l], m1;
	int j = l;
	for (int i = l + 1; i <= r; i++) {
		if (a[i] <= x) {
			j++;
			swap(a[i], a[j]);
		}
	}
	swap(a[l], a[j]);
	m1 = j - 1;
	for (int i = l; i < j && m1 >= l && m1 > i;)
	{
		if (a[j] == a[i])
			swap(a[i], a[m1--]);
		else
			i++;
	}
	m1++;
	return make_pair(m1, j);
}

void QuickSort(vector<int>& a, int l, int r) {
	if (l >= r) {
		return;
	}

	int k = l + rand() % (r - l + 1);
	swap(a[l], a[k]);
	pair<int, int> m = partition(a, l, r);

	QuickSort(a, l, m.first - 1);
	QuickSort(a, m.second + 1, r);
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < a.size(); ++i) {
		cin >> a[i];
	}
	QuickSort(a, 0, a.size() - 1);
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] << ' ';
	}
}