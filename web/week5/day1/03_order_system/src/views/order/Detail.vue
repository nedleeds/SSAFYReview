<template>
  <div>
    <b-card v-if="data" :title="data.name" img-top image-alt="디테일" tag="article" :img-src="setImage()" class="mb-2 detail-card">
    <b-card-text>
      {{data.description}}
    </b-card-text>
      <input type="number" min="1" value="1" style="width:20%; height:40px;font-size:30px; color: darkorange"><br>
      <b-button  class="btn btn-success" style="height:40px; margin-top: 10px">주문하기</b-button>
      <b-button @click="moveList" class="btn btn-primary" variant="outlie-primary" style="height:40px; margin-left: 5px; margin-top: 10px">메뉴 목록</b-button>
    </b-card>
  </div>
</template>

<script>
import {api} from '@/utils/axios';
export default {

  methods:{
      moveList(){
        this.$router.push("/orders/register");
      },

      checkOrder(){
        // alert(`${dfd}`)
      },

      setImage(image_src){
        // return http://본인AWS주소:배포한포트
        return `http://3.35.208.145:8080/${this.data.image_src}`
      }
  },

  data(){
    return {
      data:{},
      orderQuantity: "",
      orderDetail: "",
    }
  },
  async created(){
    // console.log(this.$route.params);
    const result = await api.menus.findOne(this.$route.params.id);
    this.data = result.data;
    // const orderResult = await api.orders.findOne(this.$route.params.id);
    // this.orderQuantity = orderResult.quantity;
    // this.orderDetail = orderResult.orderDetail;
    // console.log(orderResult)
  }
}
</script>

<style>

</style>