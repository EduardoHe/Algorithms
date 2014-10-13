#include<stdio.h>

int opt[100][10],v1[10],h[10];

int Cal(int v, int t)
{
	int i,j,k,x;
	opt[0][t] = 0;
	for(i = 1; i< = v; i++)
	{
		opt[i][t] = -1;
	}
	for(j = t-1; j >= 0; j--)
	{
		for(i = 0; i <= v; i++)
		{
			opt[i][j] = -1;
			for(k = 0; k <= v/v1[i]; k++)	//这里舍弃了c[]，用v/v1[]代替
			{
				if(i < k * v1[j]) {
					break;
				}
				x = opt[i - k * v1[j]][j + 1];
				if(x != -1) {
					x += h[j] * k;
					if(x > opt[i][j]) {
						opt[i][j] = x;
					}
				}
			}
		}
	}
	return opt[v][0];
}
int main(void)
{
	int v, t,result;
	scanf("%d%d",&v,&t);
	result=Cal(v,t);
	printf("%d",result);
	return 0;
}