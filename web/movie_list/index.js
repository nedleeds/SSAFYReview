const APIKEY = "35d3f9c1f03d43cf8a96c9631718ac61";
const SEARCHAPI = "https://api.themoviedb.org/3/search/movie?api_key=35d3f9c1f03d43cf8a96c9631718ac61&language=ko-KO&query=";
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

async function renderMovie(){
    const nowPlayingData = await request("movie/now_playing");
    const popularData = await request("movie/popular");
    // console.log(nowPlayingData.data);
    // console.log(popularData.data);
    const nowPlayingList = nowPlayingData.data.results.reduce((acc, cur) => {
        acc.push(cur);
        return acc
    }, [])

    const popularList = popularData.data.results.reduce((acc, cur) => {
        acc.push(cur);
        return acc
    }, [])

    const nowPlayingContainer = nowPlayingList.reduce((acc, cur) => {
        acc = acc + getCardContainer(cur)
        return acc;
    }, "")
    const popularContainer = popularList.reduce((acc, cur) => {
        acc = acc + getCardContainer(cur)
        return acc;
    }, "")

    form.addEventListener("submit", (e) => {
        e.preventDefault();
        main.innerHTML = '';
        const searchTerm = search.value;
        /*  Adding the value wriiten in the search bar to the search Api,
        in order to get the movies we search for. */
        if (searchTerm) {
            searchMovie(SEARCHAPI + searchTerm);
            search.value = "";
        }
    });

    const theme = document.querySelector('h1')
    theme.addEventListener('click', function(e){
        window.location.reload();
        getMovie();
    })
    // console.log(nowPlayingContainer);
    // console.log(popularContainer);
    document.querySelector('.MC1').insertAdjacentHTML('beforeend', nowPlayingContainer);    
    document.querySelector('.MC2').insertAdjacentHTML('beforeend', popularContainer);    
}

async function searchMovie(url=NaN){
    fetch(url).then(res => res.json())
    .then(function(data){
        console.log(data.results);
        data.results.forEach(element => {
            const el = document.createElement('div');
            const image = document.createElement('img');
            const text = document.createElement('h3');

            text.innerHTML = `
                🎬&nbsp;&nbsp;${element.title}<br>
                ⭐️&nbsp;&nbsp;${element.vote_average} - ${element.vote_count}명
                `;
            image.src = IMGPATH + element.poster_path;
            el.appendChild(image);
            el.appendChild(text);
            main.appendChild(el);
        }); 
    });
}

renderMovie();
