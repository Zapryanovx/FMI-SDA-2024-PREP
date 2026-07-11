/*
 https://leetcode.com/problems/not-boring-movies/description
 */

SELECT *
FROM Cinema
WHERE id % 2 = 1
AND description != 'boring'
ORDER BY rating DESC;