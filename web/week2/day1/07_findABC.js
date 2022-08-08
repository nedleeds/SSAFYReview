const k = "ABCABCMCABCABCMCBBQABC";
let a = -1;
let cnt =0;

while(1){
    a = k.indexOf('ABC', a+1);
    if (a === -1) 
        break;
    else 
        cnt += 1;
}

console.log(cnt);