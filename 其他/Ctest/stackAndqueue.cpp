//ջ�Ͷ���

//ջstack  push  top pop  �Ƚ��� 
//����queue  �Ƚ��ȳ� 

//����ջʵ�ֶ���   ʵ�ֶ��в���  �Ͷ�ͷɾ��
// һ��ջstack1 �����Ԫ��  ��Ȼ�󵯳�Ԫ�ص�stack2��   ��Ȼ���stack2�е��� ʵ���Ƚ��ȳ�
#include <stack>
#include <queue > 
#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
using namespace std;

void appendTail(int n){//����β���� 
	stack<int>stack1;
	stack<int>stack2;
	int input;
	while(n>0&&cin>>input){
		stack1.push(input);
		--n;
	}
	while(!stack1.empty()){
		int temp = stack1.top();
		stack2.push(temp);
		stack1.pop();
	}
	while(!stack2.empty()){
		int result = stack2.top();
		printf("%d",result);
		stack2.pop();
	}
} 
void delectHead(){//����ͷɾ�� 
	;	
}

//��������ʵ��ջ һ���������ֵqueue1��ȥ��Ȼ�󵯳�����ӵ�queue2��  Ȼ���queue2 �д�ӡ  ջ�Ǻ���ȳ�

void MoStack(int n){
	int input;
	queue<int>queue1;
	queue<int>queue2;
	while(n>0&&cin>>input){
		queue1.push(input);
		--n;
	}//���������м��� 
	while(!queue1.empty()){//�������Ӧ�ö�Ϊ�� 
		for(int i = queue1.size();i>1;--i){
			queue2.push(queue1.front());
			queue1.pop();
		} 
		//printf("2222");
		printf("%d",queue1.back());
		queue1.pop();
		if(!queue2.empty()){
			for(int i = queue2.size();i>0;--i){
				queue1.push(queue2.front());
				queue2.pop();
			} 
		}
		else if(queue1.empty()&&queue2.empty()){
			break;
		}
	}
} 

 
int main(){
	//appendTail(3);
	MoStack(3);
	system("pause");
	return 0;
}

