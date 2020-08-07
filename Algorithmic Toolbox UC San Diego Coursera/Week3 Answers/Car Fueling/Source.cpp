#include <iostream>
#include <vector>

using namespace std;

int min_refills(int dist, int tank, vector<int>& stops, int start, int count) {
    if ((start + tank) >= dist) {
        return count;
    }
    if (stops.size() == 0) {
        return -1;
    }
    int old_start = start;
    for (int i = 0; i < stops.size(); i++) {
        if (stops[i] <= (start + tank)) {
            old_start = stops[i];
        }
        else {
            if (i != 0) {
                stops.erase(stops.begin(), stops.begin() + i);
            }
            else {
                stops.erase(stops.begin());
            }
            return min_refills(dist, tank, stops, old_start, count + 1);
        }
    }
    return (old_start + tank) >= dist ? count + 1 : -1;
}

int compute_min_refills(int dist, int tank, vector<int>& stops) {
    return min_refills(dist, tank, stops, 0, 0);
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}