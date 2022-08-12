const APIKEY = "35d3f9c1f03d43cf8a96c9631718ac61";
const SEARCHAPI = `"https://api.themoviedb.org/3/search/movie?api_key=${APIKEY}&language=ko-KO&query="`;
const IMGPATH = 'https://www.themoviedb.org/t/p/w440_and_h660_face';
const request = axios.create({
    baseURL: "https://api.themoviedb.org/3/",
    params: {
        api_key: APIKEY,
        language: "ko-KR",
    },
});


function getCardContainer(cur){
    return `
    <div class="cardContainer">
        <img class="cardImage" src="${IMGPATH + cur.poster_path}">
        <div class="cardInfo">
            🎬&nbsp;&nbsp;${cur.title}<br>
            ⭐️&nbsp;&nbsp;${cur.vote_average} - ${cur.vote_count}명
        </div>
    </div>
    `
  }

async function rederMovie(){
    const nowPlayingData = await request("movie/now_playing");
    console.log(nowPlayingData.data);
    const nowPlayingList = nowPlayingData.data.results.reduce((acc, cur) => {
        acc.push(cur);
        return acc
    }, [])

    const cardContainer = nowPlayingList.reduce((acc, cur) => {
        acc = acc + getCardContainer(cur)
        return acc;
    }, "")
    console.log(cardContainer);
    document.querySelector('.movieListContainer').insertAdjacentHTML('beforeend', cardContainer);
    


    const slider = document.querySelector('.items');
    let isMouseDown = false;
    let startX, scrollLeft;

    slider.addEventListener('mousedown', (e) => {
    isMouseDown = true;
    slider.classList.add('active');

    startX = e.pageX - slider.offsetLeft;
    scrollLeft = slider.scrollLeft;
    });

    slider.addEventListener('mouseleave', () => {
    isMouseDown = false;
    slider.classList.remove('active');
    });

    slider.addEventListener('mouseup', () => {
    isMouseDown = false;
    slider.classList.remove('active');
    });

    slider.addEventListener('mousemove', (e) => {
    if (!isMouseDown) return;

    e.preventDefault();
    const x = e.pageX - slider.offsetLeft;
    const walk = (x - startX) * 1;
    slider.scrollLeft = scrollLeft - walk;
    });
}

rederMovie();

