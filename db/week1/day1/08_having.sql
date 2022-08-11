-- Group By를 사용할 때 쓸 수 있는 조건 절
use world;
select * from city;

select CountryCode as '도시', count(CountryCode) as '도시수' from city group by CountryCode;

-- 각 그룹 별로 도시 수를 가져오되, 도시 수가 200이 넘는 도시만 가져와라
select CountryCode as '도시', count(CountryCode), Population as '도시수' from city 
group by CountryCode having count(Population) < 1000 ;

-- problem 1)
-- 1) world 스키마의 city 테이블에서 record 총 갯수 출력
select count(id) as '레코드수' from city;

-- 2) 하위 5개의 도시 코드, 인구수 출력
select Name '도시명', Population '인구수'  from city order by Population ASC limit 5;

-- 3) TOP 5개의 국가 코드, 인구 수 출력
select CountryCode, Population '인구수' from city order by Population DESC limit 5 ;


-- problem 2)
-- Employees 스키마, titles 테이블에서 
-- 10만명 이상이 사용하고 있는 직함의 이름(title)과 직원의 수 출력
use Employees;
select * from titles;

select title, count(title) from titles 
group by title having count(title) > 100000;
