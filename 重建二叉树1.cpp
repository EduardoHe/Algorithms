#include<stdio.h>
#include<stdlib.h>

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void RebuildTree(int PreOrder[], int InOrder[], BinaryTreeNode** pHead, int originalLength)
{
	if(PreOrder == NULL || InOrder == NULL || originalLength < 0)
	{
		printf("Invalid Input!");
		return ;
	}
	
	int leftLength = 0, rightLength = 0;
	BinaryTreeNode* node = new BinaryTreeNode();
	node->m_nValue = *PreOrder;
	node->m_pLeft = NULL;
	node->m_pRight = NULL;
	
	if(*pHead == NULL) {
		*pHead = node;
	} else {
		printf("unknown step is here from%d\n",(*pHead)->m_nValue);
		return ;
	}
	while((*pHead)->m_nValue != InOrder[leftLength] && leftLength < originalLength) {
		leftLength++;
	}
	if(leftLength == originalLength) {
		printf("Array Error!");
		return ;
	} else if(leftLength > 0) {
		RebuildTree(PreOrder + 1, InOrder, &((*pHead)->m_pLeft), leftLength);
	}
	rightLength = originalLength - leftLength - 1;
	if(rightLength > 0) {
		RebuildTree(PreOrder + 1 + leftLength, InOrder + 1 + leftLength, &((*pHead)->m_pRight), rightLength);
	}
}

int main(void)
{
	int preorder[6]={1,2,4,3,5,6};
	int inorder[6]={4,2,1,5,3,6};
	BinaryTreeNode* pNode = NULL;	//这里没给指针初始化，会有错误
	
	RebuildTree(preorder, inorder, &pNode, 6);
	//printf("%d", pNode->m_nValue);	//在输入非法的情况下，是不能对返回的指针进行操作的，这里可以用一个全局变量作为标记
	return 0;
}
