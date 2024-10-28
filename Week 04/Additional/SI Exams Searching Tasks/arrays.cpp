// https://www.hackerrank.com/contests/exam-2020-02-06-sda/challenges/challenge-2851/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    vector<int> y(m);
    for (size_t i = 0; i < m; i++)
    {
        cin >> y[i];
    }

    sort(x.begin(), x.end());
    for (size_t i = 0; i < m; i++)
    {
        cout << distance(x.begin(), lower_bound(x.begin(), x.end(), y[i])) << " ";
    }

    return 0;
}
