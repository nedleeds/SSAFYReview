class Hero{
    constructor(hp){
        this.hp = hp;
    }
    showHP(){
        console.log("HP: " + this.hp)
    }
    run(){
        this.hp -= 10;
    }
}

const hero1 = new Hero("100");
hero1.showHP();
hero1.run();
hero1.run();
hero1.showHP();