// https://www.hackerrank.com/contests/sda-2021-2022-test5-8dec/challenges/challenge-3156/problem

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
    vector<string> data(n);
    unordered_map<string, int> m;

    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
        m[data[i]]++;
    }

    for (auto& s : data)
    {
        cout << m[s] << " ";
    }

    return 0;
}
