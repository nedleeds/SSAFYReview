<template>
  <div>
    <div @click="moveDetail(menu.id)" v-for = "menu in menus" :key="menu.id">
      <div class="menu-container">
        <img :src="setImage(menu.image_src)" width="200px" alt="메뉴 이미지"/>
        <div class="menu-image" :style="`background-iamge:url(${setImage(menu.image_src)})`"></div>
        <div class="menu-info-wrapper">
          <h2 class="menu-name">{{menu.name}}</h2>
          <p class="menu-description">{{menu.description}}</p>
        </div>
      </div>
    </div>

  </div>
</template>

<script>
  import {api} from "../../utils/axios"

  export default {
    methods:{
      setImage(image_src){
        // return http://본인AWS주소:배포한포트
        return `http://3.35.208.145:8080/${image_src}`
      },
      moveDetail(id){
        console.log(id);
        this.$router.push(`/orders/${id}`)
      }
    },

    data(){
      return {
        menus: []
      }
    },
    async created(){
      this.$store.commit("SET_TITLE", "주문 하기");
      const result = await api.menus.findAll();
      console.log(result);
      this.menus = result.data;
    }
  }
</script>

<style>

  .menu-container{
    display: flex;
    align-items: center;
    border-bottom: 3px solid black;
  }
  .menu-info-wrapper{
    margin:0 auto;
    text-align: center;
  }

  .menu-name{
    font-size:25px;
    font-weight:bold;
  }

  .menu-description{
    padding-top: 10px;
  }

  .menu-image{
    background-size: cover;
    background-position: center;
    width:25px;
    height:10px;
  }

</style>