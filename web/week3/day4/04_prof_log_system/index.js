const express = require('express');
const morgan = require('morgan');
const cors = require('cors');
// Node의 내장 모듈;
const fs = require('fs')

const { logger } = require("./utils")

const app = express();
const PORT = 8080;
app.use(cors());
app.use(morgan('dev'));
app.use(express.json());

// Ctrl + P (파일 검색)
// Ctrl + Shit +f (내용 전체 검색)

function insert(str, index, target) {
  const front = str.slice(0, index);
  const back = str.slice(index, str.length);
  return front + target + back;
}


app.get("/api/logs/:date", (req, res) => {
  console.log(req.params.date);
  let resultData = null;
  fs.readFile(`./logs/${req.params.date}.log`, "utf8", (err, data) => {
    resultData = data;
    let index = -1;

    while(1){
      index = resultData.indexOf("}", index +1);
      if(index === -1){
        break;
      }
      resultData = insert(resultData, index+1, ",");
    }

    resultData = "["+ resultData.slice(0, resultData.length -3) +"]";
    console.log(resultData);
    // 문자열 -> JSON으로 만들어주기
    resultData = JSON.parse(resultData);
    return res.json(resultData);
  })
  


  // return res.json({test:"hello"});
})

// postman 설치 
app.post("/api/logs", (req, res) => {
  logger.error("error 메시지");
  logger.warn('warn 메시지');
  logger.info("info 메시지");
  logger.http("http 메시지");
  logger.debug("debug 메시지");
  return res.json({
    test: "OK"
  })
})


app.listen(PORT, () => console.log(`${PORT} 기동중`));