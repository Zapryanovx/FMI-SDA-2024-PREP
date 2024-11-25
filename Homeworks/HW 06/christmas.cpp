#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;
const int MAX_TIME = 10080;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> dp(MAX_TIME + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int time = MAX_TIME; time >= v[i]; time--)
        {
            dp[time] = (dp[time] + dp[time - v[i]]) % MOD;
        }
    }

    int res = 0;
    for (int i = 0; i <= MAX_TIME; i++)
    {
        res = (res + dp[i]) % MOD;
    }

    cout << res << endl;

    return 0;
}
