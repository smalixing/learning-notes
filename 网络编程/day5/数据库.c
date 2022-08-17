数据库
Ø数据（**Data）
能够输入计算机并能被计算机程序识别和处理的信息集合
Ø数据库 （**Database） 
数据库是在数据库管理系统管理和控制之下，存放在存储介质上的数据集合
常用的数据库
Ø大型数据库
•Oracle公司是最早开发关系数据库的厂商之一，其产品支持最广泛的操作系统平台。目前Oracle关系数据库产品的市场占有率名列前茅。
•IBM 的DB2是第一个具备网上功能的多媒体关系数据库管理系统，支持包Linux在内的一系列平台。
Ø中型数据库
•Server是微软开发的数据库产品，主要支持windows平台。
Ø小型数据库
•mySQL是一个小型关系型数据库管理系统，开发者为瑞典MySQL AB公司，2008年被Sun公司收购，开放源码。
基于嵌入式的数据库
Ø基于嵌入式Linux的数据库主要有SQLite, Firebird, Berkeley DB, eXtremeDB
ØFirebird是关系型数据库,功能强大,支持存储过程、SQL兼容等
ØSQLite关系型数据库,体积小,支持ACID事务
ØBerkeley DB中并没有数据库服务器的概念，它的程序库直接链接到应用程序中
ØeXtremeDB是内存数据库,运行效率高
SQLite基础
ØSQLite**的源代码是C，其源代码完全开放。SQLite第一个Alpha版本诞生于2000年5月。 他是一个轻量级的嵌入式数据库。**
ØSQLite**有以下特性：**
•零配置一无需安装和管理配置；
•储存在单一磁盘文件中的一个完整的数据库；
•数据库文件可以在不同字节顺序的机器间自由共享；
•支持数据库大小至2TB；
•足够小，全部源码大致3万行c代码，250KB；
•比目前流行的大多数数据库对数据的操作要快；
 
4安装方式
	1 本地安装 sudo dpkg -i *.deb
	2 在线安装
			apt-get update
			apt-get install sqlite3               ---》sqlite3数据库软件
			apt-get install libsqlite3-dev    ---》sqlite3数据库开发支持库
			apt-get install sqlite3-doc        ---》sqlite3数据库说明文档
						说明文档安装在/usr/share/doc/sqlite3目录下，是html文件使用自带浏览器打开
sqlite基础
	1、大小写敏感性
			有个重点值得注意，SQlite一般情况下是不区分大小写。
	2、注释
			可以使用c风格的注释 /*   */
			sqlite注释  --
	3、数据类型
			数据类型是指定任何对象的数据类型的属性
			Sqlite使用一个普遍的动态数据类型系统。
			在sqlite中值的数据类型与值本身相关，而不是与他的容器相关。
	4、存储类
			每个存储在sqlite数据库中的值都具有以下存储类之一
			NULL：值也是NULL值
			INTEGER：值是一个带符号整数
			REAL：值是一个浮点值
			TEXT：值是一个文本字符串
			BLOB：值是一个blob数据，完全根据他的输入存储
 
sqlite3命令语句
创建数据库




语法
sqlite3   stu.db（如果未创建表， 数据库将不会生成）
在当前目录下创建一个stu.db数据库

系统命令
		以点开头的，称为点命令




.help   帮助信息，获取所有的点命令清单
.quit
.exit   结束程序
.table  查看当前数据库表格
.schema 查看表格的结构
    .schema 《表名》
.databases 显示当前打开的数据库文件

 
 
sql语句
	以分号结尾的是sql语句
	1、创建表




sqlite> create table 表名(字段名 类型,字段名 类型,字段名 类型,········);
​
例子：sqlite> create table stuinfo(id int,name char, age int, score float);
​
通过.table点命令查看表格
.schema stuinfo查看表格结构

	2、删除表




sqlite> drop table 要删除的表名
​
例如sqlite> drop table test2;

	3、插入一条记录




方式1：
    sqlite> INSERT INTO 表名 VALUES(数据,数据,数据,······);
    例子sqlite> INSERT INTO stuinfo VALUES(1001,"fawaikuangtu",18,88);
方式2：
    sqlite> INSERT INTO 表名(字段名,字段名,···) VALUES (数据,数据,····);
    例子sqlite> INSERT INTO stuinfo(id,name,score) VALUES (1003,"jiesi",12345);





让表格变得好看
.header on
.mode column
.timer on
设置后显示
id          name          age         score     
----------  ------------  ----------  ----------
1001        fawaikuangtu  18          88.0      
1002        geleifusi                 99.0      
1003        cuitesi                   12345.0   
1003        jiesi                     12345.0   
1003        jiesi                     12345.0   
1003        jiesi                     12345.0   
1003        jiesi                     12345.0   
Run Time: real 0.003 user 0.000079 sys 0.000268

4、查看数据库记录




//查看所有字段
sqlite> SELECT * FROM  表名;
例子sqlite> SELECT * FROM stuinfo ;
​
//按照条件
sqlite> SELECT * FROM 表名 WHERE 字段 =数值 /and/or ····;
sqlite> SELECT * FROM stuinfo WHERE score =12345;
sqlite> SELECT * FROM stuinfo WHERE score =12345 or id=1003;
sqlite> SELECT * FROM stuinfo WHERE score =12345 and id=1003;
​
//查询指定字段
sqlite> SELECT 字段 , 字段··· from 表名 ;
例子 sqlite> SELECT id,score FROM stuinfo ;
    sqlite> SELECT id,score FROM stuinfo WHERE score = 99;
    
//查看前n条记录
sqlite> SELECT * FROM stuinfo limit n;
sqlite> SELECT * FROM stuinfo limit 3;查看前三条
​
//从大到小排序
sqlite> SELECT * FROM stuinfo ORDER BY score DESC ;
​

5、更新一条记录




sqlite> UPDATE 表名 SET 更新字段=更新值 where 查找字段 = 查找值 ;
sqlite> UPDATE stuinfo SET age=20 where score = 6789 ;

6、删除一条记录




sqlite> DELETE FROM 表名 ;//清空表格中所有记录
sqlite> DELETE FROM 表名 WHERE 字段=数值 /and/or ····;
sqlite> DELETE FROM stuinfo WHERE id=1003;

7、设置主键




sqlite> create table stu(id int PRIMARY KEY,name char ,score float);
PRIMARY KEY 约束数据库表中记录是唯一标识
加入此标识后，该字段不能有重复数据
每个表中应该有一个主键，并且每一个表只能有一个主键

8、增加一列




sqlite> ALTER TABLE 表名 add COLUMN 字段 类型;
sqlite> ALTER TABLE stuinfo add COLUMN nu int;

 
SQLite3编程接口
API手册
	可以通过安装的手册，说明文档安装在/usr/share/doc/sqlite3目录下，是html文件使用自带浏览器打开
	也可以访问官网查看https://www.sqlite.org/index.html
1、打开数据库（存在就打开，不存在就创建）




#include <sqlite3.h>
​
int sqlite3_open(
  const char *filename,   /* Database filename (UTF-8) */
  sqlite3 **ppDb          /* OUT: SQLite db handle */
);
功能：打开或创建数据库
参数：
    const char *filename ：数据库文件路径名
    sqlite3 **ppDb ：指向sqlite句柄的指针
                    打开数据库后可以通过第二个参数的一级指针来操作数据库；
                    二级指针，定义一个一级指针，然后取地址传递给函数；
返回值：
    成功：返回0，SQLITE_OK
    失败：返回错误码（非零值）
​
示例
    sqlite3 * db = NULL;
    sqlite3_open("my.db",&db);

2、关闭数据库




int sqlite3_close(sqlite3*db);
功能：关闭数据库
返回值：
    成功0，SQLITE_OK
    失败：返回错误码（非零值）
sqlite3_close(db);

3、得到错误信息
一般放到打开数据库函数失败后面




const char *sqlite3_errmsg(sqlite3*db);
参数：
    sqlite3*db 句柄
返回值：
    返回错误码对应的文字说明 //类似malloc
例：
    fprintf(stderr,"打开数据库：%s"，sqlite3_errmsg(db));
​
注意：
    void sqlite3_free(void *);
    sqlite3_errmsg返回的errmsg必须用此函数释放
        释放存放错误信息的内存空间
例：
    char * err  = sqlite3_errmsg(db);
    fprintf(stderr,"打开数据库：%s"，err);        
    sqlite3_free(err);

 
4、编译：需要加 -lsqlite3 链接库
5、数据库操作




int sqlite3_exec(
  sqlite3*db,                                  /* An open database */
  const char *sql,                           /* SQL to be evaluated */
  int (*callback)(void*arg,int,char**,char**),  /* Callback function */
  void *arg,                                    /* 1st argument to callback */
  char **errmsg                              /* Error msg written here */
);
功能：执行一条sql语句
参数：
    sqlite3*db 数据库句柄
    const char *sql：sql语句
    callback：回调函数，只有在查询时采用
    void *arg：为回调函数传递参数
    char **errmsg：错误消息（需要定义一个char*的指针）
                这个可以直接用printf("%s",errmsg);打印
返回值：
    成功：SQLITE_OK
    失败：返回错误码
    

 
回调函数




int callback(void*para,int f_num,char**f_value,char**f_name)
功能：每找到一条记录，就会自动执行一次回调函数
参数：
    void*para：exec第四个参数 传递给回调函数的参数
    int f_num：表的列数。记录中 包含的字段数目，标识字段中有多少串（多少列）
    char**f_value：查询结果的指针数组。（包含每个字段的指针数组）
            f_value[0] = "1001"
            f_value[1] = "zhangsan"
            f_value[2] = "18"
            f_value[3] = "66"
    char**f_name:指向字段名的指针数组。
            f_name[0]  = "id"
            f_name[1]  = "name"
            f_name[2]  = "age"
            f_name[3]  = "score"
返回值：
    成功：0
    失败：-1






                                           
#include <stdio.h>                                                
#include <sqlite3.h>                                              
#include <string.h>                                               
                                                                  
#define DATABASE "my.db"                                     
                                                                  
static int callback(void*para,int f_num,char ** f_value,char ** f_name)
{                                                                 
    int i =-1,j=-1;                                               
    //打印传入的参数                                              
    printf("para:%s\n",(char*)para);                              
                                                                  
    //打印表头                                                    
    for(j=0;j<f_num;j++)                                          
        printf("%-15s",f_name[j]);                                
    putchar(10);                                                  
                                                                  
    //打印查询到的内容                                            
    for(i=0;i<f_num;i++){                                         
        if(!strncasecmp((char*)para,f_value[2],3))                
            printf("%-15s",f_value[i]);                           
    }                                                             
    putchar(10);                                                  
    return 0;                                                     
}                                                                 
                                                                  
                                                                  
                                                                  
int main(int argc, char **argv)                                   
{                                                                 
    sqlite3* db = NULL;                                           
    char *errmsg = NULL;                                          
                                                                  
    if(sqlite3_open(DATABASE,&db)!=SQLITE_OK){                    
        fprintf(stderr,"open %s\n",sqlite3_errmsg(db));           
        return -1;                                                
    }                                                             
    else {                                                        
        printf("数据库打开成功\n");                               
    }                                                             
                                                                  
    //创建一个表格                                                
    char * create_table =                                         
        "create table if not exists stu(id int,name char,sex char ,score int)";
        //如果表格不存在就创建                                    
    if(sqlite3_exec(db,create_table,NULL,NULL,&errmsg)!=SQLITE_OK){
        fprintf(stderr,"操作出错：%s",errmsg);                    
        sqlite3_close(db);                                        
        return -2;                                                
    }                                                             
    else{                                                         
        puts("创建或打开成功");                                   
    }                                                             
                                                                  
    //插入一条数据                                                
    if( sqlite3_exec(db,"insert into stu values(1001,'zhangsan','man',999)",
            NULL,NULL,&errmsg) != SQLITE_OK){                     
        fprintf(stderr,"open %s\n",sqlite3_errmsg(db));           
        sqlite3_close(db);                                        
        return -3;                                                
    }                                                             
    else{                                                         
        puts("插入成功");                                         
    }                                                             
                                                                  
                                                                  
    if(sqlite3_exec(db,"select * from stu;",callback,"man",&errmsg)!=SQLITE_OK){
        fprintf(stderr,"查询 %s\n",sqlite3_errmsg(db));           
        sqlite3_close(db);                                        
        return -3;                                                
    }                                                             
    else{                                                         
        puts("查询成功");                                         
    }                                                             
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
    sqlite3_close(db);                                            
    puts("关闭数据库");                                           
    return 0;                                                     
}                                                

 
不使用回调函数执行SQL语句




int sqlite3_get_table(
  sqlite3 *db,          /* An open database */
  const char *sql,     /* SQL to be evaluated */
  char ***pazResult,    /* Results of the query */
  int *pnRow,           /* Number of result rows written here */
  int *pnColumn,        /* Number of result columns written here */
  char **pzErrmsg       /* Error msg written here */
);
功能：执行sql语句
参数：
    sqlite3 *db:数据库句柄
    const char *sql：sql语句
    char ***pazResult用来指向 存放所有查询到的结果 的指针
            是一个 【((指针)数组)数组】
    int *pnRow：满足条件的个行数（条数）
    int *pnColumn：满足条件的字段（列数）
    char **pzErrmsg:错误信息的地址
返回值
        成功SQLITE_OK
        失败错误码
​
void sqlite3_free_table(char **result);


 
 
 
 
 
 
 
 