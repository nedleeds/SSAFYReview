-- CRUD : create read update delete
-- login    : select
-- sign-in  : select, insert (+ update)
-- sign-out : delete, update
--          : update로 탈퇴 여부를 y로 바꿔놓고 특정 기간 후 delete로 삭제
-- 게시판은 CRUD 전체 사용 
select * from minco.honey;
-- insert into 테이블 이름 values ('값', '값', ...);
-- 삽입해보자 : 7번, 이순신, 20세
--         : 8번, 박중박, 50세

insert into honey values(6, "이순신", "60");
select * from minco.honey;
insert into honey values(7, "박중박", "50");
select * from minco.honey;
insert into honey values(8, "박중박", "50");
select * from minco.honey;

update honey SET name="이순신", age ="80" where num = 6;
select * from minco.honey;
update honey SET name='박혁거세', age ="210" where num = 8;
select * from minco.honey;
-- update honey SET name="박중박", age ="50" where name = '이순신'; 
-- 위의 name='이순신' 은 safe mode에 의해 막힌다
-- 유일성을 위반하는 키 값의 특성을 변환하면 모든 이순신이라는 사람의 데이터가 바뀌기 때문이다
-- 기본키만 가지고 update가 동작하도록 되어있다(default: safemode)

-- delete from 테이블 where 조건
-- 6번 record 삭제
delete from honey where num = 6; 
-- 7번 record 삭제
delete from honey where num = 7; 
-- 8번 record 삭제
delete from honey where num = 8;
select * from minco.honey;

-- problem)
select * from honey;

update honey set age = "15" where num = 2 or num =4;
select * from honey;

delete from honey where num = 1;
select * from honey;

insert into honey values (50, "촉촉", 100);
select * from honey;




