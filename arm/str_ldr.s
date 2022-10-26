.text

LDR R0,=buf  @r0的值是buf的首地址

LDR R2,=0X11223344 

STR R2,[R0]  @*R0 = R2

LDRB R1,[R0]  @R1 = *R0 ,只读1个字节


STOP:
	B STOP
	
.DATA
buf:
	.space 32    @类似于 char buf[32]; 
	
.end
