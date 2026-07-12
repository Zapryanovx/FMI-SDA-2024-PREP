/*
https://leetcode.com/problems/immediate-food-delivery-ii/description
 */

SELECT ROUND(SUM(CASE WHEN d.order_date = d.customer_pref_delivery_date THEN 1 ELSE 0 END)
                 / COUNT(*) * 100, 2) AS immediate_percentage
FROM Delivery d
         JOIN (
    SELECT customer_id, MIN(order_date) AS first_order
    FROM Delivery
    GROUP BY customer_id
) AS fo ON d.customer_id = fo.customer_id AND d.order_date = fo.first_order;