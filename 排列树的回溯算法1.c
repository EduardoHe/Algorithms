#include<stdio.h>

int p=0,n,a[100],d[100];
void try(int k);
void out();

int main(void)
{
	int j;
	scanf("%d",&n);
	for(j=1; j<=n; j++)
	{
		d[j]=0;
	}
	try(1);
	return 0;
}

void try(int k)
{
	int j;
	for(j=1; j<=n; j++)
	{
		if(d[j]==0) {
			a[k]=j;
			d[j]=1;
		} else {
			continue;
		}
		if(k<n) {
			try(k+1);
		} else {
			p++;
			out();
		}
		d[j]=0;
	}
}

void out()
{
	int j;
	printf("%d  :",p);
	for(j=1; j<=n; j++)
	{
		printf("%d",a[j]);
	}
	printf("\n");
}