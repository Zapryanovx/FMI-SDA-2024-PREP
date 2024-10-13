#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        std::sort(piles.begin(), piles.end());

        int left = 0;
        int right = piles.size() - 1;

        int count = 0;
        while (left < right)
        {
            left++;
            right--;

            count += piles[right--];
        }

        return count;

    }
};