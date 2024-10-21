#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {

        sort(word.begin(), word.end());

        vector<int> letters;

        int count = 1;
        for (size_t i = 1; i < word.size(); i++)
        {
            if (word[i] == word[i - 1])
            {
                count++;
            }
            else
            {
                letters.push_back(count);
                count = 1;
            }
        }
        letters.push_back(count);

        sort(letters.rbegin(), letters.rend());

        int sum = 0;
        int clicks = 1;
        int buttons = 1;

        int sizeUnique = letters.size();
        for (size_t i = 0; i < sizeUnique; i++)
        {
            sum += clicks * (letters[i]);
            buttons++;
            if (buttons > 8)
            {
                clicks++;
                buttons = 1;
            }
        }

        return sum;
    }
};