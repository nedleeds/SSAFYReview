const arr = ["피카츄", "라이츄", "파이리", "꼬부기", "피카츄", "라이츄"]

const results = arr.reduce((acc, cur)=>{
    // if(!값) -> 부정
    // if(값) -> 긍정
    if (acc[cur]){
        acc[cur] = acc[cur] + 1;
    }else{
        acc[cur] = 1;
    }

    return acc;
}, {})