#include<stdio.h>

int w[100],p[100],x[100],x1[100],sum=0,total=0,m,n,sumx=0,r[100];
void try(int k);
int bound(int a,int b);

int main(void)
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=1; i<=n; i++)
	{
		scanf("%d%d",&w[i],&p[i]);
	}
	r[n]=p[n];
	for(i=n-1; i>1; i--)
	{
		r[i]=r[i+1]+p[i];
	}
	try(1);
	for(i=1; i<=n; i++)
	{
		if(x1[i]==1)
			printf("bag%d  ",i);
	}
	return 0;
}

void try(int k)
{
	int i;
	if(k==n+1)
	{
		if(sum>sumx)
		{
			sumx=sum;
			for(i=1; i<=n; i++)
			{
				x1[i]=x[i];
			}
		}
		return ;
	}
	if(total+w[k]<=m)
	{
		x[k]=1;
		total=total+w[k];
		sum=sum+p[k];
		try(k+1);
		sum=sum-p[k];
		total=total-w[k];
		x[k]=0;
	}
	if(bound(sum,k))
	{
		x[k]=0;
		try(k+1);
	}
}

int bound(int a,int b)
{
	if(a+r[b]-p[b]>=sumx)
		return 1;
	else
		return 0;
}
