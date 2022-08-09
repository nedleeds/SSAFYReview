// 외부 데이터를 비동기로 2군데서 가져온다

// 첫번째 데이터를 받아온 상태에서
// 두번째에 인자를 보내서 호출을 해야한다.
setTimeout(()=>{
    console.log('HI')
    setTimeout(()=>{
        console.log('First')
        setTimeout(()=>{
            console.log('Second')
            setTimeout(()=>{
                console.log('Third')
            },2000)
        }, 1000)
    }, 500)
})