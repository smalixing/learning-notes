## 一、ARM汇编指令

~~~cpp
//空指令
nop
nop

//传输指令
MOV   R1,#3     @R1=3
MOV   R1,#0x17  @R1=0x17
MOV   R0,R1     @R0=R1
MVN   R0,R1     @R0=~R1

//算术指令
ADD R0,R1,R2    @R0=R1+R2
    //ADD  不带进位的加法
    //ADDS 带进位的加法，进位时反映到CPSR中C位
    //ADDC 带进位的加法，加运算时，加上CPSR中的C位
    
SUB  R0,R1,#3   @R0= R1 - 3
MUL  R1,R2,r3   @R1=R2*r3
ADD  R0,#1      @R0=R0+1


//移位指令
//LSL逻辑移位
//ASL算术移位

MOV R0,R1,LSL#2   @R0=R1<<2
MOV R2,R1,LSR#1   @R2=R1>>1
ADD R2,R0,LSL#1   @R2 = R2 + R0<<1
    

//跳转
 B   label        //跳转到label标签 
 B    main        //跳转到标号为main地代码处 
 BL   func        //保存下一条要执行的指令的位置到 LR寄存器,跳转函数func
                  ///当跳转代码结束后,用MOV PC,LR返回

//CPSR访问指令(mrs msr)
MRS R0,CPSR  @ R0 = CPSR
MSR CPSR,R0  @ CPSR = R0
    
    
//位运算 AND ORR BIC TST
    
AND R0,R1,#0xFF   // r0 = r1&0xFF
ORR R3,R0,#0x0F   // r3 = r0|0x0F
BIC R0,R0,#0x03   // 清除r0中的0号位和1号位
TST R0,#0x20      //测试第5位是否为0 ，为0则Z标志置1
    

//比较指令      
 CMP r0,r1,       // 比较R0与R1的值
//注意：比较结果反映在CPSR中的N z c位
//配合着条件码使用

//练习
//1.测试当前工作状态是否是ARM, 是的话 r5=0xff
MRS R0,CPSR
TST R0,#0X20
MOVEQ R5,#0XFF
//2.修改当前的工作模式，切换到user模式
MRS R0,CPSR
BIC R0,#0X1F
ORR R0,#0X10
MSR CPSR,R0
    
//load/store指令
LDR R0,[R1]  @ R0 = *R1
//LDR 读4字节  LDRH 读2字节  LDRB 读1字节
STR R0,[R1]  @ *R1 = R0

    
~~~



## 二、立即数合法性分析

~~~c++
//在32位arm架构下
//arm指令占32bit位，其中立即数所占bit位12位(4位移位数，8位基数)

//合法的立即数，必须能够分解成（移位数占4位+基数占8位）
//1.满足基数，<=8bit位
//2.满足移位数是偶数（通过基数循环右移 移位数*2 ）

例如：0xF000000F,可以通过 基数(0xff) +移位数(2) 得到
//                        0xff 循环向右移动2*2 即可得到0xF000000F
例如：0x00001f80，可以通过 基数(0x7E) +移位数(13)得到
//                        0x7E 循环向右移动13*2即可得到0x00001f80

~~~



## 作业

~~~c
1.练习：汇编指令

2.试分析下面的数是否是合法的立即数
b) 0x08000012     c) 0x001f70   d) 0x7000000f 

~~~

