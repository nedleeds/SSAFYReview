// node_modules에 있는 내용도 require도 가져와진다
const puppeteer = require("puppeteer");

const main = async() => {
    // launch : 브라우저를 생성
    const browser = await puppeteer.launch({
        // headless: true 일시 화면이 보이지 않는다
        //pdf 는 headless true에서만 동작한다
        headless: true 
        
    });

    // 페이지를 띄운다
    const page = await browser.newPage();

    // 페이지로 이동한다
    await page.goto('https://www.google.com');
    
    // pdf를 만든다 test.pdf라는 경로로
    await page.pdf({path: 'test.pdf', format: 'A4'})
    
    // 만들었으니 브러우저 종료
    await browser.close();
}

main();