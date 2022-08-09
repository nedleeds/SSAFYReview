// 특정 메서드(콜백함수)
// Array.find(콜백함수)
// 조건을 만족하는 첫번째 요소의 값을 통째로 반환한다
const chicken = [
    {name: "머리", quantity: 1},
    {name: "날개", quantity: 2},
    {name: "닭다리", quantity: 2},
    {name: "닭가슴살", quantity: 1},
    {name: "닭발", quantity: 2},
]
// name 중 B를 가지고 있는 것 
const findB_2 = chicken.find(element => element.name === "닭다리")
console.log(findB_2)

// Array.findIndex(콜백함수)
// 조건을 만족하는 첫번째 요소의 인덱스를 반환한다.
const findIndexResult = chicken.findIndex(element => element.name === "닭다리");
console.log(findIndexResult)