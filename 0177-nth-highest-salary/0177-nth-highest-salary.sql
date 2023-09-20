CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    DECLARE number INT;
    SET number = N - 1;
    
  RETURN (
      # Write your MySQL query statement below.
   SELECT distinct(salary) AS getNthHighestSalary FROM Employee ORDER BY Employee.salary desc LIMIT 1 OFFSET number
 );
END