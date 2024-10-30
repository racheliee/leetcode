# Write your MySQL query statement below
select  s.student_id, 
        s.student_name, 
        sub.subject_name, # sub로 해야 null이 안생김!!
        count(e.subject_name) as attended_exams
from students s
cross join subjects sub
left join examinations e
on e.student_id = s.student_id and sub.subject_name = e.subject_name
group by s.student_id, sub.subject_name
order by s.student_id asc, sub.subject_name asc; # order w sub so it includes all subject_names!!