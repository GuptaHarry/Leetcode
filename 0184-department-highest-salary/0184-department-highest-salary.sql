/* Write your T-SQL query statement below */
SELECT 
    Dept.name AS Department,  
    e.name AS Employee,  
    e.salary AS Salary
FROM (
    SELECT 
        Emp.name, 
        Emp.salary, 
        Emp.departmentId,
        DENSE_RANK() OVER (PARTITION BY Emp.departmentId ORDER BY Emp.salary DESC) AS rnk
    FROM Employee Emp
) e
JOIN Department Dept 
    ON e.departmentId = Dept.id
WHERE e.rnk = 1;
