// 문자열.replace("찾은 문자열", "대체할 문자열");
const str = "BBQBbQMINBbQ";
const result = str.replace("BBQBbQMINBbQ", "ABC");

console.log(str);
console.log(result);

// replace에 상세 조건을 부여할 때
// 정규 표현식 사용! <- 맛만 보자
// 정규 표현식의 형태 : / / + flag 
// flag 중 g-flag 는 패턴과 일치하는 모든 것을 찾는다
// g가 없는 경우 맨 처음부터 하나만 찾음
// i가 붙으면, 대소문자 구분 없이 검색

const result1 = str.replace(/B/g, "K")
const result2 = str.replace(/B/gi, "K")
console.log(result1);
console.log(result2);