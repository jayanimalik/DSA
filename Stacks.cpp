#include<iostream>
#include<stack>
class Stack{
	public:
	int *arr;
	int top;
	int size;
	Stack(size){
		this->size=size;
		arr=new int[size];
		top=-1;
	}
	
	void push(int element){
		if(size-top>1){
			top++;
			arr[top]=element;
		}
		else{
			cout<<"Stack Overflow"<<endl;
		}
	}
	
	void pop(){
		if(top>0){
			top--;
		}
		else{
			cout<<"Stack underflow"<<endl;
		}
	}
	
	int peek(){
		if(top>0){
			return arr[top];
		}
		else{
			cout<<"Stack empty"<<endl;
			return -1;
		}
	}
};
using namespace std;
int main(){
	return 0;
}

