# Write your MySQL query statement below
select distinct a.num as ConsecutiveNums
from logs a join logs b on a.id+1 = b.id join logs c on b.id+1 = c.id
where a.num = b.num and b.num = c.num;