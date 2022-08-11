function macdonald(ms){
    return new Promise((resolve, reject) => {
        return setTimeout(()=>{
            resolve();
        }, ms)
    })
}

macdonald(3000).then(() => "참깨빵 위에 ")
.then((element) => element + ("순 쇠고기 패티 2장 "))
.then((element) => element + ("특별한 소스 "))
.then((element) => element + ("양상추 "))
.then((element) => element + ("치즈 피클 양파"))
.then((element)=>console.log(element))