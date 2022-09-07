<template>
    <div>
    {{message}}
    <Search></Search>
    <Navigation></Navigation>
  </div>
</template>

<script>
    import Search from "./Search.vue";
    import Navigation from "./Navigation.vue";
  
    export default {
        data(){
        return{
            message: "Header"
        }
        },

        components:{
            Search,
            Navigation
        }
    };
</script>

<style>

</style>