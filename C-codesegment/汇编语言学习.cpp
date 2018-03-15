#include <stdio.h>

struct company {   //定义一个公司记录的结构体 
	char cn[4];    //公司名称 
	char hn[10];    //总裁姓名 
	int pm;        //排名 
	int sr;        //收入 
	char cp[4];    //著名产品 
};

main()
{
	struct company dec={"DEC", "Ken Olsen", 137, 40, "PDP"};  //定义一个公司记录的变量,内存中将存有一条公司的记录
	
	int i;
	dec.pm = 38;
	dec.sr = dec.sr + 70;
	i = 0;
	dec.cp[i] = 'v';
	i++;
	dec.cp[i] = 'A';
	i++;
	dec.cp[i] = 'X';
	printf("该公司基本情况:\n");
	printf("名称:%s\n  排名:%d\n 收入:%d \n 产品:%s\n", dec.cn, dec.pm, dec.sr, dec.cp);
	printf("姓名:%s\n", dec.hn);
	return 0;
}
 
