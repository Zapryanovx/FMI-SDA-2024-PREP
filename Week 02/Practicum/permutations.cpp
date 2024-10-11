#include <iostream>

class Solution {
public:
    int findPermutationDifference(std::string s, std::string t) {

        int alpha[26]{};

        size_t size = s.size();
        for (int i = 0; i < size; i++)
        {
            alpha[s[i] - 'a'] = i;
        }

        for (int i = 0; i < size; i++)
        {
            alpha[t[i] - 'a'] = std::abs(alpha[t[i] - 'a'] - i);
        }

        int sum = 0;
        for (int i = 0; i < 26; i++)
        {
            sum += alpha[i];
        }

        return sum;
    }
};