import axios from "axios";

// request 는 요청을 보낼 때마다 기본 url로 baseURL이 들어간다.
// ex) request.get("/hello")
// request.get("https://jsonplaceholder.typicode.com/hello")

const request = axios.create({
    baseURL: "https://jsonplaceholder.typicode.com"
});

export const api = {
    jsonplaceholder:{
        findAll: () => request.get("/todos"),
        findOne: (id) => request.get(`/todos/${id}`)
    }
}