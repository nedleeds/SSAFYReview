console.log("어서오세요");
console.log("주문하세요");
console.log("고민하는 동안 다른 걸 하고 있을게요");

const pro = new Promise((resolve, reject) => {
    setTimeout(()=>{
        console.log("주문 할게요 !");
        // resolve("치킨");
        reject('엄마가 불러요')
    }, 3000)
})

pro.then((data) => {
    // 주문을 성공적으로 한 경우
    console.log(`${data}로 할게요`);
}).catch((error) => {
    console.log(error);
    console.log("저는 이만 가보겠습니다");
})
