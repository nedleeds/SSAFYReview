function sleep(delay){
    const start = Date.now();
    console.log(start);
    const limit = start + delay;

    while(Date.now() < limit){

    }
}
console.log('시작~')
sleep(3000);
console.log('~끝')