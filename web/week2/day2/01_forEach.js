// Array.forEach
// 반복을 하는 배열 메서드
// for랑 유사하다

const array = [3, 5, 4, 2];

// forEach와 callback 사용하기 
array.forEach(function(value){
    console.log(value)
})

// callback function 을 arrow function으로 표현하기
array.forEach(value => (console.log(value)))