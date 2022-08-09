const bucketlist = [
    {id:3, text:'여행가기', done:false},
    {id:2, text:'치킨먹기', done:false},
    {id:1, text:'코딩하기', done:false}
];

function render(bucket){
    return bucket.reduce((acc, curr)=>{
        acc = acc + 
        `
        <li id="${curr.id}">
            <label>
                <input type="checkbox>${curr.text}
            </label>
        </li>
        `
        return acc;
    }, {})
    // let html 선언해서 forEach 돌려서 html = html + 해도 됨
    // let html = 
    // `
    // <li id="${list[0].id}"><lablel>
    // <input type="checkbox>${list[0].text}
    // </label></li>

    // <li id="${list[1].id}"><lablel>
    // <input type="checkbox>${list[1].text}
    // </label></li>

    // <li id="${list[2].id}"><lablel>
    // <input type="checkbox>${list[2].text}
    // </label></li>
    // `;
    return html
}

console.log(render(bucketlist))