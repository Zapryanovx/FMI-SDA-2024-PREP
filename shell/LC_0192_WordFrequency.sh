# https://leetcode.com/problems/word-frequency/description/

cat words.txt | tr ' ' '\n' | grep -v '^$' | sort | uniq -c | sort -nr | awk '{print $2, $1}'