// Array.forEach
// 반복을 하는 배열 메서드
// for랑 유사하다

const array = [4,3,5,1,6,5];
let cnt = 0;
// forEach와 callback 사용하기 
array.forEach(function(value){
    if (value%2){
        console.log(value)
        cnt++;
    }
})
console.log("홀수 갯수: " + cnt)
// callback function 을 arrow function으로 표현하기
// array.forEach(value => if {(value%2) (console.log(value))})
