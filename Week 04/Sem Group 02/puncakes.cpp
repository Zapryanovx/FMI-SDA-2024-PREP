#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool check(vector<long long> cookers, long long target, long long p)
{
    long long currPuncakes = 0;
    for (long long i = 0; i < cookers.size(); i++)
    {
        currPuncakes += target / cookers[i];
    }

    return currPuncakes >= p;
}


int main() {

    long long p, c;
    cin >> p >> c;

    vector<long long> cookers(c);
    long long minTime = LLONG_MAX;
    long long maxTime = LLONG_MIN;

    for (long long i = 0; i < c; i++)
    {
        cin >> cookers[i];

        minTime = min(cookers[i], minTime);
        maxTime = max(cookers[i], maxTime);
    }

    long long left = (p / c) * minTime;
    long long right = (p / c + 1) * maxTime;

    long long ans = 0;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        if (check(cookers, mid, p))
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