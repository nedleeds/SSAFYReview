//rest

// 객체
const chicken = {
    type: '양념',
    drumSticks: 2,
    wing: 2
}
// 앞서 배운 destructor
// const {type, drumSticks, wing} = chicken;
// rest(나머지)를 사용한 desctructor
const {type, ...etc} = chicken;

// 배열
// const {password, information} = 정보;
// 위에선 password를 제외한 모든 정보가 information이 있다
// 그럼 information 자리에 ...information 으로 추출 하는거지
// 그러고 console.log(information)하면 password를 제외한
// 데이터가 들어가 있다
const numberAPray = [0,1,2,3,4,5,6,7];
const [one, two, ...another] = numberAPray;
