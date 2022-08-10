function ingredient(ms, sentence){
    return new Promise((resolve, reject)=>{
        setTimeout(() => {resolve(console.log(sentence))}, ms)
        //여기서 ms가 setTimeout의 인자로 들어가야돼 resolve의 인자가 아니라
    })
} 

async function hamburger(){
    await ingredient(1000, "참깨빵 위에")
    await ingredient(2000, "순쇠고기 패티 2장")
    await ingredient(3000, "특별한 소스")
    await ingredient(4000, "양상추")
    await ingredient(5000, "치즈 피클 양파")
}

hamburger();