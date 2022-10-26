.text
.global _start
.global test
_start:

LDR SP,=buf+256
MOV R0,#0X3
MOV R1,#0X4

BL fun_add

STOP:
	B STOP

test:
	nop
	nop
	nop
	MOV PC,LR

.data

buf:
	.space 256


.end
