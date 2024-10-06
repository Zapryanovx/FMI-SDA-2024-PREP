#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> candidates(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> candidates[i];
    }

    std::sort(candidates.begin(), candidates.end());

    int min = candidates[k - 1] - candidates[0];
    for (int i = 1; i < n - k + 1; i++)
    {
        min = std::min(min, candidates[i + k - 1] - candidates[i]);
    }

    std::cout << min;

    return 0;
}