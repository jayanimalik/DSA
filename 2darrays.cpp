#include<iostream>
using namespace std;

bool isPresent(int arr[][4],int target, int i, int j){
	for (int i=0; i<3;i++){
		for(int j=0;j<4;j++){
			if(target==arr[i][j])
			return 1;
		}
	}
	return 0;
}

void printSum(int arr[][4],int i, int j){
	for (int i=0; i<3;i++){
		int sum=0;
		for(int j=0;j<4;j++){
			sum+=arr[i][j];
		}
		cout<<"sum "<<i+1<<"->"<<sum<<endl;
	}
}

void printSpiral(int arr[][3],int row,int col){
	int count=0;
	int startrow=0;
	int startcol=0;
	int endrow=row-1;
	int endcol=col-1;
	int total=row*col;
	
	while (count<total){
		//start row
		for (int i=startcol;count<total && i<endcol;i++){
			cout<<arr[startrow][i]<<" ";
			count++;
		}
		startrow++;
		
		//endcol
		for(int i=startrow;count<total && i<endrow;i++){
			cout<<arr[i][endcol]<<" ";
			count++;
		}
		endcol--;
		
		//endrow
		for (int i=endcol;count<total && i>=startcol;i--){
			cout<<arr[endrow][i]<<" ";
			count++;
		}
		endrow--;
		
		//start column
		for (int i=endrow;count<total && i>=startrow;i--){
			cout<<arr[i][startcol];
			count++;
		}
		startcol++;
}}

int main()
{
	int arr[3][4]={{1,3,5,7},
	{10,11,16,20},{23,30,34,60}};
	/*for (int i=0; i<3;i++){
		for(int j=0;j<4;j++){
			cin>>arr[i][j];
		}
	}*/
	
	for (int i=0; i<3;i++){
		for(int j=0;j<3;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
	/*int target;
	cout<<"enter element to search"<<endl;
	cin>>target;
	if (isPresent(arr,target,3,4)){
		cout<<"element found"<<endl;
	}
	else
	cout<<"not found"<<endl; */
	
	return 0;
}

