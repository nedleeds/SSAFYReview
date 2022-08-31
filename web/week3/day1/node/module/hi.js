// module.exports로 가져온 내용을 가져온다
// node 명령어 실행 시 현재 경로 파악 !!
// require('경로')

// // 2) lib.js에서 내보낸 걸 받아온다.
// const lib = require('./lib'); // './lib.js 인데 .js는 생략가능하다
// console.log(lib);

const {name1, name2, run} = require("./lib");
console.log(name1);
console.log(name2);