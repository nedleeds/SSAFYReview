// async, await 를 활용하기 위해서는 해당 모듈이 promise 형식으로 리턴이 되어야한다
const mysql = require("mysql2/promise"); 

const pool = mysql.createPool({
    host: "3.39.6.173",
    user: "ssafy",
    password: "ssafy_8_A",
    database: "order_system",
    waitForConnections: true,
    connectionLimit: 10,
    queueLimit: 0
})

module.exports = { pool }