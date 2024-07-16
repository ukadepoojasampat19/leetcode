# Write your MySQL query statement below
select e1.name
from Employee e1, Employee e2
where e1.id = e2.managerId
group by e2.managerId
having count(*) >= 5;
