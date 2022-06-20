# MFC-stu  
Windows MFC frame  

源码访问链接：  
gitee:   https://gitee.com/piazini/MFC-stu  
github:  https://github.com/piazini/MFC-stu  

提交代码前，清理编译临时文件：  
clean-build.bat  

项目，目录说明  
├─Other	其他，一些收集的代码
├─DockedHide	靠边隐藏窗口  
├─GetFileIcon	获取文件图标  
├─HideWnd	靠边隐藏窗口  
├─RMenu	右键菜单  
├─RWIni	读写ini配置文件
└─OutlookBar 仿Outloo上下滚动菜单 
  
  
  
--------------------------------------  
# VC++ 6.0 BUG  问题解决  

双击dsw文件打开，VC++ 6.0崩溃？  
解决方法：先打开VC++ 6.0，然后将dsw后缀文件拖入到工作空间。  
  
新增加类不显示？  
解决方法：  
1.确认文件定义、声明都正确。  
2.关闭工作空间，删除该项目，目录下*.ncb和*.opt两个文件，重新打开工作空间。  