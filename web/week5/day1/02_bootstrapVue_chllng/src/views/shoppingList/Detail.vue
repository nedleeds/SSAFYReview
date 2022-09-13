<template>
    <div>
        <div align="center">
        <img :src=data.image class = "itemImage">
        </div>
        <div class="txt">
            <br>{{data.title}}
        </div>
        <div class="txt price">
            ${{data.price}}
        </div>
    </div>
  </template>
  
  <script>
  import {api} from "../../utils/axios.js"
  export default {
      data(){
          return {
              data: {},
          };
      },
  
      async created(){
          this.$store.commit("SET_LOADING", true);
          // router에 정의한 /:id 값 가져오기
          console.log(this.$route.params);
          const result = await api.jsonplaceholder.findOne(this.$route.params.id);
          console.log(result);
          this.data = result.data
  
          this.$store.commit("SET_LOADING", false);
      }
  }
  </script>
  
  <style>
    body{
        display:flex;
        align-items: center;
        justify-content: center;
    }
    .itemImage{
        margin-top: 10%;
        width: 200px;
        border-radius: 15px;
    }
    .txt{
        text-align: center;
    }
    .price{
        color: darkorange;
        font-weight: bolder;
    }
  </style>