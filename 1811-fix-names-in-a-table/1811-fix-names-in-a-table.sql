/* Write your T-SQL query statement below */

SELECT 
Users.user_id ,   CONCAT( UPPER(SUBSTRING(Users.name,1,1)) , LOWER( SUBSTRING(Users.name,2, LEN(Users.name ) )))  AS name
FROM  Users
ORDER BY  Users.user_id;