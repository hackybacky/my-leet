# Write your MySQL query statement below


SELECT t1.firstName , t1.lastName , t2.city , t2.state FROM Person AS t1 LEFT OUTER JOIN Address AS t2 ON t1.personId = t2.personId