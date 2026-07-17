/*
 https://leetcode.com/problems/restaurant-growth/description
 */

SELECT visited_on, amount, average_amount
FROM (
         SELECT
             visited_on,
             SUM(daily) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) AS amount,
             ROUND(SUM(daily) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) / 7, 2) AS average_amount
         FROM (
                  SELECT visited_on, SUM(amount) AS daily
                  FROM Customer
                  GROUP BY visited_on
              ) t
     ) w
WHERE visited_on >= (SELECT MIN(visited_on) FROM Customer) + INTERVAL 6 DAY
