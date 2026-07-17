/*
 https://leetcode.com/problems/delete-duplicate-emails/description
 */

DELETE FROM Person
WHERE id NOT IN (
    SELECT id FROM (
                       SELECT MIN(id) AS id
                       FROM Person
                       GROUP BY email
                   ) t
)