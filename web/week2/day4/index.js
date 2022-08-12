const imageURL = "https://picsum.photos/1280/720?grayscale";

// 이미지 설정 파트
function setRenderBackground(){
  // 이미지, 사운드, 비디오 등을 통신하는 경우에는 blob이라는 속성을 사용
  const result = axios.get(imageURL,{
    responseType: 'blob'
  });
  result.then(data =>{
    // console.log(data);
    // console.log(data.data);
    // 해당 이미지 덩어리를 임시 URL 을 만들어서 접근이 가능하게 한다
    const image = URL.createObjectURL(data.data);
    // console.log(image);
    document.querySelector('body').style.backgroundImage = `url(${image})`;
  }) 
}

// 시계 설정 파트
function setTime(){
  const timer = document.querySelector('.timer');

  setInterval( () => {
    const date = new Date();
    const hours = date.getHours();
    const minutes = date.getMinutes();
    const seconds = date.getSeconds();
    const timeFormate = `${hours}:${minutes}:${seconds}`;
    timer.textContent = timeFormate;
  }, 1000)
}

// 메모 파트
function setMemo(){
  const memoInput = document.querySelector('.memo-input');
  memoInput.addEventListener('keyup', function(e){
    // console.log(e.code);
    // console.log(e.target.value);
    if (e.code === 'Enter' && e.target.value){
      localStorage.setItem('todo', e.target.value);
      getMemo();  
    }
  })
}

function getMemo(){
  const memo = document.querySelector('.memo');
  const memoValue = localStorage.getItem('todo');
  memo.textContent = memoValue;
}

function deleteMemo(){
  // document.querySelector(body).addEventListener
  // 이벤트 위임 (최상단에 이벤트를 부여해서 조건에 따라 설정)
  document.addEventListener('click', (e)=>{
    console.log(e.target);
    // 메모는 .memo에 있다
    if (e.target.classList.contains('memo')){
      e.target.textContent = "";
      localStorage.removeItem('todo');
    }
  })
}
const key = "b15743f22c13d2369c8f1d3fd9173390";
// 도시명으로 API 호출
// api.openweathermap.org/data/2.5/forecast?q={city name}&appid={API key}

// 위도 경도로 API 호출
// api.openweathermap.org/data/2.5/forecast?lat={lat}&lon={lon}&appid={API key}

function getPosition(options){
  return new Promise((resolve, reject) => {
    navigator.geolocation.getCurrentPosition(resolve, reject, options);
  })
}

function matchIcon(weatherData) {
  if (weatherData === "Clear") return "./images/039-sun.png";
  if (weatherData === "Clouds") return "./images/001-cloud.png";
  if (weatherData === "Rain") return "./images/003-rainy.png";
  if (weatherData === "Snow") return "./images/006-snowy.png";
  if (weatherData === "Thunderstorm") return "./images/008-storm.png";
  if (weatherData === "Drizzle") return "./images/031-snowflake.png";
  if (weatherData === "Atmosphere") return "./images/033-hurricane.png";
}

// 273.15를 빼고 소숫점 한자리까지만 보여주게 만든다. 
const changeToCelsius = temp => (temp -273.15).toFixed(1);

function weatherWrapperComponents(cur){
  console.log(cur);
// 
  return `
  <div class="card bg-transparent flex-grow-1 m-2">
    <div class="card-header text-center">
      ${cur.dt_txt.split(" ")[0]}
    </div>
    <div class="card-body text-center">
      <h5 class="card-title">${cur.weather[0].main}</h5>
      <img width="60px" height="60px" src="${matchIcon(cur.weather[0].main)}" >
      <p class="card-text">${changeToCelsius(cur.main.temp)}˚</p>
    </div>
  </div>
  `
}

let weatherData = null;
async function renderWeather(){
  // 상황 : 2가지 (위치정보 승인 or 낫승인)
  let latitude = '';
  let longitude = '';
  
  try
  {
    const position = await getPosition();
    latitude = position.coords.latitude;
    longitude = position.coords.longitude;
    const result = await
    axios.get(`http://api.openweathermap.org/data/2.5/forecast?lat=${latitude}&lon=${longitude}&appid=${key}`)
    console.log(result)
    weatherData = result.data;
  }
  catch(error)
  {
    console.log(error);
    if (!latitude || !longitude){
      console.log("test");
      const result = await
      axios.get(`http://api.openweathermap.org/data/2.5/forecast?q=Seoul&appid=${key}`)
      console.log(result)
      weatherData = result.data;
    }
  }

  console.log(weatherData);
  const weatherList = weatherData.list.reduce((acc, cur) => {
      if (cur.dt_txt.indexOf("18:00:00") > 0){
        //못찾으면 -1을 리턴함
        acc.push(cur);
      }

      return acc;
  }, [])

  console.log(weatherList);

  const weatherComponents = weatherList.reduce((acc, cur) => {
      acc = acc + weatherWrapperComponents(cur);
      return acc;
    }, "")
    // console.log(weatherComponents)
    document.querySelector('.modal-body').insertAdjacentHTML('beforeend', weatherComponents)
  }

setRenderBackground();
setTime();
setMemo();
getMemo();
deleteMemo();
getPosition();
renderWeather();


// setInterval -> 비동기 + 반복에 사용
setInterval(()=>{
  setRenderBackground()
}, 10000);
// 이미지 설정 파트 끝

