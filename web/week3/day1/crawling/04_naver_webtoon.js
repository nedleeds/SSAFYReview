// node_modules에 있는 내용도 require도 가져와진다
const puppeteer = require("puppeteer");

const main = async() => {
    // launch : 브라우저를 생성
    const browser = await puppeteer.launch({
        headless: false // headless가 true면 화면이 보이지 X
    });

    // 페이지를 띄운다
    const page = await browser.newPage();

    await page.goto('https://comic.naver.com/webtoon/weekdayList?week=mon');

    // page.eveluate
    // 해당 함수 안에서는 document.querySelector가 활용이 가능하다
    // 기본적으로 node는 document 접근이 불가(서버단)
    const data = await page.evaluate(() => {
        const webToonLists = document.querySelectorAll(".img_list > li > dl > dt> a");
        console.log(webToonLists)
        // querySelectorAll로 담긴 배열은 유사 배열이다.
        // map.filter, reduce 등의 배열함수를 활용하기 위해서는
        // 유사배열이 아닌 배열로 전환해주어야한다.
        // const titles = Array.from(webToonLists).map(li => li.textContent.trim())
        const titles = Array.from(webToonLists).map(li => li.getAttribute('title'))
        
        return titles;
    })
    console.log(data);
    browser.close();

    // 네이버 웹툰 a 태그만 가져오는 코드
    // document.querySelectorAll(".img_list > li > dl > dt> a")
}

main();