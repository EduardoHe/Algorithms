#include<stdio.h>

int w[100],p[100],m,n,f[100][100];
void dp();

int main(void)
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=1; i<=n; i++)
	{
		scanf("%d%d",&w[i],&p[i]);
	}
	dp();
	return 0;
}

void dp()
{
	int i,j;
	for(j=0; j<=m; j++)
	{
		f[n][j]=0;
	}
	for(j=w[n]; j<=m; j++)
	{
		f[n][j]=p[n];
	}
	for(i=n-1; i>1; i--)
	{
		for(j=0; j<=m; j++)
		{	
			f[i][j]=f[i+1][j];
		}
		for(j=w[i]; j<=m; j++)
		{
			if(f[i+1][j]>f[i+1][j-w[i]]+p[i])
				f[i][j]=f[i+1][j];
			else
				f[i][j]=f[i+1][j-w[i]]+p[i];
		}
	}
	if(f[2][m]>f[2][m-w[i]]+p[i])
		f[1][m]=f[2][m];
	else	
		f[1][m]=f[2][m-w[1]]+p[1];
	printf("%d",f[1][m]);
}