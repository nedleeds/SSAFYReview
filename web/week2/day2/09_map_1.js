// Array.map(콜백함수)

const arr = [1, 2, 3, 4, 5];
let arrSquare = arr.map((value) => value*value)
console.log(arr)
console.log(arrSquare)

const arr2 = ["a", "bcd", "ef", "g"]
let arrLength = arr2.map(value => value.length)
console.log(arrLength)