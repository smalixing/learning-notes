# GIT分布式管理系统

起初目的管理linux内核

安装方法：

​	centos:   yum -y install git

​	ubuntu:   apt-get install git-all

​	windows:官网下载安装



#### git基本命令：

```
安装完成后进行全局配置：
git config --global user.name "smallxing"//使用名，随便取
git config --global user.name "zhaoxing010513@163.com"//自己的电子邮箱
目的：方便查看是谁做了什么

cat ~/.gitconfig
查看配置

创建新的仓库
mkdir git-tutorial
cd git-tutorial
git init  //初始化
创建文件 如：touch README.md

查看仓库状态
git status
暂存文件
git add README.md	//git add .暂存所有文件
取消README.md文件的暂存
git rm --cached README.md
暂存所有文件
git add -A 

暂存的所有文件放在暂存区中具体位置为./.git/index
	cd .git
	cat index

将暂存区的文件提交到git的本地仓库中，代表仓库到了一个交付的状态
git commit -m "add "	//""中间写如提交的提示内容，方便区分

github创建仓库、获得仓库链接

添加远端地址（直接复制github代码）
git remote add origin https://github.com/brave-acher/learning-notes.git

git remote -v//查看

提交到远端仓库github
git push -u origin master	//-u目的，以后直接git就好 

拉取远端仓库
git clone https://github.com/brave-acher/learning-notes.git
成功后获得一个仓库的文件夹，如果已经有了，便更新变动
```



