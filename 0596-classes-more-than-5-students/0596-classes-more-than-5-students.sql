# Write your MySQL query statement below


select class from (select class , COUNT(DISTINCT(student)) as cnt from Courses group by class) t where t.cnt >= 5

