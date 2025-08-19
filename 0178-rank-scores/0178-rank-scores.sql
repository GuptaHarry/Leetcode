/* Write your T-SQL query statement below */

SELECT
score,rank
from (
    SELECT score,
    DENSE_RANK() OVER( ORDER BY score DESC) rank
    FROM Scores
) t 