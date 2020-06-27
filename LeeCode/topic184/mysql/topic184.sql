# Write your MySQL query statement below
select d.`Name` as Department,e.`Name` as Employee,e.Salary from Employee as e inner join Department as d on e.DepartmentId=d.Id where (e.DepartmentId,e.Salary) in(select DepartmentId,max(Salary) from Employee group by DepartmentId); 
