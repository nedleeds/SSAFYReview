const express = require("express");
const cors = require("cors");
const morgan = require("morgan");
const { pool } = require("./db/index");
const multer = require("multer");
const path = require("path");
const PORT = 8080;
const app = express();
const upload = multer({
    storage: multer.diskStorage({
        // 파일 업로드 위치
        destination: ( req, file, done)=>{
            // public 경로에 위치
            done(null, "public/");
        },
        // 파일 저장 양식 설정
        filename: (req, file, done) => {
            console.log(file);
            // 원본 파일 이름 + 날짜 + 확장자
            const ext = path.extname(file.originalname);
            const fileNameExceptExt = path.basename(file.originalname, ext);
            const saveFileName = fileNameExceptExt + Date.now() + ext;
            done(null, saveFileName);
        }
    })
})

// cors setting
app.use(cors());            
// http log 받아오기
app.use(morgan("dev"));     
// body data 받아오기
app.use(express.json());    
// 전역 폴더 세팅 --> 밑의 "/pulbic" 은 router 경로 
// 주소창에 입력되는 주소
app.use("/public", express.static("public"))

// 해당 router 경로(/api/menus)로 도착하면 async() + await
app.get("/api/menus", async(req, res) => {
    try 
    {
        const data = await pool.query("SELECT * FROM menus");
        return res.json(data[0]);
    } 
    catch (error) 
    {
        console.log(error);
        return res.json({
            success: false,
            message: "전체 메뉴 목록 조회에 실패하셨습니다."
        })
    }
})


app.get("/api/menus/:id", async (req, res) => {
    try
    {
        // ? 와 [] 1:1 대응관계. 배열을 여러게 넣고 싶으면 ?여러개 사용
        const data = await pool.query("SELECT * FROM menus WHERE id = ?", [req.params.id])
        console.log(data[0]);
        // data[0] -> data[0][0] : 배열안의 객체에 접근 가능
        return res.json(data[0][0]);
    }
    catch(error)
    {
        console.log(error);
        return res.json({
            success: false,
            message: "메뉴 조회에 실패하였습니다."
        })
    }
})

// post("router 주소", upload, (req, res)) -> 인자별 순서대로 진행된다
// 중간에 upload.single('file')을 통해 업로드가 된다
app.post("/api/menus", upload.single('file'), async (req, res) => {
    try 
    {
        console.log(req.file)
        console.log(req.body)
        const data = await pool.query(
            `INSERT INTO menus (name, description, image_src) 
            VALUES (?, ?, ?)`,
            [req.body.name, req.body.description, req.file.path])

        return res.json({
            success: true,
            meesage: "메뉴 등록에 성공하였습니다."
        })
    } catch (error) 
    {
        console.log(error);
        return res.json({
            success: false,
            message: "메뉴 등록에 실패하였습니다."
        })
    }
})

// 수정
// id를 받아서 해당 id로 접근해서 image_src를 업데이트
app.post('/api/menus/:id/image', upload.single('file'), async (req, res) => {
    try
    {
        // 원래라면, 기존 id로 찾아서 경로를 찾아낸 후 -> 그것에 해당되는 이미지를 삭제
        const data = await pool.query(
            "UPDATE menus SET image_src = ? where ID = ?", 
            [req.file.path, req.params.id]
        );
        return res.json({
            success: true,
            message: "메뉴 이미지 수정에 성공하였습니다."
        });
    }
    catch(error)
    {
        console.log(error);
        return res.json({
            success: false,
            message: "메뉴 이미지 수정에 실패하였습니다."
        })
    }
})

app.patch("/api/menus/:id", async(req, res) => {
    try 
    {
        // patch는 특정 id를 찾아서 해당 id의 정보를 수정해야한다
        // (where id = req.params.id)
        const data = await pool.query("UPDATE menus SET name =?, description =? where id =?", [req.body.name, req.body.description, req.params.id])
        return res.json({
            success: true,
            message: "메뉴 정보 수정에 성공하였습니다."
        })
    }
    catch (error) 
    {
        console.log(error);
        return res.json({
            success: false,
            message: "메뉴 정보 수정에 실패하였습니다."
        })
    }
})

app.delete("/api/menus/:id", async(req, res) => {
    try
    {
        const data = await pool.query("DELETE FROM menus WHERE id = ?", [req.params.id])
        return res.json({
            success:true,
            message: "메뉴 삭제에 성공하였습니다."
        })
    }
    catch(error)
    {
        console.log(error)
        return res.json({
            success: false,
            message: "메뉴 삭제에 실패하였습니다."
        })
    }
})

// orders 파트

app.get("/api/orders", async (req, res) => {
    try{
        // LEFT JOIN
        // INNER JOIN -> null 로 된 결과물은 가져오지 않는다
        // a.id 라고 하는 이유, orders.id 인지 menus.id 인지 모르기 때문
        // 나머지 특성은 두 table 간 겹치는 column이 아니기 때문
        const data = await pool.query(`
            SELECT a.id, quantity, request_detail, name, description
            FROM orders as a
            INNER JOIN menus as b
            ON a.menus_id = b.id
            ORDER BY a.id DESC
        `)
        return res.json(data[0]);

    }catch(error){
        console.log(error);
        return res.json({
            success: false,
            message: "전체 주문 목록 조회에 실패하였습니다."
        })
    }
})

app.post("/api/orders", async (req, res) => {
    try {
        // quantity (수량)
        // request_detail (주문시 요청사항)
        // menus_id (DB에 menus_id를 저장)
        const data = await pool.query(`
            INSERT INTO orders (quantity, request_detail, menus_id) VALUES (?, ?, ?)`, 
            [req.body.quantity, req.body.request_detail, req.body.menus_id]    
        );
        return res.json({
            success: true,
            message: "주문에 성공하였습니다."
        });
    }catch (error){
        console.log(error);
        return res.json({
            success: false,
            message: "주문에 실패하였습니다."
        });
    }
})


app.listen(PORT, () => console.log(`${PORT} 기동 중`));