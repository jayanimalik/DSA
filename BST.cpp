#include<iostream>
#include<queue>
using namespace std;
class Node{
	public:
	int data;
	Node* left;
	Node* right;
	Node(int d){
		this->data=d;
		this->left=NULL;
		this->right=NULL;
}};

void inorder(Node* root){
	//base case
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(Node* root){
	//base case
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(Node* root){
	//base case
	if(root==NULL){
		return;
	}
	preorder(root->left);
	preorder(root->right);
	cout<<root->data<<" ";
}
Node* insertIntoBST(Node* &root,int d){
	if (root==NULL){
		root=new Node(d);
		return root;
	}
	if(d>root->data){
		root->right=insertIntoBST(root->right,d);
	} 
	
	else{ 
		root->left=insertIntoBST(root->left,d);
	}
	return root;
}

void takeInput(Node* &root){
	int data;
	cin>>data;
	while(data!=-1){
		root=insertIntoBST(root,data);
		cin>>data;
}}

void levelOrderTraversal(Node* root){
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		Node* temp=q.front();
		q.pop();
		
		if (temp==NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
		cout<<temp->data<<" ";
		if(temp->left){
			q.push(temp->left);
		}
		
		if (temp->right){
			q.push(temp->right);
}}}}

bool searchBST(Node* root, int x){
	if (root==NULL)
	return false;
	if(root->data==x)
	return true;
	
	if(root->data> x)
	searchBST(root->left, x);
	else
	searchBST(root->right, x);
}

Node* minVal(Node * root){
	Node * temp=root;
	while(temp->left!=NULL){
		temp=temp->left;
	}
	return temp;
}

Node* maxVal(Node * root){
	Node * temp=root;
	while(temp->right!=NULL){
		temp=temp->right;
	}
	return temp;
}


Node* deleteFromBST(Node* root,int val){
	if(root==NULL){
		return root;
	}
	if(root->data==val){
		//0 child
		if(root->right==NULL&& root->left==NULL){
			delete root;
			return NULL;
		}
		//1 child
		//left
		if(root->left!=NULL && root->right==NULL){
			Node * temp=root->left;
			delete root;
			return temp;
		}
		//right
		if(root->right!=NULL && root->left==NULL){
			Node * temp=root->right;
			delete root;
			return temp;
		}
		//2 child
		if(root->right!=NULL && root->left!=NULL){
			int mini=minVal(root->right)->data;
			root->data=mini;
			root->right=deleteFromBST(root->right,mini);
			return root;
		}
		
	}
	else if(root->data > val){
		root->left=deleteFromBST(root->left,val);
		return root;
	}
	else{
		root->right=deleteFromBST(root->right,val);
		return root;
	}
}

bool isBST(Node * root, int min, int max){
	if(root== NULL){
		return true;
	}
	if(root->data >min && root->data<max){
		bool left=isBST(root->left,min,root->data);
		bool right=isBST(root->right,root->data,max);
		return left && right;
	}
	else{
		return false;
	}
}

int solve(Node* root, int& i, int k){//kth smallest element
	if(root==NULL){
		return -1;
	}
	//L
	int left=solve(root->left,i,k);
	if(left!=-1){
		return left;
	}
	//N
	i++;
	if(i==k){
		return root->data;
	}
	//R
	return solve(root->right,i,k);
}

void predsucc(Node* root, int key){
	Node* temp=root;
	int pred=-1;
	int succ=-1;
	while(temp->data!=key){
		if(temp->data>key){
			succ=temp->data;
			temp=temp->left;			
		}
		else{
			pred=temp->data;
			temp=temp->right;
		}
	}
	Node* leftTree=temp->left;
	while(leftTree!=NULL){
		pred=leftTree->data;
		leftTree=leftTree->right;
	}
	Node* rightTree=temp->right;
	while(rightTree!=NULL){
		succ=rightTree->data;
		rightTree=rightTree->left;
	}
	cout<<"\nPredecessor: "<<pred<<endl;
	cout<<"Sucessor: "<<succ<<endl;
}

void MorrisTraversal(Node* root){
    Node *current, *pre;
    if (root == NULL)
        return;
    current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            cout << current->data << " ";
            current = current->right;
        }
        else {
            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL
                   && pre->right != current)
                pre = pre->right;
 
            /* Make current as the right child of its
               inorder predecessor */
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }
 
            /* Revert the changes made in the 'if' part to
               restore the original tree i.e., fix the right
               child of predecessor */
            else {
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            } /* End of if condition pre->right == NULL */
        } /* End of if condition current->left == NULL*/
}}

//is binary tree heap
int countNodes(Node* root){
	if (root==NULL)
	return 0;
	 int ans=1+countNodes(root->left)+countNodes(root->right);
	 return ans;
}
bool isCBT(Node* root,int index,int cnt){
	if(root==NULL)
	return true;
	if(index>=cnt)
	return false;
	else{
		bool left=isCBT(root->left,2*index+1,cnt);
		bool right=isCBT(root->right,2*index+2,cnt);
		return(left&& right);
	}
}
bool isMaxOrder(Node *root){
	if(root->left==NULL && root->right==NULL)
	return true;
	if(root->right==NULL){
		return(root->data>root->left->data);		
	}
	else{
		bool left= isMaxOrder(root->left);
		bool right= isMaxOrder(root->right);
		return(left && right && (root->data>root->right->data)
		&&(root->data>root->left->data));
	}
}
bool isheap(Node* root){
	int index=0;
	int totalCount=countNodes(root);
	if(isCBT(root,index,totalCount) && isMaxOrder(root)){
		return true;
	}
	else
	return false;
}

int main(){
	Node* root=NULL;
	cout<<"Enter data to create BST:";
	takeInput(root); //15 18 6 7 17 3 4 13 9 20 2 -1
	cout<<"printing tree(level order traversal): \n";
	levelOrderTraversal(root);
	cout<<"Inorder traversal:";	
	inorder(root);
	predsucc(root, 6);
	
	MorrisTraversal(root);
	return 0;
}

