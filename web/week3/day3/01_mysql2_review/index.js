const express = require("express");
const cors = require('cors');
const morgan = require('morgan');
const { pool } = require("./db/index");
const app = express();
const PORT = 8080;

app.use(express.json());
app.use(cors()); // 어떤 전역에 접속하더라도 이 구문이 실행된대
app.use(morgan('dev'));

app.get("/api/menus", async (req, res) => {
    try{
        const data = await pool.query("SELECT * FROM menus");
        return res.json(data)
    }catch(error){
        console.log(error);
        return res.json(error);
    }
});

app.post('/api/menus', async (req, res) => {
    try{
        // 0) 동작체크용
        // console.log(req.body)
        // return res.json(req.body);

        // 요청을 두 가지 방식으로 보내본다.
        // 1)
        // const data = await pool.query(
        //     `
        //         INSERT INTO menus (name, description)
        //         VALUES 
        //         ("${req.body.name}", "${req.body.description}")
        //     `
        // );
        // return res.json(req.body);

        // 2)
        const data = await pool.query("INSERT INTO menus (name, description) VALUES (?, ?)",
        [req.body.name, req.body.description])
        return res.json(data);

    }catch(error){
        console.log(error);
    };
});

app.listen(PORT, () => console.log(`${PORT} 기동 중...`));