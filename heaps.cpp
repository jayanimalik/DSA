#include<iostream>
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
	}
};
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
	int index= size;
	arr[index]=val;
	while (index>1){
		int parent=index/2;
		if(arr[parent]<arr[index]){
			swap(arr[parent],arr[index]);
			index=parent;
		}
		else{
			return;
}}}
	
void print(){
	for (int i=1;i<size+1;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
	
void deletefromHeap(){
	if (size==0){
		cout<<"Nothing to delete"<<endl;
		return;
	}
	arr[1]=arr[size];
	size--;
	//take root node to its correct pos
	int i=1;
	while(i<size){
		int leftIndex=2*i;
		int rightIndex=2*i+1;
		
		if(leftIndex<size && arr[i]<arr[leftIndex]){
			swap(arr[i],arr[leftIndex]);
			i=leftIndex;
		}
		else if(rightIndex<size && arr[i]<arr[rightIndex]){
			swap(arr[i],arr[rightIndex]);
			i=rightIndex;
		}
		else{
			return;}}}
	
};

void heapify(int arr[],int n, int i){
	int largest=i;
	int left=2*i;
	int right=2*i+1;
	
	if(left<=n && arr[largest]< arr[left]){
		largest=left;
	}
	if(right<=n && arr[largest]< arr[right]){
		largest=right;
	}
	
	if(largest!=i){
		swap(arr[largest],arr[i]);
	}
}

void heapsort(int arr[],int n){
	int size=n;
	while(size>1){
		//1. swap first and last
		swap(arr[size],arr[1]);
		size--;
		//2.
		heapify(arr,size,1);
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
}}
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
	heap h;
	h.insert(50);
	h.insert(55);
	h.insert(53);
	h.insert(52);
	h.insert(54);
	h.print();
	
	int arr[6]={-1,54,53,55,52,50};
	int n=5;
	for(int i=n/2;i>0;i--){
		heapify(arr,n,i);
	}
	/*for(int i=1;i<=n;i++){
		cout<<arr[i]<<", ";
	}cout<<endl;*/
	
	heapsort(arr,n);
	cout<<"printing sorted array"<<endl;
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<", ";
	}cout<<endl;
	return 0;
}

