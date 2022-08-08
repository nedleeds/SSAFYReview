class Lawyer{
    constructor(name, age, info){
        this.name = name;
        this.age  = age;
        this.info = info;
    }

    introduce(){
        console.log("이름: "    , this.name)
        console.log("나이: "    , this.age )
        console.log("자기소개: " , this.info)
    }
}

const person1 = new Lawyer("우영우", 27, "기러기 토마토 스위스 역삼역")
const person2 = new Lawyer("이동형", 30, "오리오 ")
person1.introduce();
person2.introduce();