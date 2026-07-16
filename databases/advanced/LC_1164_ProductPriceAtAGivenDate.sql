/*
 https://leetcode.com/problems/product-price-at-a-given-date/description
 */

SELECT
    products.product_id,
    IFNULL(current_price.new_price, 10) AS price
FROM (
         SELECT DISTINCT product_id
         FROM Products
     ) AS products
         LEFT JOIN (
    SELECT
        p.product_id,
        p.new_price
    FROM Products AS p
             JOIN (
        SELECT
            product_id,
            MAX(change_date) AS max_change_date
        FROM Products
        WHERE change_date <= '2019-08-16'
        GROUP BY product_id
    ) AS latest
                  ON latest.product_id = p.product_id
                      AND latest.max_change_date = p.change_date
) AS current_price
                   ON products.product_id = current_price.product_id;