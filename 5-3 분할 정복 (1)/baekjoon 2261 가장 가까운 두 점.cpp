#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct POINT{
	int x,y;
};
int n;
vector<POINT> p;
int dist(POINT a,POINT b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool compare(POINT a,POINT b){
	if(a.x==b.x){
		return a.y<b.y;
	}else{
		return a.x<b.x;
	}
}

bool compare2(POINT a,POINT b){
	if(a.y==b.y){
		return a.x<b.x;
	}else{
		return a.y<b.y;
	}
}

int closet(vector<POINT>::iterator it,int num){
	if(num==2){
		return dist(it[0],it[1]);
	}
	if(num==3){
		return min(min(dist(it[0],it[1]),dist(it[1],it[2])),dist(it[2],it[0]));
	}
	int line=(it[num/2-1].x+it[num/2].x)/2;
	int d=min(closet(it,num/2),closet(it+num/2,num-num/2));
	vector<POINT> mid;
	mid.reserve(num);
	for(int i=0;i<num;i++){
		int t=line-it[i].x;
		if(t*t<d){
			mid.push_back(it[i]);
		}
	}
	sort(mid.begin(),mid.end(),compare2);
	int mid_sz=mid.size();
	for(int i=0;i<mid_sz-1;i++){
		for(int j=i+1;j<mid_sz&&(mid[j].y-mid[i].y)*(mid[j].y-mid[i].y)<d;j++){
			d=min(d,dist(mid[i],mid[j]));
		}
	}
	return d;
}



int main(){

	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		p.push_back({x,y});
	}
	sort(p.begin(),p.end(),compare);
	
	cout<<closet(p.begin(),n);
	return 0;
}
