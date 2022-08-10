// Array.reduce(콜백함수, 초기값) 초기값은 생략이 가능하다.
// 초기값은 숫자뿐만 아니라 문자, 배열, 빈객체 모든 것이 가능하다.

// Array.reduce((acc, cur, index) => {}, "초기값")

// acc 첫번째 인자 = 누산기 acc에 값을 담아서 출력
// cur 두번째 인자 = 출력하는 현재 값 
//                (amp, filter, forEach 등의 첫번째 값과 동일)
// index 세번째 인자 = 출력하는 인덱스

const arr = [1,2,3,4,5,6,7,8,9,10];
const filterMapArray = arr.filter(value => (value%2===0)).map(value => value*10);

const arr2 = [1,2,3,4,5,6,7,8,9,10];
const reduceFilterArray = arr2.reduce((acc, cur)=>{
    if (cur % 2 ===0){
        acc.push(cur*10);
    }
    return acc;
}, [])

console.log(filterMapArray)
console.log(reduceFilterArray)