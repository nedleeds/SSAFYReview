const express = require('express');
const cors = require('cors');
const app = express();
const PORT = 8080;

const pool = require("./db/index")
// const pool = require("./db") 와 동일

app.use(cors());


app.get("/api/menus", async(req, res) => {
    try{
        const data = await pool.query("SELECT * FROM menus");
        console.log(data);
        return res.json(data);
    }catch(error){
        console.log(error);
        res.json(error);
    }
})

app.listen(PORT, () => console.log(`${PORT} 기동중`));