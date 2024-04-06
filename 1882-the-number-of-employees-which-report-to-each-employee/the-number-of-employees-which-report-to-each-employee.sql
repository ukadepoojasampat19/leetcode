select m.employee_id ,m.name,COUNT(e.employee_id ) as reports_count,ROUND(AVG(e.age*1.0),0) as average_age 
from Employees e
join Employees m 
on e.reports_to =m.employee_id 
group by m.employee_id ,m.name
ORDER BY employee_id