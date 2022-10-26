

#define GPF3CON *(volatile unsigned int *)0x114001E0
#define GPF3DAT *(volatile unsigned int *)0x114001E4

/*串口2相关寄存器*/

#define GPA1CON  *(unsigned int*)0x11400020
#define ULCON2  *(unsigned int*)0x13820000
#define UCON2  *(unsigned int*)0x13820004
#define UTRSTAT2  *(unsigned int*)0x13820010
#define UTXH2  *(unsigned int*)0x13820020
#define URXH2  *(unsigned int*)0x13820024
#define UBRDIV2  *(unsigned int*)0x13820028
#define UFRACVAL2  *(unsigned int*)0x1382002C

void uart_init(void) //串口初始化
{
	GPA1CON = (GPA1CON & ~(0XFF))|0X22;
    ULCON2=0x3;
    UCON2=0x5;

	/* 波特率设置 为115200 */
    UBRDIV2=53;
    UFRACVAL2=4;
	

	/* 波特率设置 为9600 */
    //UBRDIV2=650;
    //UFRACVAL2=6;

}
char uart_getchar(void) 
{
	while(! (UTRSTAT2&0x1) ); 

	return URXH2 &(0XFF);
}
void uart_putchar(char ch)
{
	while(1){
		if( UTRSTAT2 &(0x1<<1) ){  //发送完成后 结束循环
			break;
		}
	}

	UTXH2 = ch;
#if 0
	while( ! (UTRSTAT2 &(0x1<<1)) );
	UTXH2 = ch;
#endif 
}
void send_string(char *str)
{
	while(*str!='\0'){
		uart_putchar(*str++);
	}
}

void led4_init(void)
{
	GPF3CON = GPF3CON & (~(0xf<<4*4));
	GPF3CON = GPF3CON | (0x1<<4*4);
}
void led4_on(void)
{
	GPF3DAT = GPF3DAT | (0x1<<4);
}
void led4_off(void)
{
	GPF3DAT = GPF3DAT & ~(0x1<<4);
}

void delay(int x)
{
	int i,j;
	for(i=0;i<x;i++){
		for(j=0;j<2000;j++){
			;
		}
	}
}

int main(void)
{	
	
	uart_init();
	
	send_string("uart_test\r\n");
	
	char ch;

	while(1)
	{
		ch = uart_getchar();


		send_string("recv:");
		uart_putchar(ch);
	}

	return 0;
}
