# Write your MySQL query statement below
/*select e.employee_id
from Employees e
left join Salaries s on e.employee_id = s.employee_id
where e.name is null or s.salary is null
order by employee_id asc;*/



select employee_id  from Employees where employee_id not in 
(select employee_id from Salaries)
union
select employee_id from Salaries where employee_id not in
(select employee_id from Employees)
order by employee_id asc;
