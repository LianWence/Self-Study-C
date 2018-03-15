
/*
                   2015.8.15  0:20   编写了一个查看运势的小程序 
              枚举的用法，枚举保证了代码的安全性，但使得代码的编写较为麻烦 
*/
#include <stdio.h>

enum weekday 
{
	monday=1, tuesday, wednesday, thursday, friday, saturday, sunday
}; // 定义了一个枚举数据类型enum weekday  并列举了其所有可能存储的值（元素也行） 

void output(enum weekday );

int main(void)
{
	enum weekday day = wednesday;
	
	output(day);
	
	return 0;
}

void output(enum weekday what)
{
	switch (what)
	{
		case 1:
			printf("今天运气会很棒！\n");
			break;
		case 2:
		    printf("今天阁下会有桃花运！\n");
			break;
		case 3:
		    printf("今天运势一般！\n");
			break;
		case 4:
		    printf("今天运势渐长，幸福指数还凑活！\n");
			break;
		case 5:
		    printf("今天不适合嫖娼，注意身体！\n");
		    break;
		case 6:
		    printf("今天是个好日子，建议去户外活动！\n");
		    break;
		case 7:
		    printf("今天撸管要带套，祝你性福快乐！\n");
			break;						
	}
}
