#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {

public:
    string frequencySort(string s) {

        vector<pair<int, char>> symbols(62, { 0, 0 });

        for (size_t i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                symbols[s[i] - '0'].first++;
                symbols[s[i] - '0'].second = s[i];
            }

            else if (islower(s[i]))
            {
                symbols[s[i] - 'a' + 10].first++;
                symbols[s[i] - 'a' + 10].second = s[i];
            }

            else if (isupper(s[i]))
            {
                symbols[s[i] - 'A' + 36].first++;
                symbols[s[i] - 'A' + 36].second = s[i];
            }
        }

        sort(symbols.rbegin(), symbols.rend());

        string res;
        for (size_t i = 0; i < 62; i++)
        {
            for (size_t j = symbols[i].first; j > 0; j--)
            {
                res += symbols[i].second;
            }
        }

        return res;
    }
};