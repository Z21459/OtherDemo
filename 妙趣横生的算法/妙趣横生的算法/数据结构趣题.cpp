#include"allHead.h"

/*
�������ݽṹ ��߱��ˮƽ �ͽ�����������
1.˳�������
2.��̬��������  ѡ��ʽ --���� 
3.ԭ��ռ� ���й鲢
4.Լɪ������  ����һ��ѭ������
5.������ ת�˽���
6.�жϻ��� ---������һ������ һ������
7.����ƥ������ 
*/

//˳�������
void onShunXuResever()
{
	int arr[5] = { 1,2,3,4,5 };
	int temp = 0;
	int len = (sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < len /2; i++)
	{
		temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;
	}
	for (int i = 0; i < len ; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
//��̬��������  ����
struct ListNode
{
	int data;
	ListNode *next;
};
void onSortList(ListNode *head);
void onCreateList()
{
	//��ͷ����
	ListNode *head = new ListNode;
	ListNode *p = head;
	head->next = NULL;
	//β����
	int i = 0;
	for (i = 1; i < 5; i++)
	{
		ListNode *newNode = new ListNode;
		if (newNode)
		{
			newNode->data = rand()%4 + 1;
			newNode->next = NULL;
		}
		head->next = newNode;
		head = newNode;
	}
	onSortList(p);
	//p = p->next;//��ָ���һ���ڵ�  β�����
	//while (p != NULL)
	//{
	//	cout << p->data << endl;
	//	p = p->next;
	//}

	////ͷ������

	//for (i = 1; i < 5; i++)
	//{
	//	ListNode *newNode = new ListNode;
	//	if (head->next == NULL)
	//	{
	//		if (newNode)
	//		{
	//			newNode->data = i;
	//			newNode->next = NULL;
	//		}
	//		head->next = newNode;
	//	}
	//	else
	//	{
	//		ListNode * p = head->next;//ָ���һ��
	//		if (newNode)
	//		{
	//			newNode->data = i;
	//		}
	//		newNode->next = p;
	//		head->next = newNode;
	//	}
	//}
	//p = p->next;//��ָ���һ���ڵ�  β�����
	//while (p != NULL)
	//{
	//	cout << p->data << endl;
	//	p = p->next;
	//}

	//�м���� //��ѭ���ҵ����ֵ����������ָ�룬��¼��ǰ�����ǰһ���ڵ� �ͺ�һ���ڵ�


}
//������������� �ı�ָ���ָ��
void onSortList(ListNode *head)
{
	ListNode *p, *q, *tail;
	tail = NULL;
	while ((head->next->next) != tail)
	{
		p = head;
		q = head->next;//��һ���ڵ�
		while (q->next != tail)//�ڶ����ڵ㲻ΪNULL
		{
			if ((q->data) > (q->next->data))//��һ���ڵ�͵ڶ����ڵ�Ƚ�  2431
			{
				p->next = q->next;
				q->next = q->next->next;
				p->next->next = q;
				q = p->next;
			}
			q = q->next;
			p = p->next;
		}
		tail = q;
	}
	p = head->next;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}
//�ϲ��������� --��Ҫ˼·�ǽ�һ�������ÿ��ֵ ���뵽��һ��������
ListNode *onInsertList(ListNode *head, ListNode *insert)
{
	//insert ֻ��һ���ڵ�  ���ڵ�����λ��  ͷ β �м�
	ListNode *p = head->next;
	ListNode *q = NULL;
	while (p->data < insert->data && p!=NULL)
	{
		q = p;//��¼����ǰһ���ڵ�
		p = p->next;
	}
	if (p == NULL)//ͷ����
	{
		head->next = insert;
		insert->next = NULL;
		return head;
	}
	//����p q�м�
	q->next = insert;
	insert->next = p;
	return head;

}
void onMergeTwoList(ListNode *lsh1, ListNode *lsh2)
{
	ListNode *l1 = lsh1;
	ListNode *l2 = lsh2;
	ListNode *head,*nextHead;
	int count1 = 0, count2 = 0;
	if (l1->next == NULL) return;//���ز�Ϊ�յ�����
	if (l2->next == NULL) return;
	while (l1->next!=NULL)
	{
		count1++;
		l1 = l1->next;
	}
	while (l2->next != NULL)
	{
		count2++;
		l2 = l2->next;
	}
	if (count1 > count2)
	{
		head = lsh1;
		nextHead = lsh2;
	}
	else
	{
		head = lsh2;
		nextHead = lsh1;
	}
	//�̵������Ľ��в���
	//ѭ������
	//ListNode *p = head->next;
	//ListNode *q = nextHead->next;//�ֱ�ָ���һ���ڵ�
	ListNode *nextP;
	while(nextHead != NULL)
	{
		nextP = nextHead->next;
		head = onInsertList(head, nextP);
		nextHead = nextP;
		//if (p->data > q->data)//��һ���ڵ�Ƚ�
		//{
		//	//p->next = q->next;
		//	//q->next = p;
		//	//q = p;
		//	//p = p->next;
		//}
		//else
		//{
		//	//q->next = p->next;
		//	//p->next = q;
		//	//p = q;
		//	//q = q->next;
		//}
	}

	//����head
}
//����ѭ������
void onCreateCricleList()
{
	ListNode *head = new ListNode;
	head->next = NULL;
	ListNode *newNode,*p = head;
	int i = 0; 
	for (i = 1; i < 5; i++)
	{
		newNode = new ListNode;
		newNode->data = i;
		head->next = newNode;
		head = newNode;
	}
	head->next = p->next;
	int m = 3;
	ListNode *q = NULL, *r = NULL;
	for (int i = 0; i < 20; i++)
	{
		if (!m--)
		{
			q = p;
			cout << p->data;
			r->next = p->next;
			p = r->next;
			delete q;
			m = 3;
		}
		//cout << p->next->data;
		else
		{
			r = p;//��סҪɾ����ǰһ��
			p = p->next;
			if (p == r)
			{
				cout << " ���ʣ�ࣺ " << p->data;
				break;
			}
		}
		
	}
}
//������ת�˽���  �������ջ�ļ���
void onTwoToEight()
{
	string str = "1010";//10 ���ɰ˽��� 12  ��ת10���� ��ת8����
	int len = str.length();//�ַ�������
	int i = 0, sum = 0;
	for (i = 0; i < len; i++)//2->10
	{
		sum = sum + (int)pow(2, i) * (str[len - i - 1]-'0');//�ַ�ת���� -��0��
	}
	cout << str << " -> "<< sum << endl;
	//10->8
	stack<char> st;
	while (sum)
	{
		st.push((sum % 8) + '0');
		sum /= 8;
	}
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
}
//����ƥ������--ջ���ݽṹ ���ڲ㿪ʼ
bool onIsMatch(char l, char r)
{
	if (l == '(' && r == ')') return true;
	if (l == '['&&r == ']')return true;
	return false;
}
void onKuoHao()
{
	string str = "[((])])";//"[[()][]()]"
	stack<char> st;
	int len = str.length();
	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (str[i] != '(' || str[i] == ')' ||
			str[i] != '['&&str[i] != ']')
		{
			cout << "Error \n";
			return;
		}
		if (st.empty())
		{
			st.push(str[i]);
		}
		else
		{
			char temp = st.top();
			st.pop();
			if (!onIsMatch(temp, str[i]))
			{
				st.push(temp);
				st.push(str[i]);
			}
		}
	}
	if (st.empty()) cout << "ƥ��\n";
	else cout << "��ƥ��\n";
}



int main()
{

	//onShunXuResever();
	//onCreateList();
	//onCreateCricleList();

	//onTwoToEight();
	onKuoHao();



	system("pause");
	return 0;
}