// https://www.hackerrank.com/contests/practice-3-1/challenges/bibibi/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    long long n;
    cin >> n;

    vector<long long> nums(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    long long q;
    cin >> q;

    long long target;
    for (size_t i = 0; i < q; i++)
    {
        cin >> target;

        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);

        if (left == right)
        {
            cout << -1 << " " << -1 << endl;
        }

        else
        {
            cout << distance(nums.begin(), left) + 1 << " " << distance(nums.begin(), right) << endl;
        }
    }


    return 0;
}
