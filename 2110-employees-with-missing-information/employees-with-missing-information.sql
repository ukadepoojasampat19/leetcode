# Write your MySQL query statement below
/*select e.employee_id
from Employees e
left join Salaries s on e.employee_id = s.employee_id
where e.name is null or s.salary is null
order by employee_id asc;*/
select employee_id from employees where employee_id NOT IN
(select employee_id from salaries)
UNION
select employee_id from salaries where employee_id NOT IN
(select employee_id from Employees )
order by employee_id