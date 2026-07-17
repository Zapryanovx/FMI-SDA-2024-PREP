/*
 https://leetcode.com/problems/list-the-products-ordered-in-a-period/description
 */

SELECT product_name, SUM(unit) AS unit
FROM Products AS p
         JOIN Orders AS o
              ON p.product_id = o.product_id
WHERE o.order_date LIKE '2020-02-%'
GROUP BY product_name
HAVING SUM(unit) >= 100;