#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<pair<int, int>> pairs(n);

    for (size_t i = 0; i < n; i++)
    {
        pairs[i].first = nums[i];
        pairs[i].second = i;
    }

    sort(pairs.begin(), pairs.end());

    for (size_t i = 0; i < n; i++)
    {
        nums[pairs[i].second] = i;
    }

    for (size_t i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

}
