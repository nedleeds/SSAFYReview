<template>
  <div>
    <div @click="moveDetail(list.id)" v-for="list in lists" :key="list.id" class="list-wrapper">
        {{list.title}}
    </div>
  </div>
</template>

<script>
import {api} from "../../utils/axios"
export default {
    methods:{
        moveDetail(id){
            console.log(id);
            this.$router.push(`/todos/${id}`)
        }
    },

    data(){
        return {
            lists: []
        }
    },

    async created(){
        // 로딩을 켜고
        this.$store.commit("SET_LOADING", true);
        // data load
        const results = await api.jsonplaceholder.findAll();
        console.log(results);
        this.lists = results.data;
        // data를 넣었으니 로딩을 끄자
        this.$store.commit("SET_LOADING", false);
    }
}
</script>

<style>
    .list-wrapper{
        border: 1px solid black;
        padding: 20px;
    }
</style>