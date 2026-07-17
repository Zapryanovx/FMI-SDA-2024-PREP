/*
 https://leetcode.com/problems/department-top-three-salaries/description/
 */

SELECT
    d.name AS Department,
    e1.name AS Employee,
    salary AS Salary
FROM Employee e1
         JOIN Department d
              ON e1.departmentId = d.id
WHERE (
          SELECT COUNT(DISTINCT salary)
          FROM Employee e2
          WHERE e2.departmentId = e1.departmentId
            AND e2.salary > e1.salary
      ) < 3;
