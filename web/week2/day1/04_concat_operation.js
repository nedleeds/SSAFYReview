const a = "ABCMINMIN";
const b = "BBQCOCO";

const c = a+b;

const s = [];
for (let i=c.length-1; i>=0; i--){
    if (i%2==0)
        s += c[i]+',';
}
s[s.length-1] = '';
alert(s);