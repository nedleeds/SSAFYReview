const mysql = require('mysql2/promise');

const pool = mysql.createPool({
    // aws의 ip가 기입된다
    // local 환경이면 localhost or 127.0.0.1 기입

    host : '3.37.88.128',
    // mysql username 입력
    user : 'ssafy',
    //비번
    password: 'ssafy_8_A',
    // 스키마 및 DB 이름,
    database: 'johny',
    waitForConnections:true,
    connectionLimit: 10,
    queueLimit:0
});

module.exports = pool;