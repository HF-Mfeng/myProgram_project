
//引入发送请求的模块
import{ request } from "../../request/index.js"

Page({
  data: {
    //轮播图数组
    swiperlist:[],

    //导航栏的数组
    catelist:[],

    //楼层数组
    floorlist:[]
  },

  onLoad: function (options) {
    //发送异步请求，获取轮播图数据
    // wx.request({//   url: 'https://api-hmugo-web.itheima.net/api/public/v1/home/swiperdata', //   method:'GET',dataType: 'json',//   responseType:'text',//   success: (result) => {//     this.setData({ //       swiperlist:result.data.message //     }) //   }, //success结束处 // })  //request结束处

    this.getcatelist();
    this.getswiperlist();
    this.getfloorlist();

  },  //onLoad结束处

  //获取轮播图数据的方法
  getswiperlist(){
    request({url:"/home/swiperdata"})
    .then(liang=>{
      this.setData({
        swiperlist: liang.data.message
      })
    })
  } , //getswiperlist结束处

  //获取轮播图数据的方法
  getcatelist(){
    request({url:"/home/catitems"})
    .then(liang=>{
      this.setData({
        catelist: liang.data.message
      })
    })
  } , //getcatelist结束处
  
  //获取楼层数据的方法
  getfloorlist(){
    request({url:"/home/floordata"})
    .then(liang=>{
      this.setData({
        floorlist: liang.data.message
      })
    })
  } , //getfloorlist结束处


})