#include"stdio.h"
#include"stdlib.h"
#define MaxValue 255

struct NodeArray
{
	int ra[10],qz,t;
}node,enode,q[100];
int f=0,step=0,search=0,MaxStep=0;

void HeapAdjust(int j,int k);
void AddNode();
void DeleteNode();
void Swap(int j,int k);
void try1();
int upper();
void reverse(int i);
int IsSorted();

int main(void)
{
	int j;
	int CakeArray[10]={3,2,1,6,5,4,9,8,7,0};
	for(j=0; j<10; j++)
	{
		node.ra[j]=CakeArray[j];;
	}
	node.qz=MaxValue;
	node.t=0;
	AddNode();
	for(j=0; j<10; j++)
	{
		node.ra[j]=CakeArray[j];
	}
	node.qz=step+upper();
	node.t=step;
	AddNode();
	try1();
	printf("%d%d",MaxStep,search);
	return 0;
}

void try1()
{
	int i,j,temp;
	search++;
	DeleteNode();
	enode = q[f+1];
	step=enode.t+1;
	while(IsSorted()==0) 
	{
		for(i=1; i<=9; i++)
		{
			search++;
			for(j=0; j<10; j++)
			{
				temp=enode.ra[j];	//ruguomeiyou temp,jiushi yinyong,bushi chuanzhi
				node.ra[j]=temp;
			}
			reverse(i);
			node.qz=step+upper();
			node.t=step;
			if(node.qz<18) {
				AddNode();
			}
		}
		DeleteNode();
		enode = q[f+1];
		step=enode.t+1;
	}
	MaxStep=step-1;
}

void HeapAdjust(int j,int k)
{ 
	int i;
	if(k==0) {
		return ;
	}
	if((2*j)>k) {
		return ;
	}
	for(i=2*j; i<=k; i=2*i)
	{
		if(i+1<=k) {
			if(q[i].qz>q[i+1].qz) {
				i++;
			}
		}
		if(q[j].qz>q[i].qz) {
			Swap(j,i);
		} else {
			break;
		}
	}
}

void AddNode()
{
	int j,i;
	f++;
	q[f]=node;	
	j=f/2;
	if(j!=0) {
		for(i=j; i>=1; i--)
		{
			HeapAdjust(i,f);
		}
	}
}

void DeleteNode()
{
	Swap(1,f);
	f--;
	HeapAdjust(1,f);
}

void Swap(int j,int k)
{
	int i;
	int temp;
	for(i=0; i<10; i++)
	{
		temp=q[j].ra[i];
		q[j].ra[i]=q[k].ra[i];
		q[k].ra[i]=temp;
	}
	temp=q[j].qz;
	q[j].qz=q[k].qz;
	q[k].qz=temp;
	temp=q[j].t;
	q[j].t=q[k].t;
	q[k].t=temp;
}

int upper()
{
	int i,j,k=0;	//fuchuzhi
	for(i=0; i<9; i++)
	{
		j=node.ra[i]-node.ra[i+1];
		if(j>=-1&&j<=1) {
			continue;
		} else {
			k++;
		}
	}
	if(node.ra[9]!=9) {
		k++;
	}
	return k;
}

void reverse(int i)
{
	int j,k,temp;
	k=i/2;
	for(j=0; j<=k; j++)
	{
		temp=node.ra[j];
		node.ra[j]=node.ra[i-j];
		node.ra[i-j]=temp;
	}
}

int IsSorted()
{
	int i;
	for(i=1; i<10; i++)
	{
		if(enode.ra[i-1]>enode.ra[i]) {
			return 0;
		}
	}
	return 1;
}