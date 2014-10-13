#include<stdio.h>

int n,a[100],p=0;

void try(int k);
void output();
void swap(int *b, int f, int l);

int main(void)
{
	int i;
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{
		a[i]=i;
	}
	try(1);
	return 0;
}

void try(int k)
{
	int i;
	if(k>n) {
		output();
	} else {
		for(i=k; i<=n; i++)
		{
			swap(a,k,i);
			try(k+1);
			swap(a,k,i);
		}
	}
}

void output()
{
	int i;
	p++;
	printf("%d  :",p);
	for(i=1; i<=n; i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
}

void swap(int *b, int f, int l)
{
	int temp;
	temp=b[f];
	b[f]=b[l];
	b[l]=temp;
}