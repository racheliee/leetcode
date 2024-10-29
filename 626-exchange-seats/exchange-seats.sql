# Write your MySQL query statement below
select 
    case
        when id % 2 = 0 then id - 1 # even
        when id % 2 = 1 and id < (select max(id) from seat) then id + 1 # odd
        else id # last elem
    end as id,
    student
from seat
order by id asc