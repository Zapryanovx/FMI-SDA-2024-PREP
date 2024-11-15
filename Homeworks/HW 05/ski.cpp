#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct TreeNode
{
    int val = 0;
    int left = 0;
    int right = 0;
};

void dfs(int nodeIdx, int verticalIdx, vector<TreeNode>& v, map<int, long long>& verticalSums)
{
    if (nodeIdx == -1)
    {
        return;
    }

    verticalSums[verticalIdx] += v[nodeIdx].val;

    dfs(v[nodeIdx].left, verticalIdx - 1, v, verticalSums);
    dfs(v[nodeIdx].right, verticalIdx + 1, v, verticalSums);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<TreeNode>v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].val >> v[i].left >> v[i].right;
    }

    map<int, long long> verticalSums;
    dfs(0, 0, v, verticalSums);

    for (auto& pair : verticalSums)
    {
        cout << pair.second << " ";
    }

    return 0;
}
