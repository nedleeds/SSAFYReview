class Hero{
    constructor(hp){
        this.hp = hp;
    }

    walk(){
        console.log("조금 빠르게 걷기")
    }

    run(){
        this.hp = this.hp - 10;
        console.log(this.hp);
    }
}

// 상속 -> extends로 받아올 수 있다.
class Superman extends Hero{
    constructor(hp, mp){
        super(hp);
        this.hp = hp;
        this.mp = mp;
    };

    walk(){
        super.walk(); // 상위 클래스 메서드 사용하기.
        console.log("완전 빠르게 걷기")
    }

    fly(){
        console.log('fly');
        console.log(this.hp);
    }
}

const superman = new Superman(100, 100);
superman.walk();
