const toggleButton = document.querySelector(".toggle-button");
const body = document.querySelector("body");
const headerNav = document.querySelector(".header-nav");
const bookmarkWrapper = document.querySelector(".bookmark-wrapper");
const texts = document.querySelectorAll(".text")

toggleButton.addEventListener('click', function(){
    console.log("다크모드 버튼이 눌렸어요!!")
    toggleButton.classList.toggle("toggle-button-darkmode")
    toggleButton.textContent = "다크모드";
    
    body.classList.toggle("body-background-darkmode")

    for (let i=0; i<texts.length; i++){
        texts[i].classList.toggle('text-darkmode');
    }

    if (toggleButton.classList.contains("toggle-button-darkmode")){
        toggleButton.textContent = "일반모드"
    }

})

// 구글 검색 시 이동 
const searchInput = document.querySelector(".search-input");

searchInput.addEventListener('keyup', function(e){
    if (e.code == "Enter"){
        console.log("가즈아아아아")

        // 유효성 검사 
        // 반 값인 경우 검색어를 입력하지 않았다고 얘기해주기.
        if (!e.target.value){
            alert("검색어를 입력하지 않았습니다.");
            return;
        }
        // https://www.google.com/search?q=내용
        // 이동하는 두가지 방법
        // 1st: 그냥 이동
        // const target = "https://www.google.com/search?q=" + e.target.value
        // location.href = target
        
        // 2nd: 새탭 이동
        const target = "https://www.google.com/search?q=" + e.target.value
        window.open(target)

    }
})
