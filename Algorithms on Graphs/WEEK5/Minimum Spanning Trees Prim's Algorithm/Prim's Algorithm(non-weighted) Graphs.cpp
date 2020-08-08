#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
#include <numeric>

using std::vector;
using namespace std;

#define MY_MAX_INT 9999999999

double minimum_distance(vector<int> x, vector<int> y) {
    double result = 0.0;
    vector<double> cost(x.size(), MY_MAX_INT);
    vector<bool> visited(x.size(), false);

    auto cmp = [](pair<int, double> left, pair<int, double> right) { return (((left.second) > (right.second)) || (((left.second) == (right.second)) && ((left.first) > (right.first)))); };
    priority_queue<pair<int, double>, std::vector<pair<int, double>>, decltype(cmp)> Q(cmp);

    //priority_queue < pair<int, double> >Q;
    cost[0] = 0.0;
    Q.push(make_pair(0, cost[0]));

    while (!Q.empty())
    {
        int u = Q.top().first;
        Q.pop();

        if (visited[u] == false)
        {
            for (size_t i = 0; i < x.size(); i++)
            {

                if ((u != i) && (visited[i] == false)) 
                {
                    double x_dist = x[u] - x[i];
                    double y_dist = y[u] - y[i];

                    double distance = sqrt((x_dist * x_dist) + (y_dist * y_dist));
                    double newcost = distance;

                    if (cost[i] > newcost)
                    {
                        cost[i] = newcost;
                        Q.push(make_pair(i, cost[i]));
                    }
                }

            }
            visited[u] = true;
        }
    }
    for (auto i = 0; i < cost.size(); i++) {
        result += cost[i];
    }

    return result;
}

int main() {
    size_t n;
    cin >> n;
    vector<int> x(n), y(n);
    for (size_t i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    cout << std::setprecision(10) << minimum_distance(x, y) << endl;
}