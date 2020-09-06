//二叉树遍历 
//前序  根左右；   中序 左根右；  后序  左右根 ； 层次遍历 
//构建一个树   然后进行遍历

//输入前序和中序   构建树 
struct BinTreeNode{
	int value；
	BinTreeNode* Left；
	BInTreeNode* Right； 
	 
};
//二叉树 递归构建
BinTreeNode *Construct(int *preorder,int* inorder,int length){
	if(preorder ==NULL||inorder==NULL||length<=0){
		return NULL;
	}
	return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
} 
BinTreeNode*ConstructCore(int* startPreorder,int*endPreorder,int* startInorder,int* endInorder){//根据前序和中序 
	//遍历前序 找到根节点
	int rootValue = startPreorder[0];
	BinTreeNode *root = new BinTreeNode();
	root->value = rootValue;
	root->Left = root->right = NULL;
	
	//查到中序遍历 找到根节点
	int *rootInorder = startInorder;
	while(rootInorder <=endInorder &&*rootInorder！= rootValue){
		++rootInorder;//直到找到 中序中和前序第一个相等的节点值 
	}
	int leftLength = rootInorder - startInorder;//左子树长度 
	int * leftPreorderEnd = startPreorder + leftLength;//左子树的结束 
	if(leftLength>0){
		//构建左子树
		root->Left = ConstructCore(startPreorder+1,leftPreorderEnd,startInorder,rootInorder-1); 
	} 
	if(leftLength<endPrrorder-startPreorder){
		//构建右子树
		root->Right = constructCore(leftPreorderEnd+1,endPreorder,rootInoreder+1,endInorder); 
	}
	return root;
}
