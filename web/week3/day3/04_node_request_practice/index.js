const cors = require("cors");
const morgan = require("morgan");
const express = require("express");

const PORT = 8080;
const app = express();

app.use(cors());
app.use(morgan('dev'));
app.use(express.json());

// GET /user/123?name=chiken
app.get("/user/:id", (req, res)=>{
    try{
        return res.json({
            getid:true,
            id: req.params.id,
            name: req.query.name
        });
    }catch(error){
        return res.json({getid:false})
    }
})

// POST
app.post('/user', (req, res) => {
    try{
        return res.json({
            signup: true,
            id: req.body.id,
            password: req.body.password
        });
    }catch(error){
        return res.json({signup: false})
    }
} )

//PATCH
app.patch('/user:id', (req, res) => {
    try{
        return res.json({
            update: true,
            id: req.params.id,
            name: req.body.name
        })
    }catch(error){
        return res.json({update: false})
    }
} )

// DELETE
app.patch('/user:id', (req, res) => {
    try{
        return res.json({
            delete: true,
            id: req.params.id
        });
    }catch(error){
        return res.json({delete: false})
    }
} )

app.listen(PORT, () => console.log(`${PORT} 가동중`))
