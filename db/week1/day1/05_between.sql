use world;

-- between and 사용하기
select * from city where Population between 500 and 900;

-- in (후보 item1, 후보 item2, ...)
-- 지정된 컬럼의 값이 특정 값에 해당되는 조건을 만들 때 활용 or

select * from city where Name in('Seoul', 'Sydney', 'Oxford');

-- in 조건을 제외하고 
select * from city where Name not in('Seoul', 'Sydney', 'Oxford');

-- like 는 포함하고 있으면 가져온다.
-- 문자열 검색 NAME=Seoul

-- %: 다중문자를 의미(와일드카드) 
-- 'New로 시작하는' 모든 문자열을 뜻함
select * from city where Name LIKE "New%"; 
-- 'New가 포함된' 모든 문자열을 뜻함
select * from city where Name LIKE "%New%"; 

-- 한가지 문자만 가져올 때
-- CountryCoder가 K_R -> K와 R 사이에 한글자는 아무거나 들어가도 된다
select * from city where CountryCode LIKE 'K_R';

-- problem)
-- 1) 인구수(Population)가 1000명 미만이면서 A로 시작하는 도시 찾기
select * from city where Population < 1000 and Name like "A%";

-- 2) 일본(JPN) 에서, 인구수가 100만명 ~ 200만명인 도시를 찾아
-- 도시 이름과, 국가 코드 (JPN) 필드만 출력하기
select Name, CountryCode from city 
where CountryCode = "JPN" 
and Population between 1000000 and 2000000;

-- 3) 이름에 kim이 포함된 도시 출력하기
select * from city where Name like "%kim%";

