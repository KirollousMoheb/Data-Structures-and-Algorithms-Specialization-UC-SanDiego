//naive solution for maxpairwise Product
//the problem with the naive solution that it takes too much time
//as the runtime is directly proportional to n square of input
//due to the nested for loops
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long MaxPairwiseProduct(const vector<int>& numbers) {
    long long max_product = 0; //initialize the result with 0
    int n = numbers.size(); //get the input array's size

    //two for loops the first one is for the first element in the array
    //the second one is for the preceding element
    //if the multiplication of two adjacent elements in the array is bigger than the previous result
    //the answer is saved and the for loops count 
    //until we get out of the for loop with the maximum result
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (((long long )numbers[i])*numbers[j] > max_product)
            {
                max_product= ((long long)numbers[i]) * numbers[j];

            }
        }
    }

    return max_product;//return the result at the end of the function
}

int main() {
    int n;
    cin >> n;//size of the input array
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << MaxPairwiseProduct(numbers); << "\n";
    return 0;
}
