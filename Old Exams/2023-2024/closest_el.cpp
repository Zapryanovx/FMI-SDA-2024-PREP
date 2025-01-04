#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    cin >> n;

    vector<long long> nums(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    long long q;
    cin >> q;

    while (q--)
    {
        long long curr;
        cin >> curr;

        auto it = lower_bound(nums.begin(), nums.end(), curr);

        if (it == nums.end())
        {
            cout << -1 << endl;
        }

        else if (it == nums.begin())
        {
            if (it + 1 != nums.end())
            {
                cout << *(it + 1) << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }

        else if (it != nums.end() && *it == curr)
        {
            if (it + 1 != nums.end())
            {
                cout << *(it + 1) << endl;
            }

            else
            {
                cout << -1 << endl;
            }
        }

        else
        {
            auto left = (it - 1);

            if (abs(*left - curr) >= abs(*it - curr))
            {
                if (it + 1 != nums.end())
                {
                    cout << *(it + 1) << endl;
                }

                else
                {
                    cout << -1 << endl;
                }
            }

            else
            {
                cout << *it << endl;
            }
        }
    }

    return 0;
}
