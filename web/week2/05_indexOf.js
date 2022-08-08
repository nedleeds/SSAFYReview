const a = "HELLOWORLDHELLO";

// 문자열.indexOf("찾을 문자열", 검색을 시작할 index값, 생략시 0부터 시작);
const g1 = a.indexOf("OWO");
const g2 = a.indexOf("HELLO", 6);
const g3 = a.indexOf("안녕!세상", 6);

console.log(g1);
console.log(g2);
// 문자열 찾을 때 못찾는 경우: -1 출력
console.log(g3);

