
//引入发送请求的模块
import{ request } from "../../request/index.js"

Page({
  data: {
    //左侧菜单数据
    leftMenuList:[],
    //右侧数据
    rightMenuList:[],
    currentIndex:0
  },
       //接口返回的数据
       Cates:[],

  onLoad: function (options) {
    this.getcates();
  },
  
  //获取分类数据
  getcates(){
    request({url:"/categories"})
    .then(res=>{
      this.Cates=res.data.message;
      //左侧数据赋值
      let leftMenuList=this.Cates.map(v=>v.cat_name);
      //左侧数据赋值
      let rightMenuList=this.Cates[0].children;
      this.setData({
        leftMenuList,
        rightMenuList
      })
    })
  },
  hangleItemTap(e){
    const {index} =e.currentTarget.dataset;
    this.setData({
      currentIndex:index
    })
  }
})