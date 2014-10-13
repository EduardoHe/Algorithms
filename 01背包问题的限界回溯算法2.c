#include<stdio.h>

int w[100],p[100],x[100],x1[100],sum=0,total=0,m,n,sumx=0,l=0,r[100];
void try();
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
	try();
	for(i=1; i<=n; i++)
	{
		if(x1[i]==1)
			printf("bag%d  ",i);
	}
	return 0;
}

void try()
{
	int i=1,j;
	while(1)
	{
		while(i<=n&& total+w[i]<=m)
		{
			total+=w[i];
			x[i]=1;
			sum+=p[i];
			i++;
		}
		if(i==n+1&&sum>sumx) {
			sumx=sum;
			for(j=1; j<=n; j++)
			{
				x1[j]=x[j];
			}
		} else {
			x[i]=0;
		}
		while(!bound(total,i))	//当此种情况可能时，不继续向前推
		{						//这一段只负责判断以及考虑不选取的情况，不进行选取这个动作
			if(i>n)
				i--;
			while(i>0&&x[i]!=1)
				i--;
			if(i==0) {
				l=1;
				return ;
			}
			x[i]=0;
			total-=w[i];
			sum-=p[i];
		}
		i++;
		if(l==1)
			return ;
	}
}

int bound(int a,int b)
{
	if(b>n)
		return 0;
	else if(a+r[b]-p[b]>=sumx)
		return 1;
	else 
		return 0;
}