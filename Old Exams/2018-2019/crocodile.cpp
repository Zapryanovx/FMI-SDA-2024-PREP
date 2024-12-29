#include <bits/stdc++.h>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> m;

    string word;
    while (cin >> word)
    {
        m[word]++;
    }

    for (auto& p : m)
    {
        if (p.second == 1)
        {
            cout << p.first << endl;
        }
    }

    return 0;
}
