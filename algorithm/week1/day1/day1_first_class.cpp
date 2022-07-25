#include <iostream>
using namespace std;

int main(){
    // 입력을 최대한 빠르게 받기 위함
    // 코딩테스트의 목표 : 최대한 빠르게 그리고 완벽하게 동작하는 코드.
    // stream 공유를 끊어줌.- 원래는 c의 scanf가 사용하는 input stream을 물어보고 빌려와.
    ios_base::sync_with_stdio(false); //이걸 쓰면 대신 scanf를 같이 못씀.
    cin.tie();
    cout.tie();
    
    // 입출력
    // cin  >> - 입력
    // cout << - 출력
    int a;
    cin >> a;
    cout << a << endl;

    // data type
    // char -> python X
    char c = 'c';
    char s[] = "string";
    // 정수
    int x = 2178542905091;
    long long x1 = 2178542905091;
    cout << x << endl << x1;
    // 팁 : 양수 찍었는데, 음수나온다? --> 변수 타입 확인 필요.

    // 실수 -> 코테에서는 실수가 잘 안나옴.
    float a1 = 3.14;
    double b1 = 3.14;
    cout << a1 << '\n' << b1 << endl;

    // python : // (몫연산자) -> C/C++ : /(몫 연산자)
    float a3 = 10 / 3;
    cout << a3 << endl; // <-- 이렇게 해도 3 나온다!!

    // 논리연산
    // and or not
    // && || ! (연산자 순서 : 1. !,  2. &&,  3. ||)
    cout << !true || false && true;

    // 조건문 : if - else if - else
    int a4 = 0;
    
    if (a4 > 0){
        cout << "양수" << endl;
    }else if (a4 == 0){
        cout << "0" << endl;
    }else{
        cout << "음수" << endl;
    }

    // python : for i in range()
    // TIP : endl 보다 "\n"이 더 빠르다. (endl-> 출력 stream flush 가 발생.)
    for (int i = 1; i <= 10; i++)
        cout << i << "\n";
    // 이거랑
    int i=0;
    for (;i<=10;){
        cout << i << "\n";
        i++;
    }
    // 이거 동일. 이거 뭐랑 닮았어?
    int i1=0;
    while (i1<=10){
        cout << i << "\n";
        i1++;
    }

    // i++ 과 ++i 차이 : ++ 은 취우선 순위.
    int a9 = 1;
    cout << ++a9 + ++a9 << "\n";
    // ++a9 -> 2
    // ++a9 -> 3
    //  cout << 3 + 3 << "\n";
    // 6 나온다.
    int b9 = 1;
    cout << b9++ + b9++ << "\n";
    // 1 + 2 = 3나온다.

    // 배열
    // 초기화시, {1,2,3,4,5,6};을 넣으면 크기를 설정안해도 돼.
    int arr[] = {1,2,3,4,5,6}; //자동으로 크기 6을 캐치.

    // 변수 초기화 시
    // 전역 변수 -> initialize : 0 value;
    // 지역 변수 -> initialize : garbage value;
    // 함수 내부의 지역변수 크기는 IDE마다 크기가 제한 되어있어서
    // 큰 크기의 지역변수를 사용하면 에러가 뜰 때가 있는데,
    // 전역 변수를 사용하면 함수 안에서 변수가 정의되는것이 아니기 때문에
    // 해당 에러가 뜨지 않는다 -> 그래서 코테에서만큼은 전역변수로 때려넣어.
    
    // 중첩 for문
    int arr1[2][3]={
        {1, 2, 3},
        {1, 2, 3}
    };
    for (int r=0; r<2; r++){
        for (int c=0; c<3; c++){
            cout << arr1[r][c] << "\n";
        }
        cout << "\n";
    }

    return 0;
}