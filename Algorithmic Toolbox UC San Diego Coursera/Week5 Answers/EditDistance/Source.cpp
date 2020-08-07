#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
using namespace std;
int EditDistance(int m,int n,const string & input1, const string& input2) {

	vector<vector<int>> D((m+ 1),vector<int>(n + 1));
	for (int i = 0; i < m+1; i++)
	{
		D[i][0] = i;
	}
	for (int j = 0; j < n+1; j++)
	{
		D[0][j] = j;

	}
	for (int i = 1; i < m+1; i++)
	{

		for (int j = 1; j < n+1; j++)
		{

			int insertion = D[i][j - 1] + 1;
			int deletion = D[i - 1][j] + 1;
			int match = D[i - 1][j - 1];
			int missmatch = D[i - 1][j - 1] +1;

			if (input1[i-1]==input2[j-1])
			{
				D[i][j] = min(min(insertion, deletion), match);
			}
			else {
				D[i][j] = min(min(insertion, deletion), missmatch);

			}



		}
	}
	return D[m][n];

}





int main() {
	string input1;
	string input2;

	cin >> input1>> input2;
	int m = input1.length();
	int n = input2.length();

	cout << EditDistance(m,n,input1, input2);


}