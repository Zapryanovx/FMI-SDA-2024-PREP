class Solution {
public:
    string reversePrefix(string word, char ch) {

        stack<char> s;

        int prefixEnd = 0;
        for (int i = 0; i < word.size(); i++)
        {
            s.push(word[i]);
            if (word[i] == ch)
            {
                prefixEnd = i;
                break;
            }
        }

        if (!prefixEnd)
        {
            return word;
        }

        string reversed;
        while (!s.empty())
        {
            reversed += s.top();
            s.pop();
        }

        for (int j = prefixEnd + 1; j < word.size(); j++)
        {
            reversed += word[j];
        }

        return reversed;
    }
};