.text
.global _start
_start:

@以软中断讲解异常处理
@场景：在user模式下，遇到了软中断(SWI)

@异常向量表 (跳转指令)
B reset
NOP
B swi_handler
nop
nop
nop
nop
nop 


reset:
MRS R0,CPSR
BIC R0,#0X1F
ORR R0,#0X10
MSR CPSR,R0 


MOV R0,#0X11
MOV R1,#0X22
SWI 1
ADD R2,R0,R1
NOP
NOP


STOP:
	B STOP


@软中断处理函数
swi_handler:
	nop
	nop
	nop
	MOV PC,LR


.DATA

.end
