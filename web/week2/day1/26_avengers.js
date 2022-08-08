class Person{
    constructor(name, hp){
        this.name = name;
        this.hp = hp;
    }

    hello(){
        console.log("hero: " + this.name);
    }
}

class Avengers extends Person{
    constructor(name, hp, power, skill){
        super(name, hp);
        this.power = power;
        this.skill = skill;
    }
    information(){
        super.hello();
        console.log("power: "+this.power);
        console.log("skill: "+this.skill);
    }
    fly(){
        console.log("비행중");
    }
}

const thor = new Avengers('토르', 1000, 9999, '망치 던지기');
thor.information();
thor.fly();