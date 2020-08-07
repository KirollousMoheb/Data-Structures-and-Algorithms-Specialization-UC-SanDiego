#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long MaxPairwiseProduct(const vector<int>& numbers) {
    int n = numbers.size();
    int maxindex1 = -1;
    for (int  i = 0; i < n; i++)
    {

        if (maxindex1==-1 || numbers[i]>numbers[maxindex1])
        {
            maxindex1 = i;
        }
    }
    int maxindex2 = -1;
    for (int j = 0; j < n; j++)
    {

        if ((j!=maxindex1) && ((maxindex2 == -1) || (numbers[j] > numbers[maxindex2])))
        {
            maxindex2 = j;
        }
    }
    return ((long long)(numbers[maxindex1])) * numbers[maxindex2];

        }
int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
