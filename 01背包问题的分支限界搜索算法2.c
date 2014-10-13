#include<stdio.h>

int f=0,e=1,beste=0,bestp=0,m,n,r[100],w[100],p[100];
void try(int j,int k);
int bound(int a,int b);
struct node
{
	int i,par,flag;
	float cw,cp;
}enode,node,q[100];

int main(void)
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=1; i<=n; i++)
	{
		scanf("%d%d",&w[i],&p[i]);
	}
	r[n]=p[n];
	for(i=n-1; i>=1; i--)
	{
		r[i]=r[i+1]+p[i];
	}
	try(n,m);
	return 0;
}

void try(int j,int k)
{
	int l;
	enode.cw=0;
	enode.cp=0;
	enode.i=0;
	enode.par=0;
	enode.flag=0;
	q[e]=enode;
	while(f!=e)
	{
		if(enode.i==j)
		{
			break ;
		}
		node.cw=enode.cw+w[enode.i+1];
		if(node.cw<=k) {
			node.cp=enode.cp+p[enode.i+1];
			if(node.cp>bestp) {
				bestp=node.cp;
				beste=e+1;
			}
			node.i=enode.i+1;
			node.par=f;
			node.flag=1;
			e++;
			q[e]=node;
		}
		if(bound(enode.cp,enode.i+1)) {
			node.cw=enode.cw;
			node.cp=enode.cp;
			node.flag=0;
			node.par=f;
			node.i=enode.i+1;
			e++;
			q[e]=node;
		}
		f++;
		enode=q[f];
	}
	for(l=1; l<=j; l++)
	{
		if(q[beste].flag==1)
			printf("%d  ",q[beste].i);
		beste=q[beste].par;		//没有输出不代表没有选择
	}
}

int bound(int a,int b)
{
	if(a+r[b]-p[b]>=bestp)
		return 1;
	else
		return 0;
}