// 특정 메서드(콜백함수)
// Array.find(콜백함수)
// 조건을 만족하는 첫번째 요소의 값을 통째로 반환한다
const array = [1, 2, 3, 4, 5];
const findResult = array.find(element => element > 2);
console.log(findResult);

const inventory = [
    {name: "A", quantity: 1},
    {name: "B", quantity: 2},
    {name: "C", quantity: 3},
]
// name 중 B를 가지고 있는 것 - 1번 방법
const findB_1 = inventory.find(element => {
    return element.name === "B";
})
// name 중 B를 가지고 있는 것 - 2번 방법
const findB_2 = inventory.find(element => element.name === "B")

console.log(findB_1)
console.log(findB_2)

// Array.findIndex(콜백함수)
// 조건을 만족하는 첫번째 요소의 인덱스를 반환한다.
const findIndexResult = inventory.findIndex(element => element.quantity === 2);
console.log(findIndexResult)