#include<stdio.h>

int a[100],n,sum=0;
void output();
void try(int k);

int main(void)
{
	int i;
	scanf("%d",&n);
	for(i=1; i<=9; i++)
	{
		a[1]=i;
		sum=i;
		try(2);
		sum=0;
	}
	return 0;
}

void try(int k)
{
	int i;
	sum*=10;
	if(k>n) {
		output();
	} else {
		for(i=0; i<=9; i++)
		{
			sum+=i;
			if(sum%k==0) {
				a[k]=i;
				try(k+1);
			}
			sum-=i;
		}
	}
}

void output()
{
	int i;
	for(i=1; i<=n; i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
}