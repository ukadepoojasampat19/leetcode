select contest_id,
   round( count(user_id) * 100.0 / (select count(distinct user_id) from Users),2) as percentage
from Register
group by contest_id
order by percentage desc, contest_id;