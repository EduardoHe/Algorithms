#include<stdio.h>

int main(void)
{
	int i,j=0,k,a[17];
	for(i=0; i<16; i++)
	{
		a[i]=i+1;
	}
	a[16]=0;
	while(j!=a[j])
	{
		for(i=1; i<=3; i++)
		{
			k=j;
			j=a[k];//得到下一个点的下标
		}
		a[k]=a[j];
	}
	printf("%d",j);
	return 0;
}