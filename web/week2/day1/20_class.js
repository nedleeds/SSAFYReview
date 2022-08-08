//class를 정의할 때는 규칙이 있다. 첫글자 대문자!!
class Human{
    // 생성자
    constructor(name){
        this.name = name;
    }

    // 메서드
    sayMyName(){
        console.log("이름: " + this.name);
    }
}

const person1 = new Human("이온유");
person1.sayMyName();
const person2 = new Human("이동형");
person2.sayMyName();
const person3 = new Human("이정재");
person3.sayMyName();