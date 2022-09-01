const express = require('express');
const cors = require('cors');
const app = express();
const PORT = 8080;

app.use(cors());

const informations = [
    {name:"치킨", type: "food"},
    {name:"마라탕", type: "food"}
]

app.get("/test", (req, res)=>{
    return res.json(informations);
})

app.listen(PORT, () => console.log(`${PORT} 서버 기동중`));