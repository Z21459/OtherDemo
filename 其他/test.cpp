#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <stack>
#include <queue>
#include <string> 
#include <vector>

using namespace std;
#define N 21;

 
//������ż���зָ� 
typedef struct Point
{
    int data;
    struct Point *next;
}Node,*pNode;

int main()
{


    void create(pNode);
    void separate(pNode,pNode);
    void print(pNode);
    void connectNode(pNode,pNode);
    pNode A=NULL,B=NULL;
    A=(pNode)malloc(sizeof(Node));
    B=(pNode)malloc(sizeof(Node));
    printf("Enter numbers(input 0 to end):\n");
    create(A);
    separate(A,B);
    print(A);
    print(B);
    connectNode(A,B);

/*    
    queue<char>r1,r2,r3;
    string s;
    cin >> s;
    for(int i =0;i<s.length();i++){
    	//cout << "11";
    	if(s[i] == '*'){
    		r1.push(s[i]);
		}
		else if(s[i]>'a'&&s[i]<'z')
		{
			r2.push(s[i]);
		}
		else if(s[i]>='0'&&s[i]<='9'){
			r3.push(s[i]);
		}
	}
	while(!r2.empty()){
		//cout << r2.front();
		char p = r2.front();
		r1.push(p);
		r2.pop();
	}
	while(!r3.empty()){
		r1.push(r3.front());
		//cout << r3.front();
		r3.pop();
	}
	cout<<r1.size()<<endl;
	int k = r1.size(); 
	for(int i =0;i<k;i++){
		cout << r1.front();
		r1.pop();
	}
	*/

    return 0;
}
//�������ӷֿ��Ľڵ� 
void connectNode(pNode A,pNode B){
	cout << "**";
	/*queue<pNode> ret; //����ʹ��ջ �����Ƿ��� 
	pNode p,q;
	//���̵Ĳ��뵽��������
	p = A->next;////A 135 B 2 4 6 
	q = B->next;
	while(p!=NULL||q!=NULL){//���ڵ���뵽ջ�� 
			ret.push(p);
			ret.push(q);
			p = p->next;
			q = q->next;
	}
	while(!ret.empty()){
		cout << "//";
	//pNode z =	ret.pop();
		pNode z = ret.front();//����  back��β 
		cout << z->data;
		ret.pop();
	}*/
	//A 1 2     B 3 4 5
	pNode p,q;
	//p = A->next;
	//q = B->next;
	p = A;
	q = B;
	pNode t,c=p;//cָ�򱻲����λ��
	while(q!=NULL){
	  t=c->next;//���ݴ�p����ĵ�
	  c->next=q;//����q��ǰ�ڵ�
	  q=q->next;//q��ͷָ����һ��
	  c->next->next=t;//��ԭ����p�������λ�ú�Ĳ��ֽ���
	  c=t;//ָ��p�´�ѭ�������λ��
	  //
	}
	
	/*cout << "//";

	while(1){
		cout << "//";
	//pNode z =	ret.pop();
		cout << p->data;
		p=p->next;
		cout << "//";
	} */
} 
 
void create(pNode head)
{
    int n=0;
    pNode p,q;
    p=q=(pNode)malloc(sizeof(Node));
    scanf("%d",&p->data);
    while(p->data!=0)
    {
        ++n;
        if(n==1)
            head->next=p;
        else
            q->next=p;
        q=p;
        p=(pNode)malloc(sizeof(Node));
        scanf("%d",&p->data);
    }
    q->next=NULL;
}
 
void separate(pNode A,pNode B)
{
    pNode pa1,pa2,pb;
    pa1=A->next;
    pa2=A;
    pb=B;
    //�����������зָ�   //std::cout << len/2; //������ �����3   �����1 ��պú���Ϊ��һ������ 
    pNode s;
	s = A; 
	int len =-1;
    while(s!=NULL){
		s = s->next;
		len++;
	}
	
	int t = len/2;
	int m = len-t;
	while(pa1!=NULL){
		while(t!=0&&pa1->next!=NULL){
            pa2->next=pa1;//ǰ���ַ��� pa2 
            pa2 = pa2->next;
            pa1=pa1->next;
			t--;
			//cout << t;
		}//ǰ��len/2��һ������
		//����������һ������
		pa2->next = NULL;
		while(m!=0){
			pb->next=pa1;
            pb=pb->next;
			/*pb->data= pa1->data;
			cout << "///"<< pb->data;
			pb = pb->next;*/
			pa1=pa1->next;
			m--;
		}
	}
/*	 //����������ż���зָ� 
    while(pa1!=NULL)
    {
        while(pa1->data%2!=0&&pa1->next!=NULL)//��A��ǰ������������Һ��滹�н��ʱִ��//
        {
            pa2=pa1;
            pa1=pa1->next;
        }
        if(pa1->data%2==0)//�ҵ�ż����//
        {
            pa2->next=pa1->next;
            pb->next=pa1;
            pb=pb->next;
            pa1=pa2->next;
        }
        else//��A���һ�����������ʱ//
            pa1=pa1->next;
    }*/
    pb->next=NULL;
}
 
void print(pNode head)
{
    pNode p=head->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    putchar(10);
}
