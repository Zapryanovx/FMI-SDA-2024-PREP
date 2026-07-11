/*
https://leetcode.com/problems/find-customer-referee/description
 */
SELECT name
FROM Customer
WHERE referee_id IS NULL
   OR referee_id != 2; 