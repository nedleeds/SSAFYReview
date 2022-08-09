// promise
// 약속

const helloPromise = new Promise((resolve, reject)=>{
    console.log(resolve);
    console.log(reject);
})

// promise의 3가지 상태
// pending - 대기
// resolve - 이행
// reject - 이행 실패