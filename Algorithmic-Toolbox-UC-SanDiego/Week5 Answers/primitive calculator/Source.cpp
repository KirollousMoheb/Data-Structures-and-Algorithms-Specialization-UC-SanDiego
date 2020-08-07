#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> optimal_sequence_dp(int n) {

	vector<int> min_ops(n + 1);
	min_ops [0] = 0;
	min_ops[1] = 0;

	vector<int> best_parent(n + 1); 
	best_parent[0] = 0;
	best_parent[1] = 0;

	for (size_t i = 2; i <= n; i++)
	{
		int Num_ops;


		Num_ops = min_ops[i - 1] + 1;
		min_ops[i] = Num_ops;
		best_parent[i] = int(i - 1);

		if (i % 3 == 0) {
			Num_ops = min_ops[int(i / 3)] + 1;
			if (Num_ops < min_ops[i]) {
				min_ops[i] = Num_ops;
				best_parent[i] = int(i / 3);
			}

		}

		if (i % 2 == 0) {
			Num_ops = min_ops[int(i / 2)] + 1;
			if (Num_ops < min_ops[i]) {
				min_ops[i] = Num_ops;
				best_parent[i] = int(i / 2);
			}
		}

	}

	vector<int> sequence;
	sequence.push_back(n);
	int idx = n;
	while (best_parent[idx] > 0)
	{
		sequence.push_back(best_parent[idx]);
		idx = best_parent[idx];
	}

	reverse(sequence.begin(), sequence.end());

	return sequence;
}

int main() {
	int n;
	cin >> n;
	vector<int> sequence = optimal_sequence_dp(n);
	cout << sequence.size() - 1 << endl;
	for (int i = 0; i < sequence.size(); ++i) {
		cout << sequence[i] << " ";
	}
}