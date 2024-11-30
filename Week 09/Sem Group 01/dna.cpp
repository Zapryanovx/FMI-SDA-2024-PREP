class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10)
        {
            return {};
        }

        unordered_set<string> seen;
        unordered_set<string> repeated;

        for (int i = 0; i <= s.size() - 10; i++)
        {
            string seq = s.substr(i, 10);
            if (seen.find(seq) != seen.end())
            {
                repeated.insert(seq);
            }

            else
            {
                seen.insert(seq);
            }
        }

        vector<string> res;
        for (auto& seq : repeated)
        {
            res.push_back(seq);
        }

        return res;
    }
};