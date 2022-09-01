const mysql = require("mysql2/promise");

const pool = mysql.createPool({
    host: "13.124.115.118", //aws ip
    user:"ssafy",
    password:"ssafy_8_A",
    database:"johny",
    waitForConnections:true,
    connectionLimit: 10,
    queueLimit: 0,
});

module.exports = {pool};