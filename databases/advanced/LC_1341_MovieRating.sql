/*
 https://leetcode.com/problems/movie-rating/description
 */

(SELECT name AS results
 FROM Users AS u
          JOIN MovieRating AS mr
               ON u.user_id = mr.user_id
 GROUP BY u.user_id
 ORDER BY COUNT(*) DESC, name
     LIMIT 1)

UNION ALL

(SELECT title AS results
 FROM Movies AS m
          JOIN MovieRating AS mr
               ON m.movie_id = mr.movie_id
 WHERE created_at LIKE '2020-02-%'
 GROUP BY m.movie_id
 ORDER BY AVG(rating) DESC, title
     LIMIT 1);