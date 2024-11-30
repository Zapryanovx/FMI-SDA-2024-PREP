class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> rn;
        unordered_map<char, int> mg;

        for (auto& ch : ransomNote)
        {
            rn[ch]++;
        }

        for (auto& ch : magazine)
        {
            mg[ch]++;
        }

        for (auto& ch : rn)
        {
            if (mg.find(ch.first) == mg.end())
            {
                return false;
            }

            else if (mg.find(ch.first)->second < ch.second)
            {
                return false;
            }
        }

        return true;
    }
};