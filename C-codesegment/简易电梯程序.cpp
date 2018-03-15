/*
       2015.8.10  13:13
       利用switch多重选择结构实现使用电梯的简易程序! 
*/
#include <stdio.h>
int main(void)
{
	int val;
	char ch, c;
	
	do
	{ 
	
	    printf ("请输入您想到达的楼层：");
	    scanf ("%d", &val);
	
	    while ((c=getchar()) != '\n')
	         continue; 
	    
	    switch (val)
	    {
		    case 1:  // case后面不论是跟常量表达式还是数值，都只能是唯一的一种情况！否则编译出错！！！！ 
			    printf ("正在到达第%d层\n", val);
			    break;
		    case 2:
		        printf ("正在到达第%d层\n", val);
			    break;
		    case 3:
		        printf ("您好第%d层正在维修中，请您选择就近的楼层。给您带来不便，请谅解\n", val);
			    break;
		    case 4:
		        printf ("正在到达第%d层\n", val);
			    break;
		    case 5:
		        printf ("您好,本楼层还在新建中！电梯暂时无法使用！抱歉\n");
			    break;
		    default :
		        printf ("您好，本楼层目前只有5层！如有不便，敬请见谅！\n");
			    break;				
		}
	printf ("如果您需要重新输入，请按（y或者Y）即可，按其他任意键则退出使用：");
	scanf (" %c", &ch);     //注意控制符%C前面要留有空格符“空白符的意义重大，在此不做讨论” 
    } while ( 'y'==ch || 'Y'==ch );    //再次使用do-while循环结构实现人机交互！ 
	
	printf ("您好，欢迎乘坐本次电梯，祝您生活愉快！\n");
	
	return 0;
}
/*
    验证switch多选结构的用法，很开心！！！ 
*/

