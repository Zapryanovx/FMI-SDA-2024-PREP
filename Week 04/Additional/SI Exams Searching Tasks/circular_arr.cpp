// https://www.hackerrank.com/contests/sda-2020-2021-test3-trvdd/challenges/weird-array-1/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int check(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }

        else if (nums[left] <= nums[mid])
        {
            if (nums[left] <= target && target < nums[mid])
            {
                right = mid - 1;
            }

            else
            {
                left = mid + 1;
            }
        }

        else
        {

            if (nums[mid] < target && target <= nums[right])
            {
                left = mid + 1;
            }

            else
            {
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int q;
    cin >> q;

    vector<int> res;
    int target;
    for (size_t i = 0; i < q; i++)
    {
        cin >> target;
        res.push_back(check(nums, target));
    }

    for (size_t i = 0; i < q; i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}
