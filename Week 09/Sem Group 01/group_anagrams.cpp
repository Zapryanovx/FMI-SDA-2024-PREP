class Solution {
public:

    string strSort(string word)
    {
        int counter[26] = {};

        for (char ch : word)
        {
            counter[ch - 'a']++;
        }

        string myHash;
        for (int i = 0; i < 26; i++)
        {
            if (!counter[i])
            {
                continue;
            }

            myHash += to_string(counter[i]);
            myHash += (i + 'a');
        }

        return myHash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for (auto word : strs)
        {
            mp[strSort(word)].push_back(word);
        }

        vector<vector<string>> res;
        for (auto key : mp)
        {
            res.push_back(key.second);
        }

        return res;
    }
};