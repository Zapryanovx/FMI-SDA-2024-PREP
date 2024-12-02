class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {

        unordered_map<char, pair<int, int>> interval;
        for (int i = 0; i < s.size(); i++)
        {
            if (interval.find(s[i]) == interval.end())
            {
                interval[s[i]] = { i, i };
            }

            else
            {
                interval[s[i]].second = i;
            }
        }

        int maxDist = -1;
        for (auto& p : interval)
        {
            maxDist = max(maxDist, p.second.second - p.second.first - 1);
        }

        return maxDist;
    }
};