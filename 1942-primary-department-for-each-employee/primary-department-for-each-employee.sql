# Write your MySQL query statement below
/*select employee_id, (case when (count(distinct department_id)) = 1 then department_id else primary_flag ='Y' end) as department_id
from Employee
group by employee_id*/
select employee_id, department_id
from Employee
where primary_flag ='Y' or
employee_id in
(select employee_id 
from Employee
group by employee_id
having count(employee_id) =1);