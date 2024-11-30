// https://www.hackerrank.com/contests/sda-hw-9-2023/challenges/challenge-4437

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <climits>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    unordered_map<int, int> mp;
    int dist = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (mp.find(v[i]) == mp.end())
        {
            mp[v[i]] = i;
        }

        else
        {
            dist = min(dist, i - mp[v[i]]);
            mp[v[i]] = i;
        }
    }

    cout << dist;


    return 0;
}
