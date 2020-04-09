/*
	2차원 배열의 행렬과 다르게 X,Y 좌표로 주어져서 헷갈렸던 문제.
	그 부분을 제외하면 딱히 어려운 부분은 없다.
*/

#include <iostream>
#include <vector>
using namespace std;

struct DIR{
	int r,c;
};
struct ROBOT{
	int r,c,dir;
};
struct COMMAND{
	int num;
	char com;
	int cnt;
};
DIR dir[4]={{1,0},{0,1},{-1,0},{0,-1}}; // N E S W 
ROBOT robot[101];
vector<COMMAND> v;
int a,b,n,m,arr[101][101];

int main(){
	cin>>b>>a>>n>>m;
	for(int i=1;i<=n;i++){
		int x,y;
		char z;
		cin>>x>>y>>z;
		arr[y][x]=i;
		robot[i].r=y;
		robot[i].c=x;
		if(z=='N')robot[i].dir=0;
		else if(z=='E')robot[i].dir=1;
		else if(z=='S')robot[i].dir=2;
		else robot[i].dir=3;
	}
	for(int i=1;i<=m;i++){
		int num,cnt;
		char com;
		cin>>num>>com>>cnt;
		v.push_back({num,com,cnt});
	}
	for(int i=0;i<v.size();i++){
		int num=v[i].num;
		char com=v[i].com;
		int cnt=v[i].cnt;
		for(int j=0;j<cnt;j++){
			if(com=='F'){
				int r,c,d;
				r=robot[num].r;
				c=robot[num].c;
				d=robot[num].dir;
				int nr=r+dir[d].r;
				int nc=c+dir[d].c;
				if(arr[nr][nc]!=0){
					cout<<"Robot "<<num<<" crashes into robot "<<arr[nr][nc];
					return 0;
				}else if(a<nr||nr<1||b<nc||nc<1){
					cout<<"Robot "<<num<<" crashes into the wall";
					return 0;
				}else{
					arr[r][c]=0;
					arr[nr][nc]=num;
					robot[num].r=nr;
					robot[num].c=nc;
				}
			}else if(com=='R'){
				robot[num].dir=(robot[num].dir+1)%4;
			}else{
				robot[num].dir=(robot[num].dir+3)%4;
			}
		}
	}
	cout<<"OK";
	return 0;
}
