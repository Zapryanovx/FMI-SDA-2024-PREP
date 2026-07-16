/*
 https://leetcode.com/problems/managers-with-at-least-5-direct-reports/description
*/

SELECT m.name
FROM Employee as m
         JOIN Employee as e
              ON m.id = e.managerId
GROUP BY m.id, m.name
HAVING COUNT(*) >= 5;