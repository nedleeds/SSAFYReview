// some
// 하나만 만족해도 true를 리턴
// forEach는 요소 하나씩 접근하는게 끝이었다면,
// some, every는 true/false를 리턴한다!
const array = [1, 2, 3, 4, 5]
console.log(array.some(element => element>4))
console.log(array.some(element => element<0))

// 위의 두 코드는
array.some(element=>{
    if (element > 4){
        console.log(element>4);
        return element;
    }
})

// return 이 들어간 상태 -> return 을 아무것도 안하면,
// undefined를 return 그럼 이 undefined가 false로 인식될 수 있다.
array.some(element=>{
    if (element < 0){
        console.log(element<0)
        return element;
    }
})

// every
// 모두 만족해야 true를 리턴

let flag2 = true;
let flag = true;
for (let i=0; i<array.length; i++){
    if(array[i] < 0){
        flag = false;
        break;
    }
}
console.log(flag);
//flag가 true면 모두 만족한다
console.log(
    array.every(element => element < 0)
);

console.log(
    array.every (element => element > 4)
);
