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
		left=NULL;
		right=NULL;
	}
};
Node* DeleteFromBST(Node* root,int val){
	if (root==NULL){
		return NULL;
	}
	if(root->data==val){
		//0 child
		if(root->right==NULL&& root->left==NULL){
			delete root;
			return NULL;
		}
		//1 child
		//left
		if(root->right==NULL&& root->left!=NULL){
			Node* temp=root->left;
			delete root;
			return temp;
		}
		//right
		if(root->right!=NULL&& root->left==NULL){
			Node* temp=root->right;
			delete root;
			return temp;
		}
		//2child
		if(root->right!=NULL&& root->left!=NULL){
			int mini=minval(root->right)->data;
			root->data=mini;
			root->right=deleteFromBST(root->right,mini);
			return root;
		}
	}
	if(root->data>val){
		root->left=DeleteFromBST(root->left,val);
	}
	else
	root->right=DeleteFromBST(root->right,val);
	return root;
}

bool isBST(Node* root, int min, int max){
	if(root==NULL){
		return true;
	}
	else if(root->data>min && root->data<ma){
		bool left=isBST(root->left,min,root->data);
		bool right=isBST(root->right,root->data,max);
		return (left && right);
	}
	else
	return false;
}

void predsucc(Node* root, int key){
	Node* temp= root;
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
	}}
	
}

class heap{
	public:
	int arr[100];
	int size;
	heap(){
		arr[0]=-1;
		size=0;
	}
	void insert(int val){
		size=size+1;
		int index=size;
		arr[index]=val;
		while(index>1){
			int parent=index/2;
			if(arr[parent]<arr[index]){
				swap(arr[parent],arr[index]);
				index=parent;
			}
			else
			return;
		}
	}
	void heapify(int arr[],int n, int i){
		int largest=i;
		int left=2*i;
		int right=2*i+1;
		if (left<=n&&arr[largest]<arr[left]){
			largest=left;
		}
	}
	void print(){
		for (int i=1;i<=size;i++){
			cout<<arr[i]<<" "
		}cout<<endl;
	}
};

void heapify(int arr[],int n,int i){
	int largest=i;
	int left=2*i;
	int right=2*i+1;
	if(left<=n && arr[largest]<arr[left]){
		largest=left;
	}
	if(right<=n && arr[largest]<arr[right]){
		largest=right;
	}
	if(largest!=i)
	swap(arr[i],arr[largest]);}

int main(){
	return 0;
}

