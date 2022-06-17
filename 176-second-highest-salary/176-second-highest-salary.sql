# Write your MySQL query statement below
 # (select distinct salary as SecondHighestSalary from Employee order by salary desc limit 1 offset 1) 
 select (
  select distinct Salary from Employee order by Salary Desc limit 1 offset 1
)as SecondHighestSalary