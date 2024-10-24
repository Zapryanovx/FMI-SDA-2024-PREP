#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long ternary_recursive(long long left, long long right, long long x, long long candy)
{
    if (left == right)
    {
        return candy;
    }

    long long mid1 = left + (right - left) / 3;
    long long mid2 = right - (right - left) / 3;

    if (x <= mid1)
    {
        return ternary_recursive(left, mid1, x, candy + 1);
    }

    else if (x >= mid2)
    {
        return ternary_recursive(mid2, right, x, candy + 1);
    }

    return candy;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long p, n;
    cin >> p >> n;

    long long max = pow(3, p);

    for (long long i = 0; i < n; i++)
    {
        long long curr;
        cin >> curr;
        cout << ternary_recursive(1, max, curr, 1) << endl;
    }


    return 0;
}
