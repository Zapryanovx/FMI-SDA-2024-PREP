/*
 https://leetcode.com/problems/percentage-of-users-attended-a-contest/description
 */

SELECT contest_id, ROUND(COUNT(r.user_id) / (SELECT COUNT(*) FROM USERS) * 100, 2) AS percentage
FROM Register AS r
         JOIN Users AS u
              ON r.user_id = u.user_id
GROUP BY contest_id
ORDER BY percentage DESC, contest_id;