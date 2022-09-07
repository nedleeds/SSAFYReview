<template>
    <div>
    {{message}}
    <EachResult></EachResult>
  </div>
</template>

<script>
    import EachResultVue from './EachResult.vue';
import EachResult from './EachResult.vue';
  
    export default {
        data(){
        return{
            message: "Main"
        }
        },

        components:{
    EachResultVue,
    EachResult
}
    };
</script>

<style>

</style>