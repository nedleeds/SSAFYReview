// 참고로 package-lock.json, package.json이 있으면
// 명세서가 있으므로 "npm i" 명령어로 
// github 에 용량 이슈로 업로드 못한 node_modules를 
// 그대로 복구할 수 있다

// 익스프레스를 가져온다
const express = require('express');

// express 실행
const app = express();

const PORT = 8080;

// 요청이 받아와지는 부분
// app.get("주소", (req, res) => {

// })


// 주소로 요청이 도착하면 콜백함수(요청, 응답) => {} 실행
// req: request 말그래도 요청.
// client가 주소 창에 localHost:8080(현재 웹 포트)에다가 / 요청이 들어오면
// 즉, 기본페이지(localHost:8080/)에 들어가면 
// app.get("/", (req, res)) 중 req에 요청이 도착했다는 것이고, 
// result 값을 반환 한다. 
app.get("/", (req, res) =>{
    return res.json({
        menu1: "사골버섯전골",
        menu2: "마파두부덮밥"
    })
})

// 여기선 app.get("/api/info", (req, res)) 에 req 가 들어오게 된다면
// 즉, localHost:8080/api/info 를 주소창에 쳐서 client가 request를 보내게 된다면
// result를 동작시킨다.
app.get("/api/info", (req, res)=>{
    return res.json({
        chicken: "치킨은 늘 옳다"
    })
})

// 명시한 PORT로 서버를 기동
app.listen(PORT, () => console.log(`${PORT} 서버 기동 중`))