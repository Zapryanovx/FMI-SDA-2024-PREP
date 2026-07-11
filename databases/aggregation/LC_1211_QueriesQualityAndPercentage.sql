/*
 https://leetcode.com/problems/queries-quality-and-percentage/description
 */

SELECT query_name, ROUND(AVG(rating / position), 2) AS quality,
       ROUND((SELECT COUNT(*) FROM Queries WHERE rating < 3 AND query_name = q.query_name) / COUNT(*) * 100, 2) AS poor_query_percentage
FROM Queries AS q
GROUP BY query_name;