#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        std::sort(cost.rbegin(), cost.rend());

        int sum = 0;
        for (size_t i = 0; i < cost.size(); i++)
        {
            if ((i + 1) % 3 == 0)
            {
                continue;
            }

            sum += cost[i];
        }

        return sum;
    }
};