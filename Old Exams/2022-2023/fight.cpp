#include <bits/stdc++.h>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> stickers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stickers[i];
    }

    int fights = 0;
    unordered_map<int, int> wanted;
    for (int i = 0; i < n; i++)
    {
        wanted[stickers[i]]++;

        int curr;
        cin >> curr;
        if (wanted[curr] <= 0)
        {
            fights++;
        }

        else
        {
            wanted[curr]--;
        }
    }

    cout << fights;

    return 0;
}