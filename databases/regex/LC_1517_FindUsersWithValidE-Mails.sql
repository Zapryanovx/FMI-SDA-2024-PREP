/*
 https://leetcode.com/problems/find-users-with-valid-e-mails/description
 */

SELECT user_id, name, mail
FROM Users
WHERE REGEXP_LIKE(mail, '^[A-Za-z]+[A-Za-z0-9_.-]*@leetcode[.]com$','c');