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

LDR SP,=buf+256
MRS R0,CPSR
BIC R0,#0X1F
ORR R0,#0X10
MSR CPSR,R0 


@LDR SP,=buf+256
MOV R0,#0X1
MOV R1,#0X2
SWI 1
ADD R2,R0,R1
NOP
NOP

STOP:
	B STOP

@软中断处理函数
swi_handler:
	@入栈 保护现场
	STMFD SP!,{R0-R12,LR}
	
	MOV R0,#0X1F
	MOV R1,#0X13
	MOV R2,#0X2d
	MOV R3,#0Xc3
	MOV R4,#0X8a
	
	@出栈 恢复
	@lr ->pc
	@spsr -> cpsr  还原到之前的工作模式
	LDMFD SP!,{R0-R12,PC}^

.DATA
	
buf:
	.space 256

.end