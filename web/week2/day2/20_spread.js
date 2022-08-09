// 객체의 spread
const square = {
    width: 200,
    height: 200
}

const colorSquare = {
    // width: 200,
    // height: 200, <-- 대신에
    ...square, //square의 내부 변수를 가져다 쓴다.
    color: 'red'
}

const catTypeAnimals = ['고양이', '호랑이'];
const dogTypeAnimals = ['강아지', '늑대'];
const allTypeAnimals = [...catTypeAnimals,
                        ...dogTypeAnimals, 
                        '비버'];