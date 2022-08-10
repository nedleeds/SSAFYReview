const increment = input => input + 1;
const decrement = input => input - 1;
const square = input => input * input;
const half = input => input/2;

const initValue = 1;
const pipeLine = [increment, decrement, square, half]
const result = pipeLine.reduce((acc, curr)=>{
    console.log(curr(acc));
}, initValue)