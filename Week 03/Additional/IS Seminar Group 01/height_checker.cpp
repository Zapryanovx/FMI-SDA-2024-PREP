#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {

        size_t size = heights.size();
        vector<int> res(size);

        for (size_t i = 0; i < size; i++)
        {
            res[i] = heights[i];
        }

        std::sort(res.begin(), res.end());

        int diff = 0;
        for (size_t i = 0; i < size; i++)
        {
            if (heights[i] != res[i])
            {
                diff++;
            }
        }

        return diff;
    }
};