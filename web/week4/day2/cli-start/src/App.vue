<template>
  <div>
    {{message}}
    <Header></Header>
    <Main></Main>
  </div>
</template>

<script>
  // import 
  // webpack require 과 유사한 개념
  import Header from "./components/Header.vue";
  import Main from "./components/Main.vue";
  
  export default {
    data(){
      return{
        message: "test"
      }
    },

    components:{
      Header,
      Main
    }
  };
</script>

<style>

</style>