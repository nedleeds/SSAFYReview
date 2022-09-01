const cors = require('cors');
const morgan = require('morgan');
const express = require('express');

const PORT = 8080;
const app = express();

app.use(cors());
app.use(morgan('dev'));

// body의 데이터를 받아오기 위한 세팅
app.use(express.json());

// 모든 유저에 대한 정보
// app.get("/api/users")

// :id 유저에 대한 정보
// :idx 값이 path에 담긴다
app.get("/api/users/:id", (req, res)=>{
    console.log(req.params);
    
    // quert
    // ?~
    console.log(req.query);
    
    return res.json({
        params: req.params,
        query: req.query
    })
})

app.post('/api/users', (req, res) => {
    console.log(req.body);
    return res.json({
        body:req.body
    })
} )


app.listen(PORT, () => console.log(`${PORT} 기동중`)); 
