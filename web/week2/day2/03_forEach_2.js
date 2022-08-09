// Array.forEach
// 반복을 하는 배열 메서드
// for랑 유사하다

const array = [-5, 3, 4, 2, -7, -2, 7];
let cnt = 0;
// forEach와 callback 사용하기 
let pplus = []
let mminus = []
array.forEach(function(value){
    if (value<0) mminus.push(value);
    else if (value>0) pplus.push(value);
})
console.log(mminus)
console.log(pplus)
