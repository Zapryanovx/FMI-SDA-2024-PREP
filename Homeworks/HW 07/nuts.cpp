#include <bits/stdc++.h>

using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int x, n;
        cin >> x >> n;

        unordered_map<int, int> m;
        int at = 1;

        for (int i = 0; i < n; i++)
        {
            int weight;
            cin >> weight;

            int target = x - weight;
            auto iter = m.find(target);
            if (iter != m.end())
            {
                cout << iter->second << " " << i + 1 << endl;
            }

            else
            {
                m[weight] = at++;
            }
        }
    }

    return 0;
}