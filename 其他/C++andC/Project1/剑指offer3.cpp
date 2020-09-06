#include <iostream>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
	int data;
	ListNode *next;
};

//删除链表节点   要删除当前节点，将下一个节点的值赋值给当前节点，删除下一个节点
void DeleteListNode(ListNode**pListhead, ListNode*pToDelete) {
	if (!pListhead || !pToDelete)
		return;
	//删除节点不是尾部节点
	if (pToDelete->next != nullptr) {
		ListNode*pNext = pToDelete->next;
		pToDelete->data = pNext->data;
		pToDelete->next = pNext->next;
		delete pNext;
		pNext = nullptr;
	}
	//链表中只有一个
	else if (*pListhead == pToDelete) {
		delete pToDelete;
		pToDelete = nullptr;
		*pListhead = nullptr;
	}
	else {
		//多个节点
		ListNode *pnode = *pListhead;
		while (pnode->next != pToDelete) {
			pnode = pnode->next;
		}
		pnode->next = nullptr;
		delete pToDelete;
		pToDelete = nullptr;
	}
}

//数组前半部分是奇数  后半部分是偶数    使用两个指针p1指向头，p2指向尾，两个指针相对移动，p1遇到偶数，p2遇到奇数，两者交换，直到p1==p2为止
void ReorderOddEven(int *pData, unsigned int len) {
	if (pData == nullptr || len == 0) {
		return;
	}
	int *pBeg = pData;
	int *pEnd = pData + len - 1;
	while (pBeg < pEnd) {
		//通过两个循环之后 ，进行交换，然后继续判断两个指针的大小，继续执行，直到两个相同时结束循环 
		//向后移动pBeg，遇到偶数
		while (pBeg < pEnd &&(*pBeg & 0x1)!= 0){//偶数
			pBeg++;
		}
		//前移动pend 直到指向奇数
		while (pBeg < pEnd && (*pEnd & 0x1) == 0) {//奇数
			pEnd--;
		}
		if (pBeg < pEnd) {
			int tmp = *pBeg;
			*pBeg = *pEnd;
			*pEnd = tmp;
		}
	}
}

//链表中倒数第k个值   定义两个指针 ，p1走k-1步，p2从头开始，两个一起走。当p1到达尾部的时候，刚好p2是在倒数第k的位置
ListNode* FindKtoTail(ListNode* pListNode, unsigned int k) {//////////代码的鲁棒性
	if (pListNode == nullptr||k==0)
		return nullptr;
	ListNode*p1 = pListNode;
	ListNode*p2 = pListNode;
	
	for (unsigned int i = 0; i < k - 1;i++){
		if (p1->next != nullptr) {
			p1 = p1->next;
		}
		else {
			return nullptr;
		}
	}
	while (p1->next != nullptr) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2;
}

//给一个头结点，反转链表并输出翻转后链表头结点
ListNode*RevListNode(ListNode*pHead) {
	ListNode*re = nullptr;
	ListNode*pNode = pHead;
	ListNode*pPre = nullptr;
	while (pNode != nullptr) {
		ListNode *pNext = pNode->next;
		if (pNext == nullptr)
			re = pNode;
		pNode->next = pPre;
		pPre = pNode;
		pNode = pNext;
	}
	return re;
}

//合并两个递增的有序链表
ListNode*Merge(ListNode*pHead1, ListNode*pHead2) {
	if (pHead1 == nullptr)
		return pHead2;
	if (pHead2 == nullptr)
		return pHead1;
	ListNode*pMergeHead = nullptr;
	if (pHead1->data < pHead2->data) {
		pMergeHead = pHead1;
		pMergeHead->next = Merge(pHead1->next, pHead2);
	}
	if (pHead2->data < pHead1->data) {
		pMergeHead = pHead2;
		pMergeHead->next = Merge(pHead1, pHead2->next);
	}
}




int main3o() {



	system("pause");
	return 0;
}