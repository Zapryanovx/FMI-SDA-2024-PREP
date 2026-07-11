/*
https://leetcode.com/problems/students-and-examinations/description
*/

SELECT s.student_id, s.student_name, subs.subject_name, COUNT(e.student_id) AS attended_exams
FROM Students AS s
         JOIN Subjects AS subs
         LEFT JOIN Examinations AS e
                   ON s.student_id = e.student_id AND subs.subject_name = e.subject_name
GROUP BY s.student_id, s.student_name, subs.subject_name
ORDER BY student_id, subject_name;