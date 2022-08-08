const k = "AB[100]T[41]ABS[1][5]BTS";
let start_idx = 0;

let s=0;
while(1){
    start_idx = k.indexOf('[', start_idx+1);
    if (start_idx == -1) break;
    let end_idx = k.indexOf(']', start_idx);
    s += Number(k.substring(start_idx+1, end_idx));
}

console.log(s);
