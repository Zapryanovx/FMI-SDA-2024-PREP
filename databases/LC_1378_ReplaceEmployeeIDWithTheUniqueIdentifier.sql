/*
https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/description
*/

SELECT unique_id, name
FROM Employees AS e
         LEFT JOIN EmployeeUNI AS euni
                   ON e.id = euni.id;