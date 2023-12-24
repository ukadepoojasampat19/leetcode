# Write your MySQL query statement below
select author_id as id
from Views
where author_id = viewer_id
group by  author_id
having count(distinct article_id) >= 1
order by id;
