const express = require('express');
const cors = require('cors');
const app = express();
const PORT = 8080;

app.use(cors());

app.get("/", (req, res) => {

    console.log(__dirname);
    //__dirname
    // 현재 기기에서 작동중인 서버의 절대 경로를 의미
    // 각 기기마다 서버의 경로가 다르기 때문에 __dirname을 활용
    // __dirname + 폴더 경로를 활용해서 절대 경로를 만듦

    return res.sendFile(`${__dirname}/views/index.html`)
    // return res.json({
    //     path:__dirname
    // })

})

app.get("/login", (req, res) => {
    return res.sendFile(`${__dirname}/views/login.html`);
})
app.get("/whoami", (req, res) => {
    return res.sendFile(`${__dirname}/views/whoami.html`);
})

app.listen(PORT, () => console.log(`${PORT} 서버 기동중`))