///������  ���� �ݹ�ͷǵݹ�

///�ݹ�
//ǰ
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




//��  �ݹ� 
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

//�ǵݹ�
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

//��
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
			p = s.top();//ջ��
			if(p->tag)//Ϊ1ʱ
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


// �ǵݹ� ���� 
