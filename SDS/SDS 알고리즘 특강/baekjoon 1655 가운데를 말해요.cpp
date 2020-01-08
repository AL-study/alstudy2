#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int> maxpq;
priority_queue<int, vector<int>, greater<int> > minpq;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		if(minpq.size()==maxpq.size()){
			maxpq.push(num);
		}else{
			minpq.push(num);
		}
		if(!minpq.empty()&&!maxpq.empty()&&minpq.top()<maxpq.top()){
			int temp1=minpq.top();
			int temp2=maxpq.top();
			minpq.pop();
			maxpq.pop();
			minpq.push(temp2);
			maxpq.push(temp1);
		}
		
		
		cout<<maxpq.top()<<"\n";
	}
}
