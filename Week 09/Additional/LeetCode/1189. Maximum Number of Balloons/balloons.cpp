class Solution {
public:
    int maxNumberOfBalloons(string text) {

        unordered_map<char, int> m;
        for (auto& ch : text)
        {
            if (ch == 'b' || ch == 'a' || ch == 'o' || ch == 'l' || ch == 'n')
            {
                m[ch]++;
            }
        }

        int maxDoubleOccs = min(m['o'], m['l']) / 2;
        int maxSingleOccs = min(m['b'], m['a']);
        maxSingleOccs = min(maxSingleOccs, m['n']);

        return min(maxDoubleOccs, maxSingleOccs);
    }
};