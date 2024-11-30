#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n, b;
    cin >> n >> b;

    vector<long long> arr(n);
    long long bIndex = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == b)
        {
            bIndex = i;
        }
    }

    long long res = 0;
    map<long long, long long> count;

    int balance = 0;
    for (long long i = bIndex; i >= 0; i--)
    {
        if (arr[i] < b)
        {
            balance--;
        }

        else if (arr[i] > b)
        {
            balance++;
        }

        count[balance]++;
    }

    balance = 0;
    for (long long i = bIndex; i < n; i++)
    {
        if (arr[i] < b)
        {
            balance--;
        }

        else if (arr[i] > b)
        {
            balance++;
        }

        res += count[-balance];
    }

    cout << res;
    return 0;
}