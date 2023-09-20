CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    DECLARE number INT ;
    SET number = N - 1;
 
      # Write your MySQL query statement below.
    # DECLARE RESULT INT;
    RETURN (SELECT distinct(salary) AS getNthHighestSalary FROM Employee ORDER BY Employee.salary desc LIMIT 1 OFFSET number);
    # RETURN RESULT;
END;