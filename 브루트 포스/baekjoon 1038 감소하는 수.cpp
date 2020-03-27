#include <iostream>
#include <queue>
using namespace std;
int n,cnt=9;
queue<long long> q;
int main(){
	cin>>n;
	if(0<=n&&n<=9){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=9;i++){
		q.push(i);
	}
	while(cnt<n){
		long long target=q.front();
		q.pop();
		int num=target%10;
		for(int i=0;i<num;i++){
			q.push(target*10+i);
			cnt++;
			if(cnt==n){
				cout<<target*10+i;
				return 0;
			}else if(target*10+i==9876543210){
				cout<<-1;
				return 0;
			}
		}	
	}
}
