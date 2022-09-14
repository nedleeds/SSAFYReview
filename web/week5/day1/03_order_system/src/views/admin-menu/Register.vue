<template>
  <div>


    <div class="form-wrapper">
      <div>메뉴 이름: <input v-model="name" type="text"/></div>
      <div>메뉴 설명: <input v-model="description" type="text"/></div>
      <input @change="fileChange" type="file">

      <!-- $route.params.id가 존재하면 수정 모드 -->
      <div v-if ="$route.params.id"> 
        <button @click="update">메뉴 수정하기</button>
        <button @click="updateImage">이미지 수정하기</button>
      </div>

      <button @click="create">메뉴 추가하기</button>
    </div>

    <div class="image-wrapper" v-if="file">
      <img :src="setURL(file)" width="100%"/>
    </div>

  </div>
</template>

<script>
  import {api} from '@/utils/axios'

  export default {
    async created(){
      // 일반 작성 /api/menus/register
      // 수정 요청 /api/menus/register/:id
      // 즉 this.$route.params.id 가 존재하면 -> 수정모드
      if (this.$route.params.id){
        this.$store.commit("SET_TITLE", "메뉴 수정하기")
        // 원래 기입한 정보를 볼 수 있어야한다.
        // detail 처럼 id로 요청을 보낸다.
        const result = await api.menus.findOne(this.$route.params.id); // result - menu:
        console.log(result.data);
        this.name = result.data.name;
        this.description = result.data.description;

      }else{
        this.$store.commit("SET_TITLE", "메뉴 추가하기")
      }

    },

    methods:{
      async update(){
        const result = await api.menus.update(this.$route.params.id, this.name, this.description);
        console.log(result);
        alert(result.data.message);
        // 업데이트가 완료되었으니 router 이동
        this.$router.push(`/admin/menus/${this.$route.params.idx}`);
      },

      async updateImage(){
        if (!this.file){
          alert('파일을 업로드 해주세요.');
          return;
        }
        const result = await api.menus.updateImage(this.$route.params.id, this.file);
        alert(result.data.message);
      },

      fileChange(e){
        // console.log(e.target.files[0]);
        this.file = e.target.files[0];
      },
      async create(){
        if (!this.name || !this.description || !this.file){
          alert("빈 값이 있습니다. 내용을 전부 작성해주세요!");
          return;
        }
        const result = await api.menus.create(this.name, this.description, this.file);
        console.log(result);
        // 요청 성공

        if(result.data.success){
          alert(result.data.message);
          this.$router.push("/admin/menus");
        }

        if (result.data.success){
          alert(result.data.message);
        }

      },

      setURL(file){
        console.log(file);
        const imageURL = URL.createObjectURL(file);
        // console.logs(imageURL);
        return imageURL;
      }
    },

    data(){
      return {
        name:"",
        description:""
        
      }
    }
  }
</script>

<style>

  .form-wrapper{
    display: flex;
    flex-direction: column;
    margin-top:50px;
    border:1px solid black;
    padding:20px;
  }

  .form-wrapper > *{
    margin:10px;
  }

  .image-wrapper{
    margin-top:30px;
  }

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