.text

LDR R0,=buf+32

MOV R5,#0X14
MOV R6,#0X73
MOV R7,#0XAC
MOV R8,#0X43

STMFD R0!,{R5-R8}   @入栈->地址走向：从高到低

MOV R1,#0X11
MOV R2,#0XFF

STMFD R0!,{R1-R2}   @入栈->地址走向：从高到低

LDMFD R0!,{R10-R11} @出栈->地址走向：从低到高


STOP:
	B STOP
	
.DATA

buf:
	.space 32
	
.end
