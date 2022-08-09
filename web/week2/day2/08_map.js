// Array.map(콜백함수)

const data = [3, 5, 4, 2];
const newData = data.map(data => data + 1)
console.log(data)
console.log(newData)

data.map(data => {
    return (data + 1)
}) // 이것과 동일.


// 첫번째 인자 (순환하는 현재 값, 인덱스)
const newData2 = data.map((data, index) => {
    console.log(data);
    console.log(index);
    console.log('=============')
})
