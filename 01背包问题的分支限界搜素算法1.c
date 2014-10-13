#include<stdio.h>

struct node
{
	int i,par,flag;
	float cw,cp;
}enode,node,q[100];
int f=0,beste=0,bestp=0,m,n,r[100],w[100],p[100];
void try(int j,int k);
int bound(int a,int b);
void addnode(struct node e);
struct node deletenode();
void heapAdjust(struct node* d,int j,int k);
void swap(int j,int k);

int main(void)
{
	int j;
	scanf("%d%d",&n,&m);
	for(j=1; j<=n; j++)
	{
		scanf("%d%d",&w[j],&p[j]);
	}
	r[n]=0;
	for(j=n-1; j>=1; j--)
	{
		r[j]=r[j+1]+p[j+1];
	}
	try(n,m);
	return 0;
}

void try(int j,int k)
{
	enode.cw=0;
	enode.cp=0;
	enode.i=0;
	enode.par=0;
	enode.flag=0;
	addnode(enode);
	while(enode.i!=j)
	{
		node.cw=enode.cw+w[enode.i+1];
		if(node.cw<=k) {
			node.cp=enode.cp+p[enode.i+1];
			if(node.cp>bestp) {
				bestp=node.cp;
			}
			node.i=enode.i+1;
			node.par=f;
			node.flag=1;
			addnode(node);
		}
		if(bound(enode.cp,enode.i+1)) {
			node.cw=enode.cw;
			node.cp=enode.cp;
			node.flag=0;
			node.par=f;
			node.i=enode.i+1;
			addnode(node);
		}
		enode=deletenode();
	}
	printf("%d",bestp);
	//如果在每个数据中添加和变量f不同的变量lf以表示每个数据是第几个出现以及父节
	//点是谁，应该可以得到最大利润的选取方案
}

int bound(int a,int b)
{
	if(a+r[b]>=bestp)
		return 1;
	else
		return 0;
}

void addnode(struct node e)
{
	int j;
	f++;
	e.cp+=r[e.i];
	q[f]=e;
	for(j=f/2; j>=1; j--)
		heapAdjust(q,j,f);
}

struct node deletenode()
{
	swap(1,f);
	f--;
	heapAdjust(q,1,f);
	q[f+1].cp-=r[q[f+1].i];
	return q[f+1];
}

void heapAdjust(struct node* d,int j,int k)
{
	int i;
	for(i=2*j; i<=k; i=2*i)
	{
		if(i+1<=k) {
			if(d[i].cp<d[i+1].cp) {
				i++;
			}
		}
		if(d[j].cp<d[i].cp) {
			swap(j,i);
			j=i;
		}
		else {
			break;
		}
	}
}

void swap(int j,int k)
{
	struct node temp;
	temp.cw=q[j].cw;
	temp.cp=q[j].cp;
	temp.flag=q[j].flag;
	temp.par=q[j].par;
	temp.i=q[j].i;
	q[j].cw=q[k].cw;
	q[j].cp=q[k].cp;
	q[j].flag=q[k].flag;
	q[j].par=q[k].par;
	q[j].i=q[k].i;
	q[k].cw=temp.cw;
	q[k].cp=temp.cp;
	q[k].flag=temp.flag;
	q[k].par=temp.par;
	q[k].i=temp.i;
}