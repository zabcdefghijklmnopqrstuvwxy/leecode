# Write your MySQL query statement below
select w1.Id as Id from Weather as w1 inner join Weather as w2 on datediff(w1.RecordDate,w2.RecordDate)=1 where w1.Temperature > w2.Temperature;