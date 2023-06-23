# Write your MySQL query statement below


SELECT customer_id , COUNT(customer_id) as count_no_trans
FROM Visits 
left JOIN Transactions  ON Visits.visit_id = Transactions.visit_id where transaction_id is null group by customer_id