//栈和队列

//栈stack  push  top pop  先今后出 
//队列queue  先进先出 

//两个栈实现队列   实现队列插入  和队头删除
// 一个栈stack1 先添加元素  ，然后弹出元素到stack2中   ，然后从stack2中弹出 实现先进先出
#include <stack>
#include <queue > 
#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
using namespace std;

void appendTail(int n){//队列尾增加 
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
void delectHead(){//队列头删除 
	;	
}

//两个队列实现栈 一个队列填充值queue1进去，然后弹出再添加到queue2中  然后从queue2 中打印  栈是后进先出

void MoStack(int n){
	int input;
	queue<int>queue1;
	queue<int>queue2;
	while(n>0&&cin>>input){
		queue1.push(input);
		--n;
	}//将两个队列加入 
	while(!queue1.empty()){//最后两个应该都为空 
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

