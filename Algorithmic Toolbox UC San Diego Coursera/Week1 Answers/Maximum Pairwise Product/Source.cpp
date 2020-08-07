//We use this algorithm as it runs on runtime O(n)
//we use 2 separates for loop to get the two maximum elements in the input array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Stress Test
//generate random serial numbers input
while (true)
{
    int n = rand() % 10 + 2//genereate  a random size for the input array between 2 and 2+9
        //start with small range at the start of debugging 
        //then increase the range
        cout << n << endl;
    vector<int>a;
    for (int i = 0; i < n; i++)
    {
        a.push_back(rand() % 100000);//generate random numbers until 9999 and push them into the input array a
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";//print the array of input a which is later passed as a parameter to the two functions
    }
    cout << endl;
    
    long long result1;//= function1(a)
    long long result2;//=function2(a)
    if (result1!=result2)//no match
    {
        cout << "Wrong answer: " << result1 << " " << result2 << endl;//print wrong answers and the results
    }
    else {//if they match
        cout << "OK" << endl;//print OK
    }
}


long long MaxPairwiseProduct(const vector<int>& numbers) {
    int n = numbers.size();
    int maxindex1 = -1;//initialize the first maximum element index to -1
    //so if the array is empty
    for (int  i = 0; i < n; i++)
    {

        if (maxindex1==-1 || numbers[i]>numbers[maxindex1])
            //two conditions
            //if the array contains one element the max_index1 will be this element
            //or if the array's current for loop's element is larger than the previous max element selected
            //before the for loop counts
            //it will be the new max element
        {
            maxindex1 = i;
        }
    }
    //same thing to the second max element
    //except we want to make sure it's not the same index of the first maximum one
    int maxindex2 = -1;
    for (int j = 0; j < n; j++)
    {
        //the first condition
        //to make sure that the maximum element 1 is excluded 
        //the other two is explained before
        if ((j!=maxindex1) && ((maxindex2 == -1) || (numbers[j] > numbers[maxindex2])))
        {
            maxindex2 = j;
        }
    }
    return ((long long)(numbers[maxindex1])) * numbers[maxindex2];//return the product of the maximum two elements in the input array
    //we use long long in one of the elements to ensure that the result is long long
    //to prevent integer overflow
    //due to type casting
    //long long * int =long long

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
