<template>
    <div>
      <el-form ref="form" :model="form" label-width="120px">
        <div class="groups-wrapper">
          <!-- 키워드를 저장할때마다 keywords 배열에 담긴다 -->
          <!-- 주제 생성하기를 누르면 해당 keywords들을 가지고있는 배열을 생성 -->
          <el-form-item style="width: 500px" label="키워드">
            <el-input v-model="form.keyword">
              <el-button @click="saveKeyword" slot="append"
                >키워드 추가</el-button
              >
            </el-input>
          </el-form-item>
  
          <div v-if="keywords.length" class="tag-wrapper">
            <el-tag
              @click="removeKeyword(keyword)"
              v-for="keyword in keywords"
              :key="keyword"
              class="group-tag"
            >
              {{ keyword }}
            </el-tag>
          </div>
  
          <el-form-item style="width: 500px" label="주제">
            <el-input v-model="form.groupName"></el-input>
          </el-form-item>
  
          <div v-if="keywordGroups.length" class="tag-wrapper">
            <el-tag
              @click="removeGroup(group.groupName)"
              v-for="(group, index) in keywordGroups"
              :key="index"
              type="success"
              class="group-tag"
            >
              {{ group.groupName }}
            </el-tag>
          </div>
  
          <el-button @click="saveGroup" class="create-button" type="primary"
            >주제 생성하기</el-button
          >
        </div>
  
        <div class="groups-wrapper">
          <!-- 시간단위 -->
          <el-form-item label="시간대별 설정">
            <el-col :span="11">
              <el-date-picker
                type="date"
                placeholder="시작날짜를 고르세요"
                v-model="form.startDate"
                style="width: 100%"
              >
              </el-date-picker>
            </el-col>
  
            <el-col class="line" :span="2">-</el-col>
  
            <el-col :span="11">
              <el-date-picker
                type="date"
                placeholder="종료날짜를 고르세요"
                v-model="form.endDate"
                style="width: 100%"
              >
              </el-date-picker>
            </el-col>
  
  
          </el-form-item>
          <!-- 구간단위 -->
        <el-form-item label="구간 단위">
          <el-radio-group v-model="form.timeUnit">
            <el-radio label="date"></el-radio>
            <el-radio label="week"></el-radio>
            <el-radio label="month"></el-radio>
          </el-radio-group>
        </el-form-item>
  
        <!-- 디바이스 전체, pc, mobile -->
        <el-form-item label="디바이스">
          <el-radio-group v-model="form.device">
            <el-radio label="all"></el-radio>
            <el-radio label="pc">pc</el-radio>
            <el-radio label="mo">모바일</el-radio>
          </el-radio-group>
        </el-form-item>
  
        <el-form-item label="성별">
          <el-radio-group v-model="form.gender">
            <el-radio label="all">모두</el-radio>
            <el-radio label="m">남</el-radio>
            <el-radio label="f">녀</el-radio>
          </el-radio-group>
        </el-form-item>
        </div>

        <el-form-item>
            <el-button type="primary" @click="onSubmit">작성</el-button>
        </el-form-item>

      </el-form>
    </div>
  </template>
  
  <script>
  import moment from "moment";
  import { dataLap } from "../utils/axios";

  export default {
    methods: {
        async onSubmit(){
            const {startDate, endDate, timeUnit, device, gender} = this.form;    
            if (startDate && endDate && timeUnit && device && gender && this.keywordGroups.length){
                const data = {
                    keywordGroups: this.keywordGroups,
                    timeUnit: timeUnit,
                    device: device,
                    gender,
                    startDate: moment(startDate).format("YYYY-MM-DD"),
                    endDate: moment(endDate).format("YYYY-MM-DD"),
                };

                const result = await dataLap.post(data);
                // if (result.data.length){
                this.$store.dispatch("generateChartData")
                // }
            }else{
                alert("값이 비어있습니다. 채워주세요");
            }
        },
      removeGroup(groupName) {
        this.keywordGroups = this.keywordGroups.filter(
          (li) => li.groupName !== groupName
        );
      },
      saveGroup() {
        if (this.form.groupName) {
          this.keywordGroups.push({
            groupName: this.form.groupName,
            keywords: this.keywords,
          });
          // 그룹 생성한후 현재 존재하는 groupName keywords 배열 비워주기
          this.form.groupName = "";
          this.keywords = [];
        }
      },
      removeKeyword(keyword) {
        this.keywords = this.keywords.filter((li) => li !== keyword);
      },
      saveKeyword() {
        if (this.form.keyword) {
          this.keywords.push(this.form.keyword);
        }
        // push로 넣었으니 값을 비우기
        this.form.keyword = "";
      },
    },
  
    data() {
      return {
        form: {
          // 시작날짜
          startDate: "",
          // 종료 날짜
          endDate: "",
          // 구간 단위
          timeUnit: "month",
          // groupName
          groupName: "",
          // keyword
          keyword: "",
          // device
          device: "all",
          // 성별
          gender: "all",
        },
        keywordGroups: [],
        keywords: [],
      };
    },
  };
  </script>
  
  <style>
  .groups-wrapper {
    text-align: center;
    display: flex;
    flex-direction: column;
    border: 1px solid #dddddddd;
    padding: 30px;
    /* margin:20px; */
    margin-bottom: 30px;
    /* justify-content: center; */
    align-items: stretch;
  }
  .create-button {
    width: 31%;
    margin-top: 30px !important;
    margin-left: 120px !important;
    /* margin-left: 40%; */
    /* margin: 0 auto !important;  */
  }
  
  .tag-wrapper {
    display: flex;
    flex-wrap: wrap;
    justify-content: center;
    margin-bottom: 12px;
  }
  
  .group-tag {
    width: 80px;
    font-size: 11px !important;
    margin: 3px;
    overflow: hidden;
    text-overflow: ellipsis;
    white-space: nowrap;
  }
  </style>