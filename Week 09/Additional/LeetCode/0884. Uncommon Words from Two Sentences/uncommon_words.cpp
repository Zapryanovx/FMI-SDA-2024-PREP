class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {

        stringstream ss1(s1);
        stringstream ss2(s2);

        unordered_map<string, int> m1;
        unordered_map<string, int> m2;

        while (!ss1.eof())
        {
            string word;
            ss1 >> word;

            m1[word]++;
        }

        while (!ss2.eof())
        {
            string word;
            ss2 >> word;

            m2[word]++;
        }

        vector<string> res;
        for (auto& p : m1)
        {
            if (p.second == 1 && m2.count(p.first) == 0)
            {
                res.push_back(p.first);
            }
        }

        for (auto& p : m2)
        {
            if (p.second == 1 && m1.count(p.first) == 0)
            {
                res.push_back(p.first);
            }
        }

        return res;
    }
};