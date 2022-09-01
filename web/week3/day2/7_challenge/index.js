const express = require('express');
const cors = require('cors');

const PORT = 8080;

const app = express();

app.use(cors());

const infos =[
  {
    name: "나나",
    age: 12
  },
  {
    name: "유진",
    age: 8
  },
  {
    name: "재범",
    age: 40
  },
]

app.get("/infos/names",(req, res) => {
  const names = infos.map(li => li.name);

  return res.json(names);
});

app.get("/infos/ages", (req, res) => {
  const ages = infos.map(li =>li.age);
  
  return res.json(ages);
})

app.get('/infos/0',(req, res) => {
  return res.json(infos[0]);
})

app.get('/infos/1',(req, res) => {
  return res.json(infos[1]);
})
app.get('/infos/2',(req, res) => {
  return res.json(infos[2]);
})




app.listen(PORT, () => console.log(`${PORT} 기동중`));