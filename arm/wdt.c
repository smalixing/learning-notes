

#define GPF3CON *(volatile unsigned int *)0x114001E0
#define GPF3DAT *(volatile unsigned int *)0x114001E4

/*串口2相关寄存器*/
#define GPA1CON		*(volatile unsigned int *)0x11400020
#define ULCON2		*(volatile unsigned int *)0x13820000
#define UCON2		*(volatile unsigned int *)0x13820004
#define UTRSTAT2	*(volatile unsigned int *)0x13820010
#define UTXH2		*(volatile unsigned int *)0x13820020
#define URXH2		*(volatile unsigned int *)0x13820024
#define UBRDIV2		*(volatile unsigned int *)0x13820028
#define UFRACVAL2	*(volatile unsigned int *)0x1382002C

/* 看门狗相关寄存器 */
#define WTCON	*(volatile unsigned int *)0x10060000
#define WTCNT	*(volatile unsigned int *)0x10060008

void wdt_init(void)
{
	WTCNT = 15259; 
 
	WTCON |= (0xff<<8); //预分频255
	WTCON |= (0x3<<3);  //二分频128
	WTCON &= ~(0x1<<2); //非中断
	WTCON |= (0x1<<5)|(0x1<<0); //启动wdt
}

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
	wdt_init();

	while(1)
	{
		send_string("running...\r\n");
		//WTCNT = 15259;   //循环中喂狗

		delay(1000);
	}

	return 0;
}
