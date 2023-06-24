# Write your MySQL query statement below

select E.name from Employee as E  join Employee as E2 on E.id = E2.managerId group by E.name Having COUNT(E2.managerId) >= 5 