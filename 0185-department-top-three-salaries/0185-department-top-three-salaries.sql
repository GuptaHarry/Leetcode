/* Write your T-SQL query statement below */
SELECT 
    d.name AS Department,
    t.name AS Employee,
    t.salary AS Salary
FROM (
    SELECT 
        e.name,
        e.salary,
        e.departmentId,
        DENSE_RANK() OVER (
            PARTITION BY e.departmentId 
            ORDER BY e.salary DESC
        ) AS rnk
    FROM Employee e
) t
JOIN Department d 
    ON t.departmentId = d.id
WHERE t.rnk <= 3;
