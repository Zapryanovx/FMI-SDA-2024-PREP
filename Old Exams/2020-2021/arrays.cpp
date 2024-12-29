#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    vector<int> y(m);
    for (int i = 0; i < m; i++)
    {
        cin >> y[i];
    }

    sort(x.begin(), x.end());
    for (int i = 0; i < m; i++)
    {
        auto right = lower_bound(x.begin(), x.end(), y[i]);
        cout << distance(x.begin(), right) << " ";
    }

    return 0;
}
