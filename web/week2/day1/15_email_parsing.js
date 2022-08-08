const mail = "bts@macdonald.co.kr||inho@mincoding.co.kr||jason@jyp.com";

const result = mail.replace(/.co.kr|.com/g, ".net");
console.log(result)

const result2 = mail.split("||");
console.log(result2)

for (let i=0; i<result2.length; i++){
    let start_idx=0;
    end_idx = result2[i].indexOf("@");
    console.log(result2[i].substring(start_idx, end_idx));
}
