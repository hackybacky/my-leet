# Write your MySQL query statement below

select name , bonus from Employee left outer join Bonus on Employee.empId = Bonus.empId  where Bonus.bonus < 1000 or Bonus.bonus is NULL