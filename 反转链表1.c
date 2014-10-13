#include<stdio.h>

struct ListNode
{
    int m_nKey;
	struct ListNode *m_pNext;
};
typedef struct ListNode node;

node* ReversedNode = NULL;

node* ReverseList(node* pHead)
{
    node* pNode = pHead;
    if(pNode != NULL) {
        node* pPrev = pNode->m_pNext;
        if(pPrev != NULL) {
            pPrev = ReverseList(pPrev);
            pPrev->m_pNext = pNode;
        } else {
            ReversedNode = pNode;
        }
    }
    return pNode;	
}

int main(void)
{
    node** pHead = NULL;
	//CreateNode(pHead);
    node* pEnd = ReverseList(*pHead);
	if(pEnd != NULL) {
        pEnd->m_pNext = NULL;
	}
	//TestPrintNode(ReversedNode);
    return 0;
}