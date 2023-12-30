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
};

void print(Node* &head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void insertathead(Node* &head,int d){
	Node* temp=new Node(d);
	temp->next=head;
	head=temp;
}

void swap(Node * head){
	Node* temp = head;
 
    while (temp != NULL && temp->next != NULL) {
        swap(temp->data,
             temp->next->data);
 
        // Move temp by 2 for the next pair 
        temp = temp->next->next;
    }
}

int main(){
	Node* node1= new Node(10);
	Node* head=node1;
	insertathead(head,12);
	insertathead(head,13);
	insertathead(head,14);
	print(head);
	swap(head);
	print(head);
	return 0;
}

