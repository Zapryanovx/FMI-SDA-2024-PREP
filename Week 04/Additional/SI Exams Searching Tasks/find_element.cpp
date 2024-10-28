// https://www.hackerrank.com/contests/sda-2019-2020-exam-2e3nr4rr/challenges/find-element-sda/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int q;
    cin >> q;

    for (size_t i = 0; i < q; i++)
    {
        int target;
        cin >> target;

        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);

        if (left == right)
        {
            cout << distance(nums.begin(), left) << endl;
        }

        else
        {
            cout << distance(nums.begin(), left) << " " << distance(nums.begin(), right) - 1 << endl;
        }
    }

    return 0;
}
