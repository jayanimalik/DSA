#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	Node(int data){
		this->data=data;
		this->next=NULL;
	}
	~Node(){
		int value=this->data;
		if(this->next!=NULL){
			delete next;
			next=NULL;
		}
		cout<<"memory freed for Node with value "<<value<<endl;
	}
};

void insertNode(Node* &tail,int element,int d){
	if(tail==NULL){
		Node* temp=new Node(d);
		tail=temp;
		temp->next=temp;
	}
	
	else{
		Node* curr=tail;
		while(curr->data!= element){
			curr=curr->next;
		}
		Node* temp=new Node(d);
		temp->next=curr->next;
		curr->next=temp;
	}
}

void deleteNode(Node* &tail,int element){
	if(tail==NULL){
		cout<<"Empty list"<<endl;
		return;
	}
	else{
		Node* prev= tail;
		Node* curr=prev->next;
		while(curr->data!= element){
			prev=curr;
			curr=curr->next;
		}
		if(curr=prev){
			tail=NULL;
		}
		prev->next=curr->next;
		curr->next=NULL;
		if(tail==curr){
			tail=prev;
		}
		delete curr;
	}
}

void print(Node* tail){
	Node *temp=tail;
	do{
		cout<<tail->data<<" ";
		tail=tail->next;
	}while(tail!=temp);
}

int main(){
	Node* tail=NULL;
	
	insertNode(tail,5,3);
	insertNode(tail,3,5);
	insertNode(tail,5,7);
	insertNode(tail,5,9);
	print(tail);
	deleteNode(tail,5);
	print(tail);
	return 0;
}
