<template>
    <div>
        <el-form ref="form" label-width="120px">
            <div class="groups-wrapper">
                <!-- 키워드를 저장할때마다 키워드 배열에 담긴다 -->
                <!-- 주제 생성하기를 누르면 해당 keyword들을 가지고 있는 배열을 생성 -->
                <el-form-item style="width:500px" label="키워드">
                    <el-input v-model="form.keyword">
                        <el-button>키워드 추가</el-button>
                    </el-input>
                </el-form-item>

                
            </div>
        </el-form>
    </div>
</template>

<script>
export default {
    data(){
        return {
            form:{
                startDate:"",// 시작날짜
                endDate:"",// 종료날짜
                timeUnit:"",// 구간단위
                groupName:"",// groupName
                keyword:"",// keyword
                device:"all",// device
                gender:"all",// 성별
            },
            keywordGroups: [],
            keywords: []
        }
    }
}
</script>

<style>

</style>