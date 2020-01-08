#include <iostream>
using namespace std;

int n,arr[32][2];

void pre(int node){
	if(node==(int)('.'-'A')){
		return; 
	}
	cout<<(char)(node+'A');
	pre(arr[node][0]);
	pre(arr[node][1]);
}
void in(int node){
	if(node==(int)('.'-'A')){
		return; 
	}
	in(arr[node][0]);
	cout<<(char)(node+'A');
	in(arr[node][1]);
}
void post(int node){
	if(node==(int)('.'-'A')){
		return; 
	}
	post(arr[node][0]);
	post(arr[node][1]);
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
	pre(0);
	cout<<"\n";
	in(0);
	cout<<"\n";
	post(0);
}
