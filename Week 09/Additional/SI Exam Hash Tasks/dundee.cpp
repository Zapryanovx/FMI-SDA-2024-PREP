// https://www.hackerrank.com/contests/sda-test5-2022-2023-43wdst52/challenges

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> m;
    string s;

    while (cin >> s)
    {
        m[s]++;
    }

    for (auto& p : m)
    {
        if (p.second == 1)
        {
            cout << p.first << endl;
        }
    }

    return 0;
}
