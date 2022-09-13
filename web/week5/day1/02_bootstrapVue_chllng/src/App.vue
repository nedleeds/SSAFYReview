<template>
  <div>
    <router-view/>
    <!-- 로딩창을 넣고 Vuex로 제어 -->
    <div v-if="$store.state.loading"  class="spinning">
    <b-spinner label="Loading..."></b-spinner>
    </div>
  </div>
</template>

<script>
export default {
  data(){
    return{
      myName: "",
    };
  }
}
</script>

<style>
  .spinning{
    position: absolute;
    top: 50%;
    left: 50%;
    transform: translate(-50%, -50%);
  }
</style>
