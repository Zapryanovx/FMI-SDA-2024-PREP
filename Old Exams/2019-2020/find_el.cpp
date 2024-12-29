#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;

        auto left = lower_bound(nums.begin(), nums.end(), x);
        auto right = upper_bound(nums.begin(), nums.end(), x);

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
