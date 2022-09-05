// winston: 로그 라이브러리
// winston-daily-ratate-file 로그 관리 라이브러리
const winston = require("winston");
require('winston-daily-rotate-file');

const moment = require("moment");


// console.log
// 서버가 종료되면 날아가고 찾기도 힘들다
// 따라서 해당 오류를 파일로 남긴다
const transport = new winston.transports.DailyRotateFile({
    level: 'info',
    datePattern: 'YYYY-MM-DD-HH',
    filename: './logs/%DATE%.log',
    zippedArchive: true,
    maxSize: '20m',
    maxFiles: '1d',
    format: winston.format.combine(
        winston.format.timestamp({
            format: moment().format("YYYY-MM-DD HH:mm:ss")
        }),
        winston.format.json()
    )
})

const logger = winston.createLogger({
    transports: [transport]
}); // logger 객체 설정

module.exports = {logger} // logger 객체 내보내기