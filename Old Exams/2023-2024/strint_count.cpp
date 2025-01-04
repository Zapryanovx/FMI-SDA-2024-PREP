#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;

        unordered_map<char, int> m;
        unordered_map<int, int> freq;

        for (char ch : word)
        {
            m[ch]++;
        }

        for (auto& p : m)
        {
            freq[p.second]++;
        }

        if (freq.size() >= 3)
        {
            cout << 0 << endl;
        }

        else if (freq.size() == 1)
        {
            cout << (m.size() == 1) << endl;
        }

        else
        {
            vector<pair<int, int>> v;
            for (auto& iter : freq)
            {
                v.push_back(iter);
            }

            if ((v[0].second == 1 && v[0].first == 1) || (v[1].second == 1 && v[1].first == 1))
            {
                cout << 1 << endl;
            }

            else if (v[0].second == v[1].second)
            {
                cout << (abs(v[1].first - v[0].first) - 1 == 0) << endl;
            }

            else if (v[0].second == 1)
            {
                cout << (v[0].first == v[1].first + 1) << endl;
            }

            else if (v[1].second == 1)
            {
                cout << (v[1].first == v[0].first + 1) << endl;
            }

            else
            {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}
