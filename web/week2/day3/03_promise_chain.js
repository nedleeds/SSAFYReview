function plus(){
    return new Promise((resolve, reject) => {
        resolve(0);
    })
}

// promise 체이닝을 활용해서 1부터 5까지 덧셈을 해보자
// 1)plus() 처음 호출 시 pending  2)끝났네? 그럼 ~ 이 부분이 then
plus().then(sum => { 
    console.log(sum);
    return sum + 1;
})
.then(sum => {
    console.log(sum)
    return sum + 2
})
.then(sum => {
    console.log(sum)
    return sum + 3
})
.then(sum => {
    console.log(sum)
    return sum + 4
})
.then(sum => sum + 5)
.then(sum => sum + 6)
.then(sum => sum + 7)
.then(sum => sum + 8)
.then(sum => sum + 9)
.then(sum => console.log(sum));