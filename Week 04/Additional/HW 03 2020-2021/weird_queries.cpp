#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> nums(n);
    for (int i = n - 1; i >= 0; --i)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    while (q--)
    {
        long long sum = 0;
        int s, p;
        cin >> s >> p;

        auto maxIt = lower_bound(nums.begin(), nums.end(), p + 1);
        if (maxIt == nums.begin())
        {
            cout << 0 << endl;
            continue;
        }

        --maxIt;
        int maxIndex = distance(nums.begin(), maxIt);

        int count = 0;
        for (int j = maxIndex; j >= 0; --j)
        {
            if (sum + nums[j] > s)
            {
                break;
            }

            sum += nums[j];
            ++count;
        }

        printf("%u\n", count);
    }

    return 0;
}
