#include <iostream>

using namespace std;
int arr[32][2],n;
// 루트-왼쪽-오른쪽 
void preorder(int node){
	if(node==(int)('.'-'A')){
		return; 
	}
	cout<<(char)(node+'A');
	preorder(arr[node][0]);
	preorder(arr[node][1]);
}
// 왼쪽-루트-오른쪽 
void inorder(int node){
	if(node==(int)('.'-'A')){
		return; 
	}
	inorder(arr[node][0]);
	cout<<(char)(node+'A');
	inorder(arr[node][1]);
}
// 왼쪽-오른쪽-루트 
void postorder(int node){
	if(node==(int)('.'-'A')){
		return; 
	}
	postorder(arr[node][0]);
	postorder(arr[node][1]);
	cout<<(char)(node+'A');
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		char a,b,c;
		cin>>a>>b>>c;
		arr[a-'A'][0]=b-'A';
		arr[a-'A'][1]=c-'A';
	}
	preorder(0);
	cout<<"\n";
	inorder(0);
	cout<<"\n";
	postorder(0);
}
