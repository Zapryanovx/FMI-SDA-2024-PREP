/*
 https://leetcode.com/problems/consecutive-numbers/description
 */

SELECT DISTINCT l1.num AS ConsecutiveNums
FROM Logs AS l1
         JOIN Logs AS l2
              ON l1.num = l2.num
         JOIN Logs AS l3
              ON l2.num = l3.num
WHERE l1.id = l2.id - 1
  AND l2.id = l3.id - 1;
