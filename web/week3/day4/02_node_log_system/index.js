const cors = require("cors");
const morgan = require("morgan");
const express = require("express");
const {logger} = require("./utils")
const fs = require('fs');

const app = express();
const PORT = 8080;

app.use(cors());
app.use(morgan("dev"));
app.use(express.json());

function insert(str, index, target){
    const front = str.slice(0, index);
    const back = str.slice(index, str.length);
    return front + target + back;
}

app.get("/api/logs/:date", (req, res) => {
    console.log(req.params.date);
    let resultData = null;
    fs.readFile(`./logs/${req.params.date}.log`, 'utf-8', (err, data) => {        
        resultData = data;
        let index = -1;
        while(1){
            index = resultData.indexOf("}", index + 1);
            if (index === -1 ){
                break;
            }
            resultData = insert(resultData, index+1, ",");
        }
        resultData = "[" + resultData.slice(0, resultData.length -3) + "]";
        // console.log(resultData);
        // 문자열 -> json으로 만들어주기
        resultData = JSON.parse(resultData);
        return res.json(resultData);
    })
    // return res.json({test:"hello"});
})

app.post("/api/logs", (req, res) => {
    logger.error("error 메세지");
    logger.warn('warn 메세지')
    logger.info('info 메세지')
    logger.http('http 메세지')
    logger.debug('debug 메세지')

    return res.json({
        test: "OK"
    })
})



app.listen(PORT, () => console.log(`${PORT} 기동 중`));