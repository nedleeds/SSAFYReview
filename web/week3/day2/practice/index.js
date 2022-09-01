const express = require("express");
const cors = require("cors");
const { pool } = require("./db");
const app = express();
app.use(cors());
const PORT = 8080;

app.get("/api/menu", async(req, res) => {
    try{
        const data = await pool.query("SELECT * FROM new_table");
        if(data[0]){
            return res.json(data[0]);
        }
    }catch(error){
        return res.json(error);
    }
});

app.listen(PORT, () => console.log(`this server listening on ${PORT}`));