#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

long long findBiggestCube(unsigned long long points)
{
    unsigned long long left = 0;
    unsigned long long right = points;

    unsigned long long res = 0;
    while (left <= right)
    {
        unsigned long long mid = left + (right - left) / 2;
        unsigned long long cube = mid > 2097151 ? ULLONG_MAX : mid * mid * mid;
        if (cube <= points)
        {
            res = max(cube, res);
            left = mid + 1;
        }

        else
        {
            right = mid - 1;
        }

    }

    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned long long points;
    cin >> points;

    unsigned long long presents = 0;
    while (points > 0)
    {
        unsigned long long present = findBiggestCube(points);
        points -= present;
        presents++;
    }

    cout << presents;


    return 0;
}
