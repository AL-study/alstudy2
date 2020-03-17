#include <iostream>
using namespace std;

string str[50];
int n,ans;

void check(){
	for(int i=0;i<n;i++){
		int num=1;
		char temp=str[i][0];
		for(int j=1;j<n;j++){
			if(temp==str[i][j]){
				num++;
			}else{
				ans=max(ans,num);
				temp=str[i][j];	
				num=1;
			}
		}
		ans=max(ans,num);
	}
	for(int i=0;i<n;i++){
		int num=1;
		char temp=str[0][i];
		for(int j=1;j<n;j++){
			if(temp==str[j][i]){
				num++;
			}else{
				temp=str[j][i];
				ans=max(ans,num);
				num=1;
			}
		}
		ans=max(ans,num);
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>str[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j!=n-1){
				if(str[i][j]!=str[i][j+1]){
					char temp=str[i][j];
					str[i][j]=str[i][j+1];
					str[i][j+1]=temp;
					check();	
					temp=str[i][j];
					str[i][j]=str[i][j+1];
					str[i][j+1]=temp;
				}
			}
			if(i!=n-1){
				if(str[i][j]!=str[i+1][j]){
					char temp=str[i][j];
					str[i][j]=str[i+1][j];
					str[i+1][j]=temp;
					check();	
					temp=str[i][j];
					str[i][j]=str[i+1][j];
					str[i+1][j]=temp;
				}
			}
		}
	}
	cout<<ans;
}
