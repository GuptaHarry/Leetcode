/* Write your T-SQL query statement below */

select distinct
num as ConsecutiveNums
from (
    select id,num,
    LEAD(num) OVER(ORDER BY id) NextValue,
    LAG(num) OVER(ORDER BY id) PreviousValue
    -- LEAD(num,2) OVER(ORDER /BY num) NxtToNxt
    FROM Logs
)t
WHERE  num=NextValue and num = PreviousValue;