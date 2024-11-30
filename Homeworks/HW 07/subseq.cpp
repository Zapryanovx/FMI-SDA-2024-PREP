#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

vector<int> findMinPermutation(int n, int m, vector<int>& p)
{
    set<int> valid;
    for (int i = 1; i <= n; i++)
    {
        valid.insert(i);
    }

    for (int x : p)
    {
        valid.erase(x);
    }

    vector<int> res;
    auto iter = valid.begin();

    for (int i = 0; i < m; i++)
    {
        while (iter != valid.end() && *iter < p[i])
        {
            res.push_back(*iter);
            iter++;
        }

        res.push_back(p[i]);
    }

    while (iter != valid.end())
    {
        res.push_back(*iter);
        iter++;
    }

    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int>p(m);
    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
    }

    vector<int> res = findMinPermutation(n, m, p);
    for (int x : res)
    {
        cout << x << " ";
    }
    cout << endl;


    return 0;
}
