#include <iostream>
using namespace std;
int gcd(long long a,long long b){
	return b==0? a:gcd(b,a%b);
}
int extended_gcd(long long a, long long b){
	int r,q,temp_a=a,t,t1=0,t2=1;
	while(b!=0){
		q=a/b;
		r=a%b;
		t=t1-q*t2;
		a=b;
		b=r;
		t1=t2;
		t2=t;
	}
	while(t1<0)t1+=temp_a;
	return t1;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		long long k,c;
		cin>>k>>c;
		if(c==1){
			if(k+1>1000000000) cout<<"IMPOSSIBLE\n";
			else cout<<k+1<<"\n";
			continue;
		}else if(k==1){
			cout<<"1\n";
			continue;
		}else if(gcd(k,c)!=1){
			cout<<"IMPOSSIBLE\n";
			continue;
		}else{
			long long ans=extended_gcd(k,c);
			if(ans>1000000000) cout<<"IMPOSSIBLE\n";
			else cout<<ans<<"\n";
		}	
	}
}
