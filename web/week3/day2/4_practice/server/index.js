// 익스프레스를 가져온다
const express = require("express");

// express 실행 후 app 변수로 해당 객체 전달
const app = express();

// cors 패키지 가져오기

const PORT = 8080;

// app.use는 전역 실행
// cors() 상태로 실행하면 모든 접속이 허용
const cors = require('cors');

// 요청이 받아와지는 부분
// app.get("주소", (req, res) => {

// })
app.use(cors());

// 주소로 요청이 도착하면 콜백함수(요청, 응답) => {} 실행
// req: request 말그래도 요청.
// client가 주소 창에 localHost:8080(현재 웹 포트)에다가 / 요청이 들어오면
// 즉, 기본페이지(localHost:8080/)에 들어가면 
// app.get("/", (req, res)) 중 req에 요청이 도착했다는 것이고, 
// 요청에 대해 response !!
app.get("/", (req, res)=>{
    return res.json({
        menu1: "버섯사골전골",
        menu2: "마파두부덮밥"
    })
})

// 여기선 app.get("/api/info", (req, res)) 에 req 가 들어오게 된다면
// 즉, localHost:8080/api/info 를 주소창에 쳐서 client가 request를 보내게 된다면
// response, 반응한다
app.get("/api/info", (get, res)=>{
    return res.json({
        wish: "경주 가고 싶다"
    })
})


// 명시한 PORT로 서버를 기동
add.listen(PORT, () => console.log(`${PORT} 서버 기동중`));