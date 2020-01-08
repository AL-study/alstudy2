#include <iostream>
#include <map>
using namespace std;

map<string, int> m;
int cnt;

int main(){
	string s;
	while (getline(cin, s)) {
		m[s]++;
		cnt++;
	}
	cout.precision(4);
	cout<<fixed;
	for(map<string,int>::iterator it = m.begin(); it != m.end(); it++){
		cout<<it->first<<" "<<(double)it->second/cnt*100<<'\n';
	}
}
