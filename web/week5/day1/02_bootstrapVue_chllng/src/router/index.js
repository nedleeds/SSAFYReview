import Vue from 'vue'
import VueRouter from 'vue-router'
// view로 부터 import로 가져온다
// routes 배열안에 정의한다
import Main from "../views/Main.vue"
import List from "../views/shoppingList/List.vue"
import Detail from "../views/shoppingList/Detail.vue"

Vue.use(VueRouter)

const routes = [
  {
    path:"/",
    name:"Main",
    component: Main
  },
  {
    path: "/shop",
    name: "List",
    component: List
  },
  {
    path: "/shop/:id",
    name: "Detail",
    component: Detail
  }
]

const router = new VueRouter({
  mode: 'history',
  base: process.env.BASE_URL,
  routes
})

export default router
