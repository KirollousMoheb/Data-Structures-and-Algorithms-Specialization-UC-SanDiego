#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif
//The goal of this Program is to implement in depth-first methods to sort the binary search tree
//We can sort them Inorder ,preOrder or Post oder

//And by depth we mean that we Completely traverse one sub-tree before moving on to a sibling sub-tree
//And that is opposite to the Breadth-first method that we traverse all the nodes in each level
//then we move to the next level
using namespace std;
class TreeOrders {
    int n;//number of nodes
    vector <int> key;//vector to store the nodes' keys
    vector <int> left;//vector to store the left nodes
    vector <int> right;//vector to store the right nodes

public:
    void read() {//read input from the user
        cin >> n;
        key.resize(n);
        left.resize(n);
        right.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> key[i] >> left[i] >> right[i];//the user enters the key the left node
            //index of the right and left child of the parent node
        }
    }


    void in_order(vector <int>& result,int node) {//function to sort the tree in ascending order

        if (node ==-1)//if the node is a leaf do nothing
        {
            return;
        }
        //else
        in_order(result,this->left[node]);//go to the left of the current node recursively until there is no more left node
        result.push_back(this->key[node]);//push back this node's key the nreturn to it's parent 
        //since there is no left nodes to it either push its key to the result array
        in_order(result,this->right[node]);//go to the right node and do the previous steps again
        //For this tree
        //                                     4
        //                               2                  5
        //                          1          3
        //the order will be 12345
    }

    void  pre_order(vector <int>& result,int node) {//return the key of the active node when we aare moving to it's left subtree
        
        if (tree == -1)
        {
            return;
        }

        result.push_back(this->key[node]);
        pre_order(result,this->left[node]);
        pre_order(result,this->right[node]);
        //For this tree
        //                                        4
        //                               2                  5
        //                          1          3

        //the order will be 42135
        //We push the node's key if we passed by it no matter what
        //so we first print the parent node of the whole tree
        //and since we move left firsr we will print the 2 the 1 and we go right to print 3
        //and we move up again but we find that all of them was pushed
        //then we move right

        


        
    }

    void post_order(vector <int>&result,int node) {//return the node at the end 

        if (tree == -1)
        {
            return;
        }
        post_order(result,this->left[node]);
        post_order(result,this->right[node]);
        result.push_back(this->key[node]);


        //For this tree
        //                                     4
        //                               2                  5
        //                          1          3
        //the order will be 13254
        //The post order print's the node's key only if we passed through all it's children first
        //It also prints the leaves first as we move to the most left
        //The first node that will not have a child will be node 1 then 3 and now 2 is considered with no children so we push it

    }
    vector <int> IN() {
        vector<int>result;
        in_order(result, 0);//the starting node is zer oa we start from the parent node with index 0
        return result;
    }
    vector <int> PRE() {
        vector<int>result;
        pre_order(result, 0);//the starting node is zer oa we start from the parent node with index 0
        return result;

    }
    vector <int> POST() {
        vector<int>result;
        post_order(result, 0);//the starting node is zer oa we start from the parent node with index 0
        return result;

    }

};

void print(vector <int> a) {
    for (size_t i = 0; i < a.size(); i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << a[i];
    }
    cout << '\n';
}

int main_with_large_stack_space() {
    ios_base::sync_with_stdio(0);
    TreeOrders t;
    t.read();
    print(t.IN());
    print(t.PRE());
    print(t.POST());
    return 0;
}

int main(int argc, char** argv)
{
#if defined(__unix__) || defined(__APPLE__)
    // Allow larger stack space
    const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                std::cerr << "setrlimit returned result = " << result << std::endl;
            }
        }
    }
#endif

    return main_with_large_stack_space();
}

