#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() {

    string str;
    cin >> str;

    vector<int> dp(str.size() + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < str.size() - 1; i++)
    {
        if (dp[i] == INT_MAX)
        {
            continue;
        }

        int letters[26]{};
        for (int j = i; j < str.size(); j++)
        {
            letters[str[j] - 'a']++;
            bool is_valid = true;
            for (int k = 0; k < 26; k++)
            {
                if (letters[k] % 2 == 0 && letters[k] != 0)
                {
                    is_valid = false;
                    break;
                }
            }

            if (is_valid)
            {
                dp[j + 1] = min(dp[j + 1], dp[i] + 1);
            }
        }
    }

    cout << dp.back();

    return 0;
}
