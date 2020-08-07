#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class HeapBuilder {
private:
    vector<int> data;//dynamic array to store the user's data into
    vector< pair<int, int> > swaps;

    void WriteResponse() const {
        cout << swaps.size() << "\n";
        for (int i = 0; i < swaps.size(); ++i) {
            cout << swaps[i].first << " " << swaps[i].second << "\n";
        }
    }

    void ReadData() {  //Function to read data from the user
        int n;
        cin >> n;//number of elements to be entered
        data.resize(n);
        for (int i = 0; i < n; ++i)//Input our tree elements
            cin >> data[i];
    }

    int Parents(int i) {
        return int((i + 1) / 2); //general formula for index of parents in the tree
    }
    int LeftChild(int i) {
        return 2*i + 1;     //general formula for any left child in the tree
    }
    int RightChild(int i) {
        return 2 * i + 2;   //general formula for any right child in the tree
    }
    void SiftDown(int i) {
        int minIndex = i;
        int Left = LeftChild(i); //get the index of the left child and store it in Left
        //Check if the current index has a left child in the first condition
        //Check if the Left child is smaller than it's parent
        if ( Left < data.size()  &&  data[Left] < data[minIndex] )
        {
            //if conditions is met
            //the left child is assigned the minimum index
            minIndex = Left;
        }
        //Moving to Dealing with right childs
        int Right = RightChild(i);//get the right child index for i and store it in Right
        //same thing as with left child
        if ( Right < data.size() && data[Right]<data[minIndex])
        {
            minIndex = Right;

        }
        //if the current index is not the minimum index
        if (i!= minIndex)
        {
            //we swap the current active index's value with the value of the minimum index met in the if conditions above
            swap(data[i], data[minIndex]);
            //multi-dimensional dynamic array to store the pair of swaps in it
            swaps.push_back(make_pair(i, minIndex));
            SiftDown(minIndex);//Sift the swapped element recursively
        }


    }

    void GenerateSwaps() {
        swaps.clear();
        //To fix a tree we start from the leaves and go to the root
        //                             1

        //               2                                       3             level1

        //         4            5                         6             7      level2
         
        //      8    9     10      11                12      13     14    15   level3

        //Imagine a Tree of 15 nodes
        ////To sort the tree we divide it into subtrees and sort the subtrees from the leaves going up to the root
        //for example in the above tree starting from 15 which is the data.size since there are 15 elements stored in the tree
        //starting from the leaves at level3 since this is the last level there will be no problems in them
        //moving up to node 7 which is the initial number in the below for loop in this case since int(15/2)=7
        //since i here will be 7 and calling the SiftDown function and passing 7 to it
        //the sub tree of 7,14,15 will be sorted
        //and moving in level2 from the right to the left to node 6,5,4 and so on
        //we will do the same until we reach the root at the top leading  to a sorted tree in ascending order
        for (int i = (data.size() / 2); i>=0 ; i--)
        {
            SiftDown(i);
        }

    }

public:
    void Solve() {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    HeapBuilder heap_builder;
    heap_builder.Solve();
    return 0;
}
