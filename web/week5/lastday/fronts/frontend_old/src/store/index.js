import Vue from 'vue'
import Vuex from 'vuex'
import { dataLap } from "../utils/axios"

Vue.use(Vuex)

function makeColor(){
  return "#" + Math.round(Math.random() * 0xffffff).toString(16);
}


export default new Vuex.Store({
  state: {
    chartData: null
  },
  getters: {
  },
  mutations: {
    CHANGE_CHART_DATA(state, data){
      state.chartData = data;
    }
  },
  // 비동기요청을 행해야할 경우 action에서 비동기처리를 하고
  // mutations를 호출한다 
  // this.$store.dispatch('함수명',전달인자)
  actions: {
    async generateChartData({commit}){
      // labels에는 period 매핑
      // datsets에는 title을 매핑 
      const result = await dataLap.get();
      console.log(result.data);
      
      const chartData = {
        labels: result.data[0].data.map(li => li.period),
        datasets: result.data.reduce((acc, cur) => {
          //cur.label-> cur.title로 변경
          const label = cur.title;
          const data = cur.data.map(li => li.ratio);
          acc.push({label:label, data: data, fill:false, backgroundColor:makeColor(),
          borderColor:makeColor()})
          return acc
        }, [])
      }

      commit("CHANGE_CHART_DATA", chartData)

    }
  },
  modules: {
  }
})
