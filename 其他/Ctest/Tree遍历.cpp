///二叉树  遍历 递归和非递归

///递归
//前
void  PreOrder(){
	if(root ==NULL){
		return;
	}
	PreOrder(root);
}
void PreOrder(Node* current){
	if(current!=NULL){
		cout << current->data;
		PreOrder(current->left);
		PreOrder(current->right);
	}
} 
void PreOrder(){
	stack<Node*>s;
	Node* p  =root;
	while(p!=NULL&&!s.empty()){
		while(p!=NULL){
			cout << p->data;
			s.push(p);
			p = p->left;
		}
		
		if(!s.empty()){
			p = s.top();
			s.pop();
			p = p->right;
		} 
	}
}




//中  递归 
void InOrder(){
	if(root!=NUUL){
		return;
	}
	InOrder(root);
	
} 

void Inorder(Node* current){
	if(current!=NULL){
		Inorder(current->left);
		cout << current->data;
		InOrder(current->right);
	}
}

//非递归
void Inorder(){
	stack<NOde*>s;
	Node*p = root;
	while(p!=NULL&&!s.empty()){
		while(p!=NULL){
			s.push(p);
			p = p->left;
		}
		if(!s.empty()){
			p = s.top();
			s.pop();
			cout << p->data;
			p=p->right;
		}	
	}
} 

//后
void HandOrder(){
	if(root==NULL){
		return;
	}
	HnadOrder(root);
	
} 
void HandOrder(Node* current){
	if(current!=NULL){
		HandOrder(current->left);
		HandOrder(current->right);
		cout << current->data;
	}
}

void HandOredr(){
	stack<Node*>s;
	Node*p = root;
	while(p!=NULL||!s.empty()){
		while(p!=nullptr){
			s.push(P);
			p = p->left;
		}
		
		if(!s.empty()){
			p = s.top();//栈顶
			if(p->tag)//为1时
			{
				cout<<p->data;
				s.pop();
				p = NULL; 
			} 
			else{
				p->tag = 1;
				p = p->right;
			}
		}
	}
} 


// 非递归 遍历 
