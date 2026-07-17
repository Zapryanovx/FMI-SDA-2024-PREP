/*
 https://leetcode.com/problems/last-person-to-fit-in-the-bus/description
 */

SELECT person_name
FROM (
         SELECT person_name, turn, SUM(weight) OVER (ORDER BY turn) AS cumulative_weight
         FROM Queue
     ) AS sorted
WHERE cumulative_weight <= 1000
ORDER BY turn DESC LIMIT 1