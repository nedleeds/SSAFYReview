// 비구조화 할당
// 구조분해 할당
// 객체 안에 있는 값을 추출해서 변수 상수로 선언하는 방식

const abc = {
    name: "치킨",
    type: "후라이드"
}
// abc.name or abc['name'] 으로 접근했었다

// 객체의 desctruction
// abc 객체 안의 요소를 추출한다 --> vue에서 많이 사용
// 객체의 key 값과 변수 이름이 같아야 추출 가능하다
const {name, type} = abc;
console.log(name, type);

// 배열의 desctruction
// 배열의 구조분해할당은 객체와 다르게 
// 순서 보장이 되어있기 때문에 
// 임의의 변수를 등록해도 가능하다.
const array = [1,2,3,4];
const [one, two, three, four] = array;