const helloPromise = new Promise((resolve, reject)=>{

})

console.dir(helloPromise);

// pending
// at the moment when we make Promise object, 
// the status is set to 'pending' status
new Promise((resolve, reject) => {}) // pending상태

// resolve
// change status from pending to fulfilled(이행) status
new Promise((resolve, reject)=>{
    resolve(); // changed to fulfilled
})


// reject
// when request has been rejected and try to implement,
// then you will get the rejected status
new Promise((resolve, reject)=>{
    reject(); // make rejected status
})


// [setTimeout] => [promise]
const delay = (ms) => {
    return new Promise((resolve, reject) => {
        return setTimeout(() => {
            resolve();
        }, ms)
    })
}

// promise 는 호출하고 나서
// 이행된 상태에서는 then을 붙이고
// 이행되지 않은 reject 상태에서는 catch를 붙인다
delay(1000).then(()=>{
    console.log("1초 후 실행")
}) //1000ms delay 하고 나면 then 실행

// resolve에 인자 넣기
const delay2 = (ms) => {
    return new Promise((resolve, reject) => {
        return setTimeout(() => {
            resolve(ms);
        }, ms)
    })
}
delay2(3000).then((data)=>{
    console.log(data)
    console.log(`${data}ms 후 실행`)
})

// promise를 직접적으로 다룰일은 많이 없지만
// 기본 비동기에 콜백 방식으로 된 많은 코드들을
// promise 방식으로 리팩토링해서 사용하게 될 경우는 종종 있다
// 위도, 경도를 -> promise 방식으로 리팩토링 -> async await을 활용해서 순서 보장
delay2(3000).then((data)=>{
    console.log(data);
    console.log(`${data}ms 후 실행`);
    return data; // return 을 붙여야 다음 then에 data가 넘어간다.
}).then((data)=>{
    console.log("두번째 then");
    console.log(data);
    return data
}).then((d)=>{
    delay(1000).then(()=>{
        console.log("세번째 then");
        console.log(d);
    })
})

// reject 상태에 대한 대응
const rejectDelay = (ms) => new Promise((resolve, reject) => setTimeout(() => {
    reject(ms);
}, ms)) // 화살표 함수에서 {} 없으면 오른쪽 값 return

// reject -> 이행 실패 상태 -> 에러메세지를 담아서 출력하는 경우가 많다
rejectDelay(1000).then(data => {
    console.log("fulfilled")
    console.log(data);
}).catch(data => {
    console.log('rejected');
    console.log(data);
})
