// setTimeout(콜백함수, 지연시킬 시간)

// 완전 정확한 3초는 아니다
// callstack으로부터 비워져있다가 다시 callstack까지
// 보내는 타이밍이 존재하기 때문
setTimeout(() => {
    console.log("빨래")
}, 3000);

console.log("설거지")

// setInterval(콜백함수, 지연시간)
// 지연시간마다 해당 콜백함수 반복
setInterval(()=>{
    console.log("기러기 토마토 스위스")
    // 이부분 채워야돼
})