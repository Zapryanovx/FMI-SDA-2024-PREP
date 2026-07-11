/*
https://leetcode.com/problems/invalid-tweets/description
*/

SELECT tweet_id
FROM Tweets
WHERE LENGTH(content) > 15;