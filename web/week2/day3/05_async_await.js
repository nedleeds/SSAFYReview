// promise를 사용해도 
// 여전히 존재하는 chain hell
// 그래서 async + await가 등장

function eat(){
    return new Promise((resolve, reject) => {
        setTimeout(()=>resolve("먹어"), 2000);
    })
}

// async await
// -> 쓰읍! 기다려 !! -> 먹어!!
// async await 를 활용하기 위해서는 
// 무조건 함수 앞에 async를 붙여야한다
// async가 있어야만 await 동작한다
async function wait(){
    console.log("기다려~")
    const data = await eat();
    console.log(data);
    console.log("굿보이~")
}

wait()
// promise 에서 then catch 형태였는데
// async await 상태에서는 rejected 상황을 잡기 위해서는
// try catch{}
function eat2(){
    return new Promise((resolve, reject) => {
        setTimeout(()=>reject("안먹어"), 2000);
    })
}
async function wait2(){
    try{
        console.log("기다려!!")
        const data = await eat2();
        console.log(data);
        console.log("잘했어");

    }
    catch(error) // catch안에 Rejected가 담긴다.
    {
        console.log(error)
    }
}
wait2()