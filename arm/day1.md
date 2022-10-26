## ARM体系结构 

##### 课程安排： 3 (基础理论，arm汇编指令) + 4（裸机编程）

##### 课程特点：软硬结合，（硬件的基础知识，arm汇编， 裸机编程，芯片手册）



## 一、理论知识

#### 1.ARM简介	

##### 		1.一个公司      

##### 		2.一系列的芯片

~~~
精简指令集RISC
低功耗
主流的产品线，A系列，R系列，M系列
~~~

##### 		3.ARM开发技术



#### 2.工作模式 

| 模式       | 简介                                               |
| ---------- | -------------------------------------------------- |
| User       | 非特权模式，大部分任务执行在这种模式               |
| FIQ        | 当一个高优先级（fast) 中断产生时将会进入这种模式   |
| IRQ        | 当一个低优先级（normal) 中断产生时将会进入这种模式 |
| Supervisor | 当复位或软中断指令执行时将会进入这种模式           |
| Abort      | 当存取异常时将会进入这种模式                       |
| Undef      | 当执行未定义指令时会进入这种模式                   |
| System     | 使用和User模式相同寄存器集的特权模式               |

Cortex-A特有模式：
	Monitor : 是为了安全而扩展出的用于执行安全监控代码的模式； 
     也是一种特权模式

#### 3.寄存器

##### 经典模型 37个寄存器

##### 		1 个用作PC( program counter)          

##### 		1个用作CPSR(current program status register)

##### 		5个用作SPSR(saved program status registers)

##### 		30 个通用寄存器 

##### A系列： 40（37+3 ) 

~~~
R15(PC)  : 程序计数器
R14(LR)  : 链接寄存器， 记录pc值，用于返回
~~~

## 二、环境搭建



## 三、ARM汇编指令

~~~c
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

~~~



## 作业

~~~
1.练习arm汇编指令，尝试模式切换svc->irq, irq->user

2.cpu， soc， mcu，是什么？

~~~

