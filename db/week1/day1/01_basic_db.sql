SELECT * FROM minco.honey;
-- 검색: SELECT
-- 1개의 SQL 문을 실행 : CTRL + Enter
-- 여러개(다중) SQL 문을 실행 : CTRL + SHIFT ENTER (실행하고자 하는 영역을 드래그, 드래그 안할 시 모든 SQL 실행)

-- num이 2보다 크거나 같고 4보다 작거나 같다 (where 사용) 
select * from minco.honey where 2<=num and num <=4;

-- minco.honey 에서 이름이 "동형" 인 것을 찾아 name과 age를 찾아라
SELECT name, age from minco.honey where name="동형";

-- 연산자
-- prob 1)
SELECT * from honey where num =3 or num =5;
-- prob 2)
SELECT num, name, age from minco.honey where 2<=num and num<=5;
-- prob 3)
SELECT * from honey where age = 20;
-- prob 4)  
SELECT name from honey where num %2=0 and age%2=1; 

