# Write your MySQL query statement below


select e.machine_id , ROUND(AVG(e.timestamp - s.timestamp), 3) as processing_time from Activity as e , Activity as s where e.activity_type = 'end' and s.activity_type = 'start' and e.machine_id = s.machine_id group by machine_id