.text


LDR R0,=buf

@LDRB R1,[R0,#1]   @ *(ptr+1)
s
@LDRB R1,[R0,#1]!  @ *(++ptr)

LDRB R1,[R0],#1    @ *(ptr++)


STOP:
	B STOP
	
.DATA

buf:
	.byte 0x1,0x2,0x3,0x4
	
.end
