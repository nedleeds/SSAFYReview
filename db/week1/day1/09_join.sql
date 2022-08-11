use employees;

-- 각 사원들의 사원번호, first_name, 근무부서 번호를 가져오자
--     !!! 테이블이 나뉘어 있다 !!!
-- 사원번호, first_name(employees 테이블) 
-- 근무부서 번호(dept_emp 테이블)
-- 공통인 부분을 찾아야한다
-- => emp_no

-- select, from 테이블 left join 테이블 on 조건(공통된 부분)
-- 공통으로 포함된 부분(emp_no)은 어디의 emp_no인지 명시를 해줘야한다
select a.emp_no, first_name from employees as a
left join dept_emp as b
on employees.emp_no = b.emp_no;

-- problem)
-- 각 사원들의 사원번호, first_name, 현재 받고 있는 급여액을 가져온다
-- left join은 null 값이 나오고 
-- left join 대신 INNER join 하면 null 값이 안나온다
select employees.emp_no, first_name, salary
from employees
left join salaries
on salaries.emp_no = employees.emp_no
where salaries.to_date = '9999-01-01';
 
