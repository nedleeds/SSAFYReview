const mysql = require("mysql2/promise");

const pool = mysql.createPool({
    // aws ip, local 환경이면 127.0.0.1
    host: "13.124.115.118",
    //port는 default값 - 3306
    user: 'ssafy', 
    password: 'ssafy_8_A',
    database: 'jony',
    waitForConnections: true,
    connectionLimit: 10,
    queueLimit: 0
});

module.exports = {pool}; 

// 외부에서 받아올 때는 const {pool} = require("./db/index.js")

// module.exports = pool;
// 외부에서 받아올 때는 const pool = require("./db/index.js")
