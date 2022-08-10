// Array.reduce(콜백함수, 초기값) 초기값은 생략이 가능하다.
// 초기값은 숫자뿐만 아니라 문자, 배열, 빈객체 모든 것이 가능하다.

// Array.reduce((acc, cur, index) => {}, "초기값")

// acc 첫번째 인자 = 누산기 acc에 값을 담아서 출력
// cur 두번째 인자 = 출력하는 현재 값 
//                (amp, filter, forEach 등의 첫번째 값과 동일)
// index 세번째 인자 = 출력하는 인덱스

const data = [1,2,3,4,5];

// 초기값을 생략한 경우 index가 1부터 시작하고
// acc 첫번째 값에 배열의 첫번째 값이 들어간다.
console.log("======index 초기 값 미설정시=======");
const accResult = data.reduce((acc,cur,index)=>{
    console.log("acc: " + acc);
    console.log("cur: " + cur);
    console.log("index: " + index);
    console.log("=================");
    return acc = acc + cur;
})

console.log("======index 초기 값을 0으로=======");
const accResult2 = data.reduce((acc,cur,index)=>{
    console.log("acc: " + acc);
    console.log("cur: " + cur);
    console.log("index: " + index);
    console.log("=================");
    return acc = acc + cur;
}, 0)

// reduce로 map 같이 구현
const array = [1, 2, 3, 4]
array.reduceMapArray = array.reduce((arr, cur)=>{
    // 초기값을 배열로 해주면 배열 관련 메서드도 사용 가능하다.
    acc.push(cur*cur);
    return acc;
}, [])

//reduce로 filter 구현
// 2보다 큰 경우만 배열에 담기
const reduceFilterArray = array.reduce((acc, cur)=>{
    if (cur > 2){
        acc.push(cur);
    }
    return acc;
}, [])