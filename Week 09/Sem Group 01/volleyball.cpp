#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int root, n;
    cin >> root >> n;

    unordered_set<int> s;
    s.insert(root);

    for (int i = 0; i < n; i++)
    {
        int player, bestFriend;
        cin >> player >> bestFriend;

        if (s.find(player) != s.end())
        {
            s.insert(bestFriend);
        }
    }

    cout << s.size();


    return 0;
}