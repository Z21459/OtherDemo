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

//ɾ������ڵ�   Ҫɾ����ǰ�ڵ㣬����һ���ڵ��ֵ��ֵ����ǰ�ڵ㣬ɾ����һ���ڵ�
void DeleteListNode(ListNode**pListhead, ListNode*pToDelete) {
	if (!pListhead || !pToDelete)
		return;
	//ɾ���ڵ㲻��β���ڵ�
	if (pToDelete->next != nullptr) {
		ListNode*pNext = pToDelete->next;
		pToDelete->data = pNext->data;
		pToDelete->next = pNext->next;
		delete pNext;
		pNext = nullptr;
	}
	//������ֻ��һ��
	else if (*pListhead == pToDelete) {
		delete pToDelete;
		pToDelete = nullptr;
		*pListhead = nullptr;
	}
	else {
		//����ڵ�
		ListNode *pnode = *pListhead;
		while (pnode->next != pToDelete) {
			pnode = pnode->next;
		}
		pnode->next = nullptr;
		delete pToDelete;
		pToDelete = nullptr;
	}
}

//����ǰ�벿��������  ��벿����ż��    ʹ������ָ��p1ָ��ͷ��p2ָ��β������ָ������ƶ���p1����ż����p2�������������߽�����ֱ��p1==p2Ϊֹ
void ReorderOddEven(int *pData, unsigned int len) {
	if (pData == nullptr || len == 0) {
		return;
	}
	int *pBeg = pData;
	int *pEnd = pData + len - 1;
	while (pBeg < pEnd) {
		//ͨ������ѭ��֮�� �����н�����Ȼ������ж�����ָ��Ĵ�С������ִ�У�ֱ��������ͬʱ����ѭ�� 
		//����ƶ�pBeg������ż��
		while (pBeg < pEnd &&(*pBeg & 0x1)!= 0){//ż��
			pBeg++;
		}
		//ǰ�ƶ�pend ֱ��ָ������
		while (pBeg < pEnd && (*pEnd & 0x1) == 0) {//����
			pEnd--;
		}
		if (pBeg < pEnd) {
			int tmp = *pBeg;
			*pBeg = *pEnd;
			*pEnd = tmp;
		}
	}
}

//�����е�����k��ֵ   ��������ָ�� ��p1��k-1����p2��ͷ��ʼ������һ���ߡ���p1����β����ʱ�򣬸պ�p2���ڵ�����k��λ��
ListNode* FindKtoTail(ListNode* pListNode, unsigned int k) {//////////�����³����
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

//��һ��ͷ��㣬��ת���������ת������ͷ���
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

//�ϲ�������������������
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