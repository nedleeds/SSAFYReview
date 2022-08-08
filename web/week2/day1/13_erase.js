function erase(src, start_idx, amounts){
    const a = src.substring(0, start_idx);
    const b = src.substring(start_idx+amounts, src.length);
    return a+b;
}

function erase_target(src, target){
    const idx = src.indexOf(target);
    const b = src.substring(0, idx);
    const c = src.substring(idx+target.length, src.length);
    return b + c;
}

const a ="aabbccde"
console.log(erase_target(a, "bc"))
console.log(erase(a, 1, 2))