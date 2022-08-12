// 이미지 설정 파트
const imageURL = "https://picsum.photos/1280/720";
function setRenderBackground(){
  // 이미지, 사운드, 비디오등을 통신하는 경우에는 blob이라는 속성을 사용
  const result = axios.get(imageURL, {
    responseType: 'blob'
  });
  
  result.then(data => {
    // console.log(data);
    // console.log(data.data);
    // 해당 이미지 덩어리를 임시 URL을 만들어서 접근이 가능하게 한다
    const image = URL.createObjectURL(data.data);
    // console.log(image);
    document.querySelector('body').style.backgroundImage = `url(${image})`;
  })
}
// 이미지 설정 파트 끝

// 시계 설정 파트
function setTime(){
  const timer = document.querySelector('.timer');

  setInterval(() => {
    const date = new Date();
    // console.log(date);
    const hour = date.getHours();
    const minutes = date.getMinutes();
    const second = date.getSeconds();
    const timeFormat = `${hour}:${minutes}:${second}`;
    timer.textContent = timeFormat;
  
  }, 1000)

}


// 메모 파트 
function setMemo(){
  const memoInput = document.querySelector('.memo-input');
  memoInput.addEventListener('keyup', function(e){

    // console.log(e.code);
    
    // console.log(e.target.value);
    // 부정의의미
    // 긍정의의미
    // if(value) -> 긍정
    // if(!value) -> 부정  
    // e.target.value !== undefined && !== null !== false 
    if(e.code === 'Enter' && e.target.value){
      // memo.textContent = e.target.value;
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
  // document.querySelector(body).addEventLitener
  // 이벤트 위임 (최상단에 이벤트를 부여해서 조건에 따라 설정 )
  document.addEventListener('click', (e) =>{
    // console.log(e.target);
    // 메모는 .memo에 있다
    if(e.target.classList.contains('memo')){
      e.target.textContent = "";
      localStorage.removeItem('todo');
    }
  })
}

const key = "dc1b69744442caa38d9ccdc354897bfd";
// 도시명으로 API 호출하는법
// api.openweathermap.org/data/2.5/forecast?q={city name}&appid={API key}

// 위도 경도로 API 호출하는법
// api.openweathermap.org/data/2.5/forecast?lat={lat}&lon={lon}&appid={API key}


// 위도 경도 받아오기
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

function weatherWrapperComponent(cur){
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



async function renderWeather(){
  // 위치 정보를 승인 O 
  let latitude = '';
  let longitude = '';
  let weatherData = null;
  try {
    const position = await getPosition();
    console.log(position.coords);
    latitude = position.coords.latitude;
    longitude = position.coords.longitude;
    console.log(latitude, longitude);
    const result = await axios.get(`http://api.openweathermap.org/data/2.5/forecast?lat=${latitude}&lon=${longitude}&appid=${key}`);
    console.log(result.data);
    weatherData = result.data;

  // 위치정보를 승인X
  } catch (error) {
    console.log(error);
    if(!latitude || !longitude){
      console.log("test");
      const result = await axios.get(`http://api.openweathermap.org/data/2.5/forecast?q=Seoul&appid=${key}`)
      console.log(result.data);
      weatherData = result.data;
    }
  }

  console.log(weatherData);
  const weatherList = weatherData.list.reduce((acc, cur) => {
      if(cur.dt_txt.indexOf("18:00:00") > 0){
        acc.push(cur);
      }

    return acc; 
  }, [])

  console.log(weatherList);

  const weatherComponents = weatherList.reduce((acc, cur) => {
    acc = acc + weatherWrapperComponent(cur);

    return acc;
  },"")

  console.log(weatherComponents);
  document.querySelector('.modal-body').insertAdjacentHTML('beforeend', weatherComponents);

}

setRenderBackground();
setTime();
setMemo();
getMemo();
deleteMemo();
renderWeather();

// setInterval

setInterval(() => {
  setRenderBackground()
}, 5000);