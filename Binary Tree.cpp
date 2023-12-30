#include<iostream>
#include<queue>
using namespace std;
class node{
	public:
		int data;
		node* left;
		node* right;
		node(int d){
			this->data=d;
			this->left=NULL;
			this->right=NULL;
		}
};

node* buildTree(node* root){
	cout<<endl<<"Enter the Data:";
	int d;
	cin>>d;
	root=new node(d);
	
	if (d==-1){
		return NULL;
	}
	
	cout<<"Enter data for inserting in left of "<<d;
	root->left=buildTree(root->left);
	cout<<"Enter data for inserting in right of "<<d;
	root->right=buildTree(root->right);
	return root;
}

void levelOrderTraversal(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		node* temp=q.front();
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
		}}
	}
}

void inorder(node* root){
	//base case
	if(root==NULL){
		return;
	}
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(node* root){
	//base case
	if(root==NULL){
		return;
	}
	
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void buildfromlevelOrder(node* &root){
	queue<node*> q;
	int data;
	cin>>data;
	root=new node(data);
	q.push(root);
	
	while(!q.empty()){
		node* temp=q.front();
		q.pop();
		
		cout<<"Enter left node for:"<<temp->data<<endl;
		int leftData;
		cin>>leftData;
		
		if(leftData!=-1){
			temp->left=new node(leftData);
			q.push(temp->left);
		}
		
		cout<<"Enter right node for:"<<temp->data<<endl;
		int rightData;
		cin>>rightData;
		
		if(rightData!=-1){
			temp->right=new node(rightData);
			q.push(temp->right);
		}
	}
}

void postorder(node* root){
	//base case
	if(root==NULL){
		return;
	}
	
	preorder(root->left);
	preorder(root->right);
	cout<<root->data<<" ";
}

int height(node* node){
	if(node==NULL){
		return 0;
	}
	int left=height(node->left);
	int right=height(node->right);
	int ans=max(left,right)+1;
	return ans;
}

int main(){
	node* root=NULL;
	root=buildTree(root);
	//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
	levelOrderTraversal(root);
	cout<<"Inorder traversal:";
	inorder(root);
	cout<<"\npreorder traversal:";
	preorder(root);
	cout<<"\npostorder traversal:";
	postorder(root);
	return 0;
}

