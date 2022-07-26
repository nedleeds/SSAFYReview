titles = document.querySelectorAll(".title")
percents = document.querySelectorAll("strong.percent")
dates = document.querySelectorAll(".txt-info") 
images = document.querySelectorAll(".thumb-image")

console.log(titles[0].outerText)
console.log(percents[0].outerText)
console.log(dates[0].outerText)

new_title = "삼겹살과 그대라면"
new_percent = Number(percents[1].outerText.split('율')[1].split('%')[0])*.95
new_percent = "예매율 " + String(new_percent.toFixed(1)) + "%"
new_date = "1985.07.07 개봉";

titles[1].innerText = new_title
percents[1].textContent = new_percent
dates[1].innerText = new_date

console.log(titles[1].outerText)
console.log(percents[1].outerText)

// !!!! querySelector 를 사용하는게 핵심 !!!!
src1 = images[0].querySelector("img").src
src3 = images[2].querySelector("img").src

images[0].querySelector("img").setAttribute("src", src3)
images[2].querySelector("img").setAttribute("src", src1)
