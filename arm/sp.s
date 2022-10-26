.text

LDR SP,=buf+32   @sp指针 指向栈空间

MOV R0,#0X11
MOV R1,#0X22
MOV R2,#0X33
MOV R3,#0X44


STMFD SP!,{R0-R3}

LDMFD SP!,{R9-R12}


STOP:
	B STOP
	
.DATA

buf:
	.space 32
	
.end
