const bucketlist = [
    {id:3, text:'여행가기', done:false},
    {id:2, text:'치킨먹기', done:false},
    {id:1, text:'코딩하기', done:false}
];

// reduce로 사용
// function allTrue(){
//     return bucketlist.reduce((acc, curr)=>{
//         curr.done = true;
//         acc.push(curr);
//         return acc;
//     }, [])
// }

// map사용
function allTrue(){
    return bucketlist.map(bucketlist=>{
        return {...bucketlist, done:true}
    })
}

console.log(allTrue());