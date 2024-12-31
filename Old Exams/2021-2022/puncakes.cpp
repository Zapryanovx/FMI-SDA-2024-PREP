#include <bits/stdc++.h>
using namespace std;

bool check(vector<long long>& cooks, long long n, long long m)
{
    long long res = 0;
    long long size = cooks.size();
    for (long long i = 0; i < size; i++)
    {
        res += m / cooks[i];
    }

    return res >= n;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;
    vector<long long> cooks(k);

    long long maxTime = LLONG_MIN;
    for (long long i; i < k; i++)
    {
        cin >> cooks[i];
        maxTime = max(maxTime, cooks[i]);
    }

    long long l = 0;
    long long r = maxTime * n;

    long long ans = 0;
    while (l <= r)
    {
        long long m = l + (r - l) / 2;
        if (check(cooks, n, m))
        {
            ans = m;
            r = m - 1;
        }

        else
        {
            l = m + 1;
        }
    }

    cout << ans;

    return 0;
}