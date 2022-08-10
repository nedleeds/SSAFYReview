const arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13];

let odd_cnt = 0;
let even_cnt = 0;
const countOddEven = arr.reduce((acc, curr)=>{
    if (curr % 2){
        if (acc['홀수']){
            acc['홀수'] += 1
        }else{
            acc['홀수'] = 1
        }
    }
    else{
        if (acc['짝수']){
            acc['짝수'] += 1
        }else{
            acc['짝수'] = 1
        }
    }
        
    return acc; // 까먹지말고 넣어줘야돼
}, {})

console.log("홀수: " + countOddEven['홀수'])
console.log("짝수: " + countOddEven['짝수'])