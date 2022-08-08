class Hero{
    constructor(){
        this.hp = 100;
    }

    run(){
        this.hp = this.hp - 10;
    }
}

// 상속 -> extends로 받아올 수 있다.
class Superman extends Hero{
    fly(){
        console.log('fly');
        console.log(this.hp);
    }
}

const superman = new Superman();
superman.run();
superman.fly();
