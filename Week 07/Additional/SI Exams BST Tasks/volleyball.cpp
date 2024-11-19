// https://www.hackerrank.com/contests/sda-hw-8/challenges/volleyball-friends

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {

    int root;
    cin >> root;

    set<int> ms;
    ms.insert(root);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int p, f;
        cin >> p >> f;

        if (ms.find(p) != ms.end())
        {
            ms.insert(f);
        }
    }

    cout << ms.size();

    return 0;
}