// prompt
const result = prompt("새 문자열 입력");
console.log(result);

// 문자열 -> 배열의 형태
// split " "을 기반으로 나누기
const splitResult = result.split(" ");
console.log(splitResult);

const array = [];
for (let i=0; i< splitResult.length; i++){
    array.push(splitResult)
}



// const result = prompt("새 문자열 입력");
// const splitResult = result.split(" ");

// a1 = splitResult[0];
// a2 = splitResult[1];
// a3 = splitResult[2];
// if (a1 == a2 && a2==a3){
//     alert("Very Good");
// }else if(a1 != a2 && a2 != a3){
//     alert("Only One");
// }else{
//     alert("Two");
// }