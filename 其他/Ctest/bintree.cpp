//���������� 
//ǰ��  �����ң�   ���� ����ң�  ����  ���Ҹ� �� ��α��� 
//����һ����   Ȼ����б���

//����ǰ�������   ������ 
struct BinTreeNode{
	int value��
	BinTreeNode* Left��
	BInTreeNode* Right�� 
	 
};
//������ �ݹ鹹��
BinTreeNode *Construct(int *preorder,int* inorder,int length){
	if(preorder ==NULL||inorder==NULL||length<=0){
		return NULL;
	}
	return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
} 
BinTreeNode*ConstructCore(int* startPreorder,int*endPreorder,int* startInorder,int* endInorder){//����ǰ������� 
	//����ǰ�� �ҵ����ڵ�
	int rootValue = startPreorder[0];
	BinTreeNode *root = new BinTreeNode();
	root->value = rootValue;
	root->Left = root->right = NULL;
	
	//�鵽������� �ҵ����ڵ�
	int *rootInorder = startInorder;
	while(rootInorder <=endInorder &&*rootInorder��= rootValue){
		++rootInorder;//ֱ���ҵ� �����к�ǰ���һ����ȵĽڵ�ֵ 
	}
	int leftLength = rootInorder - startInorder;//���������� 
	int * leftPreorderEnd = startPreorder + leftLength;//�������Ľ��� 
	if(leftLength>0){
		//����������
		root->Left = ConstructCore(startPreorder+1,leftPreorderEnd,startInorder,rootInorder-1); 
	} 
	if(leftLength<endPrrorder-startPreorder){
		//����������
		root->Right = constructCore(leftPreorderEnd+1,endPreorder,rootInoreder+1,endInorder); 
	}
	return root;
}
