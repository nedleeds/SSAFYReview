// Array.filter(콜백함수)
// 콜백함수(요소, index)
// 특정 조건을 만족하는 값'들'을 추출

const data = [3, 5, 4, 2];
// 3보다 큰 값들을 배열에 담는다
const newData = data.filter((element)=>element>3);
console.log(newData)