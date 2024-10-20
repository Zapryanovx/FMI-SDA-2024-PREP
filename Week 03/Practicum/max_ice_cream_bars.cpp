#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        sort(costs.begin(), costs.end());

        int count = 0;
        for (size_t i = 0; i < costs.size(); i++)
        {
            if (costs[i] <= coins)
            {
                count++;
                coins -= costs[i];
            }
        }

        return count;
    }
};