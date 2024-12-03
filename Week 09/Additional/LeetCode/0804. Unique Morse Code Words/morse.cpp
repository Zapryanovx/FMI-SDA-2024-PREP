class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {

        vector<string> morse = {
            ".-","-...","-.-.","-..",".","..-.","--.","....",
            "..",".---","-.-",".-..","--","-.","---",".--.",
            "--.-",".-.","...","-","..-","...-",".--","-..-",
            "-.--","--..",
        };

        unordered_set<string> encoded;
        for (auto& word : words)
        {
            string res;
            for (auto& ch : word)
            {
                res += morse[ch - 'a'];
            }

            encoded.insert(res);
        }

        return encoded.size();
    }
};