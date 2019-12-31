#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int k;
string p;
bool arr[1000001];
vector<int> v;
bool check(int num){
	int ret=0;
	for(int i=0;p[i];i++){
		ret*=10;
		ret+=p[i]-'0';
		ret%=num;
	}
	return ret==0;
}
 
int main(){
	cin>>p>>k;
	for(int i=2;i<=1000001;i++){
		if(!arr[i]){
			v.push_back(i);
			for(int j=i+i;j<1000001;j+=i){
				arr[j]=true;
			}
		}
	}

	for(int i=0;i<v.size();i++){
		if(v[i]>=k)break;
		if (check(v[i])) {
			cout<<"BAD "<<v[i];
			return 0;
        }
	}
	cout<<"GOOD";

}

