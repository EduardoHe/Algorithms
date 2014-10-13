#include<stdio.h>

int main(void)
{
	unsigned int n,temp;
	scanf("%d", &n);
	temp = n - ((n >>1) &0x77777777) - ((n >>2) &0x33333333) - ((n >>3) &0x11111111);
	temp = ((temp + (temp >>4)) &0x40f0f0f0) %255;
	/*temp = n - ((n >>1) &033333333333) - ((n >>2) &011111111111);
	temp = ((temp + (temp >>3)) &030707070707) %63;*/
	printf("%d", temp);
	return 0;
}