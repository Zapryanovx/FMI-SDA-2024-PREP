/*
 https://leetcode.com/problems/game-play-analysis-iv/description
 */

SELECT ROUND(COUNT(a2.player_id) / COUNT(*), 2) AS fraction
FROM Activity AS a
         JOIN (
    SELECT player_id, MIN(event_date) AS first_login
    FROM Activity
    GROUP BY player_id
) AS fl ON a.player_id = fl.player_id AND a.event_date = fl.first_login
         LEFT JOIN Activity a2 ON a2.player_id = fl.player_id
    AND a2.event_date = DATE_ADD(fl.first_login, INTERVAL 1 DAY);