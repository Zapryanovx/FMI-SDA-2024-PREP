// https://www.hackerrank.com/contests/practice-3-1/challenges/winterwinter/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

bool check(vector<long long>& clothes, long long mid, long long k)
{
    long long totalTime = 0;
    for (size_t i = 0; i < clothes.size(); i++)
    {
        if (clothes[i] > mid)
        {
            long long time = (clothes[i] - mid + k - 2) / (k - 1);
            totalTime += time;
        }

    }

    return totalTime <= mid;
}

int main() {

    long long  n, k;
    cin >> n >> k;

    vector<long long> clothes(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> clothes[i];
    }

    long long  left = 0;
    long long  right = *max_element(clothes.begin(), clothes.end());

    if (k == 1)
    {
        cout << right;
        return 0;
    }

    long long ans = LLONG_MAX;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        if (check(clothes, mid, k))
        {
            ans = mid;
            right = mid - 1;
        }

        else
        {
            left = mid + 1;
        }
    }


    cout << ans;

    return 0;
}
