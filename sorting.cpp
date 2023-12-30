#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
	for (int i=0;i<n;i++){
		bool swapped= false;
		for(int j=0;j<n-i;j++){
		if (arr[j]>arr[j+1]){
			swapped=true;
			swap(arr[j],arr[j+1]);
		}}
		if(swapped==true)
		break;
	}
}

void selectionSort(int arr[],int n){
	for (int i=0;i<n;i++){
		int minIndex=1;
		
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[minIndex])
			minIndex=j;
		}
		swap(arr[minIndex],arr[i]);
	}
}

void insertionSort(int arr[],int n){
	for (int i=0;i<n;i++){
		int temp=arr[i];
		int j=i+1;
		for(;j>=0;j++){
			if(arr[j]>temp){
				arr[j+1]=arr[j];
			}
			else
			break;
		}
		arr[j+1]=temp;
	}
}

int main(){
	return 0;
}

