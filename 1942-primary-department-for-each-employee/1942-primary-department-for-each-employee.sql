/* Write your T-SQL query statement below */



-- step-1 person with only one dept 
select employee_id , department_id
from 
(
select employee_id , department_id , primary_flag , 
COUNT(*) OVER(PARTITION BY employee_id) AS CNT
FROM Employee
) t 
WHERE CNT=1 or primary_flag ='Y'