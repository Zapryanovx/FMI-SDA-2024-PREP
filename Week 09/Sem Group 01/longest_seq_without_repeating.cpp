class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> m;

        int maxSize = 0;
        int currStart = 0;

        for (int i = 0; i < s.size(); i++)
        {
            auto iter = m.find(s[i]);
            if (iter != m.end() && iter->second >= currStart)
            {
                currStart = iter->second + 1;
            }

            m[s[i]] = i;
            if (i - currStart + 1 > maxSize)
            {
                maxSize = i - currStart + 1;
            }
        }

        return maxSize;
    }
};