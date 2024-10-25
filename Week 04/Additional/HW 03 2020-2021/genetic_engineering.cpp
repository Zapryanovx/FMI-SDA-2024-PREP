#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ternary_recursive(long long left, long long right, long long target, long long pickle)
{
    if (left >= right)
    {
        return pickle;
    }

    long long mid1 = left + (right - left) / 3;
    long long mid2 = right - (right - left) / 3;
    if (target <= mid1)
    {
        return ternary_recursive(left, mid1, target, pickle + 1);
    }

    else if (target >= mid2)
    {
        return ternary_recursive(mid2, right, target, pickle + 1);
    }

    return pickle;
}

int main() {

    /*int p, n;
    cin >> p >> n;

    long long maxNum = pow(3, p);

    for (int i = 0; i < n; i++)
    {
        long long curr;
        cin >> curr;

        cout << ternary_recursive(1, maxNum, curr, 1) << endl;
    }*/

    vector<int> v = { 1,2,3,4 };
    
    auto it = upper_bound(v.begin(), v.end(), 5);
    cout << (it == v.end());

    return 0;
}
