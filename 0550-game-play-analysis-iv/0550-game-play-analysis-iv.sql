# Write your MySQL query statement below
select ROUND(COUNT(t2.player_id) / COUNT(t1.player_id) , 2) as fraction from
(select player_id , min(event_date) as min_date from Activity group by player_id ) t1 left join Activity t2 on t1.player_id = t2.player_id and DATEDIFF(min_date , t2.event_date) = -1
