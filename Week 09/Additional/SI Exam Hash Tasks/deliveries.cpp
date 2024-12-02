// https://www.hackerrank.com/contests/sda-test-5/challenges/1-140/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;

        if (m.find(c) == m.end() || m[c] + 1 < 10)
        {
            m[c]++;
        }

        else
        {
            m.erase(c);
        }
    }

    int purchases = 0;
    for (auto& p : m)
    {
        purchases += p.second;
    }

    cout << m.size() << " " << purchases << endl;


    return 0;
}