// puppeteer 를 사용하기 전에
// npm init 으로 json 파일만들고 패키지 생성
// puppeteer - 크롬 환경을 제어하기 위한 라이브러리
// 가장 빠른 크롤링 라이브러리중 하나
// 다운 : npm i puppeteer
const puppeteer = require("puppeteer");
const { resourceLimits } = require("worker_threads");

const main = async() => {

    // browser를 생성
    const browser = await puppeteer.launch(({
        headless: false
    }))

    // 페이지를 생성
    const page = await browser.newPage();

    // 페이지를 이동
    await page.goto("https://www.megabox.co.kr/movie");

    // 영화 포스터(".movie-list img.poster")가 생성이 되면 -> 로딩이 끝났다고 생각
    await page.waitForSelector(".movie-list img.poster");

    // 영화 포스터 주소를 가져오기
    const data = await page.evaluate(() => {
        const images = document.querySelectorAll(".movie-list img.poster");
        // 주의!!! 어제도 말했지만 querySelectorAll 은 !!! 유사배열 !!!
        // 그래서 Array.from으로 Typecasting을 해줘야 배열 메서드 사용가능하다
        const images_array = Array.from(images).map(li => li.getAttribute('src'));
        // attribute -> 인자값 !! (parameter에 값이 할당된 값!!)
        return images_array;
    });

    console.log(data);
}

main();