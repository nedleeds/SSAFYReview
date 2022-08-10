// Array.filter(콜백함수)
// 콜백함수(요소, index)
// 특정 조건을 만족하는 값'들'을 추출

const data = [1,2,3,4,5,6,7,8,9,10];
// 3보다 큰 값들을 배열에 담는다
let arr1 = data.filter(e => e%2)
console.log(arr1)
const arr2 = data.filter((element)=>(element>3 && element<9));
console.log(arr2)