use minco;
select name, age from honey;

-- name -> '이름'으로 (as가 alia래)
select name as '이름', age from honey;
-- as는 생략이 가능하다
select name '이름', age '나이' from honey; 

-- 정렬하기  (order by를 사용)
-- 오름차순 (default 정렬) : ASC (ascending)
select * from honey order by age ASC;
-- 내림차순 : DESC (descending)
select * from honey order by age DESC;

-- limit (데이터의 제한) : 너무 많은 데이터가 필요없는 경우
select * from honey limit 2;
-- offset : 시작 행을 설정
select * from honey limit 2 offset 3;

select num '번호', name '성함', age '나이' from honey order by age ASC;
select name, age from honey order by name ASC;