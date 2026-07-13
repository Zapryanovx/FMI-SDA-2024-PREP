/*
 https://leetcode.com/problems/product-sales-analysis-iii/description
 */

SELECT
    outer_sales.product_id,
    outer_sales.year AS first_year,
    outer_sales.quantity,
    outer_sales.price
FROM Sales AS outer_sales
         JOIN (
    SELECT product_id, MIN(year) AS first_year
    FROM Sales
    GROUP BY product_id
) inner_sales ON inner_sales.product_id = outer_sales.product_id
                     AND inner_sales.first_year = outer_sales.year;