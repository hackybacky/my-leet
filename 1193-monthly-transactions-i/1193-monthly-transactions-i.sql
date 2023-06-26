# Write your MySQL query statement below

select  LEFT(trans_date , 7)  as month , country , COUNT(id) as   trans_count , SUM(state = "approved" ) as approved_count ,SUM(amount) as  trans_total_amount , SUM( CASE WHEN state = "approved" THEN amount ELSE 0 END) as approved_total_amount from    Transactions  group by month , country