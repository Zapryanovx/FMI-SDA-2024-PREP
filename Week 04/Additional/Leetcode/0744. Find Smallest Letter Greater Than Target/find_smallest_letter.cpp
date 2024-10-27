class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        auto nextLetter = upper_bound(letters.begin(), letters.end(), target);

        if (nextLetter == letters.end())
        {
            return letters[0];
        }
        return *nextLetter;

    }
};