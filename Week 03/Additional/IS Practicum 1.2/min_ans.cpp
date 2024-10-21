#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        std::sort(arr.begin(), arr.end());

        int minDiff = arr[1] - arr[0];
        for (size_t i = 2; i < arr.size(); i++)
        {
            minDiff = std::min(minDiff, arr[i] - arr[i - 1]);
        }

        cout << minDiff;

        vector<vector<int>> res;
        for (int i = 1; i < arr.size(); i++)
        {
            if (minDiff == arr[i] - arr[i - 1])
            {
                vector<int> pair{ arr[i - 1], arr[i] };
                res.push_back(pair);
            }
        }

        return res;
    }
};