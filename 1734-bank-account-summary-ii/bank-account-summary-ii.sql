# Write your MySQL query statement below

/*select count(distinct account), sum(amount) as balance
from Users
left join  Transactions on Users.account = Transactions.trans_id
group by Transactions.account
where Transactions.amount >10000;*/


/*SELECT u.name, SUM(t.amount) AS balance
FROM Users u
JOIN Transactions t ON u.account = t.account
GROUP BY u.account
HAVING SUM(t.amount) > 10000;*/



select u.name , sum(t.amount) as balance
from Users u
join Transactions t on u.account = t.account
group by u.account
having sum(t.amount) > 10000;