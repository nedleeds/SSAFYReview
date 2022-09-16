<template>
  <div class="main-contianer">
    <Form></Form>
    <reactive-bar-chart
      style="width:40vw;"
      v-if=$store.state.chartData
      :chart-data = $store.state.chartData
    ></reactive-bar-chart>
    <!-- <el-button type="primary">Primary</el-button> -->
  </div>
</template>

<script>
import Form from "./components/Form.vue"
import ReactiveBarChart from "./components/ReactiveBarChart"
export default {
  components:{
    ReactiveBarChart,
    Form
  },

  data(){
    return {
      chartData: null
    }
  },

  mounted(){
    this.generateData();
    setInterval(this.generateData, 5000)
    this.$store.dispatch('generateChartData')
  },

  methods:{
    generateData() {
      let newArray = [];
      let newArray2 = [];
      for (let i = 0; i < 10; i++) {
        let randomValue = Math.floor(Math.random() * 10);
        newArray.push(randomValue);
      }

      for (let i = 0; i < 10; i++) {
        let randomValue = Math.floor(Math.random() * 10);
        newArray2.push(randomValue);
      }

      this.chartData = {
        labels: ["Red", "Blue", "Yellow", "Green", "Purple", "Orange"],
        datasets: [
          {
            label: "Data One",
            backgroundColor: "#f87979",
            data: newArray,
            fill: false,
          },
          {
            label: "Data One",
            backgroundColor: "#f87979",
            data: newArray2,
            fill: false,
          },
        ],
      };
    },
  }
}
</script>

<style>
.main-container{
  display: flex;
  padding:20px;
}
.main-container > * {
  width:700px;
}
</style>
