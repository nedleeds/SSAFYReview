const friends ={
    name1 : "철수",
    name2 : "영희",
    run : (word) => console.log(word, "가자")
}

// node에서는 module화
// 특정 내용을 외부로 내보낼 수 있다
// module.exports

// 1) 내보낸다
module.exports = friends;