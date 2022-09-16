const express = require('express');
const app = express();
const cors = require('cors');
const axios = require('axios');
const fs = require('fs');

const dotenv = require('dotenv');
dotenv.config();

const morgan = require('morgan');
const { generateKeySync } = require('crypto');
const PORT = 8000;

app.use(cors());
app.use(morgan('dev')); // log 를 위해 사용
app.use(express.json()); // body 요청을 위해 사용

app.get("/", (req, res) => {
    console.log(process.env.CLIENT_ID);
    console.log(process.env.CLIENT_SECRET);
    return res.json({test: "HELLO"});
})

app.post("/data", async (req, res) => {
    try {
        const api_url = 'https://openapi.naver.com/v1/datalab/search';
        const {startDate, endDate, timeUnit, device, gender, keywordGroups} = req.body;
        // req.body.stateDate
        const request_body = {
            "startDate": startDate,
            "endDate": endDate,
            "timeUnit": timeUnit,
            "keywordGroups": keywordGroups,
            // device
            "device": device === "all" ? "" : device,
            "gender": gender === "all" ? "" : gender
        };
        
        const headers = {
            'X-Naver-Client-Id': process.env.CLIENT_ID,
            'X-Naver-Client-Secret': process.env.CLIENT_SECRET,
            'Content-Type': 'application/json'
        };

        
        const result = await axios.post(api_url, request_body, {
            headers:headers
        });
        // console.log(result);
        
        // poost로 요청받은 result 값을 chart.json 형식으로 파일에 저장
        // get 요청할 때마다 chart.json을 읽어서 받아오기
        // JSON.stringfy -> .json 파일을 문자열로 변환
        // JSON.parse -> 문자열화 된 JSON 을 json으로 변환
        
        fs.writeFile("./uploads/chart.json", JSON.stringify(result.data['results']), function(err){
                console.log(err);
            })
            
            
            
        return res.json(result.data);
    } catch (error) {
        console.log(error)
        return res.json({error: error});
    }
    
})

app.get('/data', (req, res) => {
    try{
        fs.readFile('./uploads/chart.json', 'utf-8', (err, data) => {
            if (err) {
                console.log(error);
            }
            return res.json(JSON.parse(data)); // 문자열화 된 JSON 을 json으로 변환
        });

    }catch(error){
        console.log(error);
        return res.json(error);
    }
})

app.delete('/data', (req, res)=>{
    try{
        fs.unlink('./uploads/chart.json', (err)=>{
            if(err){
                console.log(err);
                return res.json({result:"FAIL"});
            }
            return res.json({result:"OK"});
        })
    }catch (error){
        console.log(error);
        return res.json(error);
    }
})

app.listen(PORT, () => console.log(`${PORT} 서버 기동중`))


/*
const express = require('express');
const app = express();
const cors = require('cors');
const axios = require('axios');

const fs = require('fs');

const dotenv = require('dotenv');
dotenv.config();

const morgan = require('morgan');
const PORT = 8000;


app.use(cors());
app.use(morgan('dev'));
app.use(express.json());

app.get("/", (req, res) => {
  console.log(process.env.CLIENT_ID);
  console.log(process.env.CLIENT_SECRET);
  return res.json({test: "HELLO"});
})

app.post("/data", async(req, res) => {
  const api_url = 'https://openapi.naver.com/v1/datalab/search';
  const {startDate, endDate, timeUnit, device, gender, keywordGroups} = req.body;
// req.body.starteDate

  const request_body = {
    "startDate": startDate,
    "endDate": endDate,
    "timeUnit": timeUnit,
    "keywordGroups": keywordGroups,
    "device": device,
    "gender": gender
};

const headers = {
  'X-Naver-Client-Id': process.env.CLIENT_ID,
  'X-Naver-Client-Secret': process.env.CLIENT_SECRET,
  'Content-Type': 'application/json'
}

const result = await axios.post(api_url, request_body, {
  headers:headers
});
console.log(result);

// post로 요청받은 result값을 chart.json형식으로 파일에 저장
// get 요청할때마다 chart.json을 읽어서 받아오기 
// JSON.stringify -> JSON 을 문자열로 변환
// JSON.parse -> 문자열화 된 JSON을 json으로 변환
fs.writeFile("./uploads/chart.json", JSON.stringify(result.data['results']), function(err){
  console.log(err);
})

return res.json(result.data);



})



app.listen(PORT, () => console.log(`${PORT} 서버 기동중`));
*/







// const express = require('express');
// const app = express();
// const cors = require('cors');
// const axios = require('axios');
// const morgan = require('morgan');
// const fs = require('fs');
// const dotenv = require('dotenv');
// dotenv.config();
// const PORT = 8000;  

// app.use(cors());
// app.use(morgan('dev'));
// app.use(express.json());

// app.get("/", (req, res) => {
//   return res.json({test: "HELLO"});
// });

// app.post("/data", async(req, res) => {
//   const api_url = 'https://openapi.naver.com/v1/datalab/search';
//   const {startDate, endDate, timeUnit, device ,gender, keywordGroups} = req.body;
//   const request_body = {
//       "startDate": startDate,
//       "endDate": endDate,
//       "timeUnit": timeUnit,
//       "keywordGroups": keywordGroups,
//       "device": device,
//       "gender": gender
//   };

//   const headers = {
//     'X-Naver-Client-Id': process.env.CLIENT_ID,
//     'X-Naver-Client-Secret': process.env.CLIENT_SECRET,
//     'Content-Type': 'application/json'
//   }

//   const result = await axios.post(api_url, request_body, {
//     headers: headers
//   });

//   //console.log(result);

//   fs.writeFile("./uploads/chart.json",
//     JSON.stringify(result.data['results']),
//     function(err){console.log(err);}
//   );

//   return res.json(result.data);
// });

// app.get('/data', (req, res) => {
//   fs.readFile('./uploads/chart.json', 'utf8', (err, data) => {
//     if(err) {
//       console.log(err);
//       return res.json({result: "FAILED"})
//     }
//     return res.json(JSON.parse(data));
//   })
// });

// app.delete('/data', (req, res) => {
//   fs.unlink('./uploads/chart.json', (err) => {
//     if(err){
//       console.log(err);
//       return res.json({result: "FAILED"});
//     }
//     return res.json({result: "Deleted"});
//   })
// });

// app.listen(PORT, () => console.log(`${PORT} port running`));
