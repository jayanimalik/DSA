
#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		node(int data){
			this->data=data;
			this->next=NULL;
		}
		~node(){
			int value=this->data;
			if(this->next!=NULL){
				delete next;
				this->next=NULL;
			}
			cout<<"Memory freed for for node with data="
			<<value<<endl;
		}
};

void insertathead(node* &head,int d){
	node* temp=new node(d);
	temp->next=head;
	head=temp;
}
void insertattail(node* &tail,int d){
	node* temp=new node(d);
	tail->next=temp;
	tail=tail->next;
}

void InsertAtPosition(node* &head,node* &tail,
int position,int d){
	
	if (position==1){
		insertathead(head,d);
		return;
	}
	node* nodetoinsert=new node(d);
	int cnt=1;
	node* temp=head;
	while(cnt<position-1){
		cnt++;
		temp=temp->next;
	}
	
	if(temp->next=NULL){
		insertattail(tail,d);
	}
	else{
		nodetoinsert->next=temp->next;
		temp->next=nodetoinsert;
	}
}

void deleteNode(node* &head,node* &tail,int position){
	if(position==1){
		node* temp=head;
		head=head->next;
		temp->next=NULL;
		delete temp;
	}
	else{
		node* curr=head;
		node* prev=NULL;
		int cnt=1;
		while(cnt<position){
			prev=curr;
			curr=curr->next;
			cnt++;
		}
		prev->next=curr->next;
		curr->next=NULL;
		delete curr;
	}
}

void print(node* &head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main(){
	node* node1= new node(10);
	node* head=node1;
	node* tail=node1;
	insertathead(head,12);
	insertattail(tail,15);
	print(head);
	
	InsertAtPosition(head,tail,4,22);
	print(head);
	
	deleteNode(head,tail,3);
	print(head);
	
	cout<<"head:"<<head->data<<endl;
	cout<<"tail:"<<tail->data<<endl;
	return 0;
}
