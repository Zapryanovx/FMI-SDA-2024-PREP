/*
 https://leetcode.com/problems/the-number-of-employees-which-report-to-each-employee/description
 */

SELECT
    m.employee_id,
    m.name,
    COUNT(*) AS reports_count,
    ROUND(AVG(e.age)) AS average_age
FROM Employees e
         JOIN Employees m
              ON e.reports_to = m.employee_id
GROUP BY m.employee_id, m.name
ORDER BY m.employee_id;