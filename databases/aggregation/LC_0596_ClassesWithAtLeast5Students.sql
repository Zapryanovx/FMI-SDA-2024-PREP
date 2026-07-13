/*
 https://leetcode.com/problems/classes-with-at-least-5-students/description
 */

SELECT class
FROM courses
GROUP BY courses.class
HAVING COUNT(*) >= 5;