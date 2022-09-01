const cors = require("./src/node_modules/cors");
const morgan = require("./src/node_modules/morgan");
const express = require("./src/node_modules/express");
const multer = require('./src/node_modules/multer');

const upload = multer({
    storage: multer.diskStorage({
        destination: (req, file, done) => {
            done(null, "../public/")
        },  // 업로드 되는 파일 저장
        filename:(req, file, done) =>{
            done(null, file.originalname)
        },        // 업로드 되는 파일의 이름 지정
        limits:{}               // 업로드 되는 파일의 사이즈 limit
    })
})

const PORT = 8080;
const app = express();

app.use(cors());
app.use(morgan('dev'));
app.use(express.json());

// public 경로로 오면 express의 public 폴더를 보여주겠다
app.use("../public", express.static("public"));

// upload.single('key값') - > 하나만 올린다
// 파일 업로드는 POST 요청으로만 해야한다
app.post("/api/file", upload.single('file'), (req, res) => {
    return res.json({ test: "OK"})
})


app.listen(PORT, () => console.log(`${PORT} 가동중`))