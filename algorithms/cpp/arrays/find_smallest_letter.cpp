// https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/?envType=problem-list-v2&envId=binary-search
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