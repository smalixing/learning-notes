.text
.global _start
_start:

@以软中断讲解异常处理
@场景：在user模式下，遇到了软中断(SWI)

@异常向量表 (跳转指令)
B reset
NOP
LDR PC,_soft_interrupt
nop
nop
nop
LDR PC,_irq_interrupt
nop 



_soft_interrupt: .word swi_handler
_irq_interrupt:  .word irq_handler


reset:
@复位 svc模式

/* svc模式 分配栈空间 */
LDR SP,=buf+512*3


/* irq模式 分配栈空间 */
MRS R0,CPSR
BIC R0,#0X1F
ORR R0,#0X12
MSR CPSR,R0 
LDR SP,=buf+512*2


/* 切换到user模式 */
MRS R0,CPSR
BIC R0,#0X1F
ORR R0,#0X10
MSR CPSR,R0 
LDR SP,=buf+512


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
	/* 入栈 保护现场 */
	STMFD SP!,{R0-R12,LR}
	
	MOV R0,#0X1F
	MOV R1,#0X13
	MOV R2,#0X2d
	MOV R3,#0Xc3
	MOV R4,#0X8a
	
	@lr ->pc
	@spsr -> cpsr  还原到之前的工作模式
	/* 出栈 恢复 */
	LDMFD SP!,{R0-R12,PC}^

irq_handler:
	/* 入栈 保护现场 */
	STMFD SP!,{R0-R12,LR}
		
	/* irq中断处理 */
	

	/* 出栈 恢复 */
	LDMFD SP!,{R0-R12,PC}^
.DATA
	
	
buf:
	.space 512*3  

.end
