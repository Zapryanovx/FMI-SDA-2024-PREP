/*
 https://leetcode.com/problems/project-employees-i/description
 */

SELECT p.project_id, IFNULL(ROUND(AVG(experience_years), 2), 0) AS average_years
FROM Project AS p
         LEFT JOIN Employee AS e
                   ON p.employee_id = e.employee_id
GROUP BY p.project_id;