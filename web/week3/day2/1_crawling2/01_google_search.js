const puppeteer = require("./node_modules/puppeteer");

const main = async() => {

    // browser를 생성
    const browser = await puppeteer.launch(({
        headless: false
    }))

    // 페이지를 생성
    const page = await browser.newPage();

    // 페이지를 이동
    await page.goto("https://www.google.com");

    // 해당 evaluate 안에서는 DOM에 접근이 가능해진다
    await page.evaluate(()=>{
        document.querySelector(".gLFyf").value="치킨";
        document.querySelector(".gNO89b").click();
    })

    // 여기서 스크린 샷을 찍게 되면, 페이지 로딩 시간을 고려않고 스크린샷을 찍기
    // 때문에 원하는 치킨 검색결과가 찍히지 않는다
    // // 스크린샷 찍기
    // await page.screenshot({path: "chicken.jpg", fullPage:true});

    // 그래서 그걸 방지하기 위해서 특정 페이지에만 존재하는 특정 선택자가
    // 나타날 때까지 기다리고 스크린샷을 찍게 만들어준다

    // await page.waitForSelector("선택자")
    // 특정 선택자가 생성이 될 때까지 기다린다
    await page.waitForSelector(".kpQuGf");
    // 스크린샷 찍기
    await page.screenshot({path: "chicken.jpg", fullPage:true});

}

main();