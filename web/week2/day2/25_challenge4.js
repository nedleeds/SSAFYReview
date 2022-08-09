const bucketlist = [
    {id:3, text:'여행가기', done:false},
    {id:2, text:'치킨먹기', done:true},
    {id:1, text:'코딩하기', done:false}
];

function toggle(id){
    return bucketlist.reduce((acc, curr)=>{
        // if(curr.id==id){
        //     curr.done = !curr.done
        // } //이렇게 해도 되고

        // 이렇게 해도 된다!
        if (bucketlist.id == id)
            return {...bucketlist, done:!bucketlist.done}

        return acc;
    }, [])
}

toggle(2);

console.log(bucketlist);