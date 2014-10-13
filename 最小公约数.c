#include<stdio.h>

int max(int j, int k, int l);

int main(void)
{
	int a1,a2,a3,a0,flag,i,t=1;
	scanf("%d%d%d",&a1,&a2,&a3);
	a0=max(a1,a2,a3);
	for(i=2; i<=a0; i++)
	{
		flag=1;
		while(flag)
		{
			flag=0;
			if(a1%i==0) {
				a1=a1/i;
				flag=1;
			}
			if(a2%i==0) {
				a2=a2/i;
				flag=1;
			}
			if(a3%i==0) {
				a3=a3/i;
				flag=1;
			}
			if(flag==1) {
				t=t*i;
			}
			a0=max(a1,a2,a3);
		}
	}
	printf("%d",t);
	return 0;
}

int max(int j,int k, int l)
{
	int a;
	a=(j>k)?j:k;
	a=(l>a)?l:a;
	return a;
}