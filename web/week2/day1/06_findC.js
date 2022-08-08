// 'C' 출력하기
// 1. 첫번째 'C'가 등장하는 인덱스 출력
// 2. 'C'가 등장하는 모든 인덱스 출력

const a = "KFCOCOBBQMINMINC";
const r= [];

// 1. 답
let ans = a.indexOf('C',0);

// 2. 내 답
for (let i=0; i<a.length; i++){
    if (a[i]=='C'){
        r.push(i);
    }   
}

// 3. 교수님 답

while(1){
    a1 = str.indexOf("C", a1+1);
    if (a1===-1) break;
    array.push(a1);
}

console.log(ans);
console.log(r);
console.log(array);