use world;
select id, CountryCode from city ; -- CountryCode 상의 중복 허용
select id, CountryCode from city group by CountryCode; -- CountryCode 상의 중복 제거 

-- 언제 group by를 사용할까? -> 집계함수가 필요할 때 사용
-- sum, avg, min, max, count
-- 인구수를 다 더할 때 : sum
-- 평균을 구할 때 : avg
-- 최소/최대값을 구할 때 : min/max
-- 개수 구할 때 : count

select sum(Population) from city;
select count(Population) from city where Name like "kim%";
-- ex) 대한민국의 도시별 평균 인구를 구하라 

-- CountryCode 별로 묶어서 각 CountryCode 별 인구수의 합
select CountryCode, sum(Population) as "인구수 합계" from city
group by CountryCode;

-- CountryCode 별 최대 인구수
select CountryCode, max(Population) from city
group by CountryCode;

select CountryCode, count(id) as "도시 개수" from city 
group by CountryCode;

select Name , Population as "인원 수" from city
where CountryCode = "KOR" group by Name ;
