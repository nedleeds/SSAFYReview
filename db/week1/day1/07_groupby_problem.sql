use employees;
select * from salaries;

-- 1) 급여 수령 시작일 별 급여의 평균을 구하시오
select from_date, count(from_date) as '사람 수(명)', avg(salary) as '급여 수령 시작일 별 급여의 평균'  from salaries 
group by from_date order by from_date DESC;
