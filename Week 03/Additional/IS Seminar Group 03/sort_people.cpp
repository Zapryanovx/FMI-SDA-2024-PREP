#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        vector<pair<int, string>> data(names.size());

        for (size_t i = 0; i < names.size(); i++)
        {
            data[i].first = heights[i];
            data[i].second = names[i];
        }

        std::sort(data.begin(), data.end());

        vector<string> res;
        for (size_t i = 0; i < names.size(); i++)
        {
            res.push_back(data[names.size() - i - 1].second);
        }

        return res;
    }
};