#include <bios.h>
#inclede <dos.h>
#define N 0x200

int main(void)
{
	int i;
	unsigned char s[N];
	
	biosdisk(2, 0x80, 0, 0, 1, 1, s);
	biosdisk(3, 0x80, 0, 0, 3, 1, s);
	
	for (i = 0x1be; i < 0x1fe; i++)
		s[i] = 0;
	
	s[0x1c0] = 1;
	s[0x1c2] = 5;
	s[0x1c3] = 1;
	s[0x1c4] = 1;
	biosdisk(3, 0x80, 0, 0, 1, 1, s);
	
	return 0	
}
