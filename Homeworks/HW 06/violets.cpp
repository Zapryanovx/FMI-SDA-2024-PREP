#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> flowers;
    flowers.push_back(0); //if n = 0 => 0
    flowers.push_back(2); //if n = 1 => [blue], [purple]
    flowers.push_back(2); //if n = 2 => [blue, purple], [purple, blue];

    for (int i = 3; i <= n; i++)
    {
        int res = (flowers[i - 1] + flowers[i - 2]) % MOD;
        flowers.push_back(res);
    }

    cout << flowers.back();

    return 0;
}
