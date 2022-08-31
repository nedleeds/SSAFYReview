// node_modules에 있는 내용도 require도 가져와진다
const puppeteer = require("puppeteer");

const main = async() => {
    // launch : 브라우저를 생성
    const browser = await puppeteer.launch({
        headless: false // headless가 true면 화면이 보이지 X
    });

    // 페이지를 띄운다
    const page = await browser.newPage();

    await page.goto('https://www.naver.com');

    // 스크린샷
    await page.screenshot({path:'screenshot.jpg', fullPage: true})
    await browser.close();

    // document.querySelectorAll(".img_list > li > dl > dt> a")
}

main();