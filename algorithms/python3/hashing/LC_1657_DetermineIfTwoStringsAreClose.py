# https://leetcode.com/problems/determine-if-two-strings-are-close/description

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2) or set(word1) != set(word2):
            return False

        w1_chars = {}
        w2_chars = {}

        for i in range(0, len(word1)):
            w1_chars[word1[i]] = w1_chars.get(word1[i], 0) + 1
            w2_chars[word2[i]] = w2_chars.get(word2[i], 0) + 1

        return sorted(w1_chars.values()) == sorted(w2_chars.values())
