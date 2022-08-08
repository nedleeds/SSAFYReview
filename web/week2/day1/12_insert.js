function insert(str, index, target){
    const a = str.substring(0, index);
    const b = str.substring(index, str.length);
    return a+target+b;
}

const a = "abcdef";
console.log(insert(a, 3,'A'));
