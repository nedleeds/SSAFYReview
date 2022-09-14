<template>
  <div>
    <b-card v-if="data" :title="data.name" img-top image-alt="디테일" tag="article" :img-src="setImage()" class="mb-2 detail-card">
    <b-card-text>
      {{data.description}}
    </b-card-text>
      <b-button @click="moveUpdate" variant="primary"> 수정</b-button>
      <b-button @click="deleteMenu" variant="danger">삭제</b-button>
      <b-button @click="moveList" variant="outlie-primary">목록</b-button>
    </b-card>
  </div>
</template>

<script>
import {api} from '@/utils/axios';
export default {

  methods:{
      moveUpdate(){
        this.$router.push(`/admin/menus/register/${this.$route.params.id}`);
      },
      async deleteMenu(){
        const confirmResult = confirm("삭제하시겠습니까?")
        console.log(confirmResult);
        if (confirmResult){
          const result = await api.menus.delete(this.$route.params.id);
          alert(result.data.message);
          this.$router.push("/admin/menus");
        }
      },

      moveList(){
        this.$router.push("/admin/menus");
      },

      setImage(image_src){
        // return http://본인AWS주소:배포한포트
        return `http://3.35.208.145:8080/${this.data.image_src}`
      }
  },

  data(){
    return {
      data:{}
    }
  },
  async created(){
    console.log(this.$route.params);
    const result = await api.menus.findOne(this.$route.params.id);
    console.log(result);
    this.data = result.data;
  }
}
</script>

<style>

</style>