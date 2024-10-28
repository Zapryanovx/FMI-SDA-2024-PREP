// https://www.hackerrank.com/contests/sda-ttest-2/challenges/challenge-1636/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> check(vector<int>& nums, int target)
{
    int count = 1;

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return { mid, count };
        }

        else if (nums[mid] > target)
        {
            right = mid - 1;
        }

        else
        {
            left = mid + 1;
        }

        count++;
    }

    return { -1, count - 1 };
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

    int k, target;
    cin >> k;

    vector<pair<int, int>> resSearch;
    for (size_t i = 0; i < k; i++)
    {
        cin >> target;
        resSearch.push_back(check(nums, target));
    }

    for (size_t i = 0; i < k; i++)
    {
        cout << resSearch[i].first << " ";
    }
    cout << endl;

    for (size_t i = 0; i < k; i++)
    {
        cout << resSearch[i].second << " ";
    }

    return 0;
}
