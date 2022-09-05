const cors = require("cors");
const morgan = require("morgan");
const express = require("express");
const axios = require("axios");
const app = express();
const PORT = 8080;

app.use(cors());
app.use(morgan("dev"));
app.use(express.json());

// ejs 사용하기 - spring 쪽에서 많이 사용
// ejs: 템플릿 엔진
// ejs 파일을 -> 서버에서 읽어서 DB, 통신 등 모든 과정을 거쳐
// html 파일로 변환되어 리턴
// 즉, backend + client가 합쳐진 상태
app.set('view engine', 'ejs');

app.get('/',async (req, res) => {
    const result = await axios.get("https://jsonplaceholder.typicode.com/todos");
    console.log(result.data);
    res.render("index", {name: "치킨", holder: result.data})
})

app.listen(PORT, () => console.log(`${PORT} 기동 중`));