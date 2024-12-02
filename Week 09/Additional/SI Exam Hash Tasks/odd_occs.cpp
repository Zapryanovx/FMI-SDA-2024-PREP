// https://www.hackerrank.com/contests/sda-2021-2022-test5-8dec/challenges/challenge-3157/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {

    int n;
    cin >> n;

    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int target;
        cin >> target;

        m[target]++;
    }

    int sum = 0;
    for (auto& el : m)
    {
        if (el.second % 2 != 0)
        {
            sum += el.first * el.second;
        }
    }

    cout << sum;

    return 0;
}
