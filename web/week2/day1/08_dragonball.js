const k = "BTSMINBTSMINBTSKKOPSM";
const f = ["SM", "MIN", "OP", "VO", "TSM"];

let cnt = [-1, -1, -1, -1, -1];
for (let idx = 0; idx < k.length; idx++){
    if (k.indexOf(f[0]) !== -1){
        cnt[0]++;
    }
    if (k.indexOf(f[1]) !== -1){
        cnt[1]++;
    }
    if (k.indexOf(f[2]) !== -1){
        cnt[2]++;
    }
    if (k.indexOf(f[3]) !== -1){
        cnt[3]++;
    }
    if (k.indexOf(f[4]) !== -1){
        cnt[4]++;
    }
}

let M = -2134567890;
let M_idx = -1;
for (let i=0; i<cnt.length; i++){
    if (M < cnt[i]){
        M = cnt[i];
        M_idx = i;
    }
}
console.log(f[M_idx]);
