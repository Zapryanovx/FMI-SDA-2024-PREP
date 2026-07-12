/*
https://leetcode.com/problems/user-activity-for-the-past-30-days-i/description
 */

SELECT activity_date as day, COUNT(DISTINCT user_id) AS active_users
FROM ACTIVITY
WHERE activity_date > DATE_SUB('2019-07-27', INTERVAL 30 DAY)
  AND activity_date <= '2019-07-27'
GROUP BY activity_date