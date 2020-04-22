/*
	각 정점 간의 최단거리를 모두 구하는 플로이드 알고리즘은 n^3의 시간
	복잡도를 가진다. 플로이드 알고리즘 자체는 어렵지 않아서 구현이 쉽지만,
	이미 구해진 플로이드 알고리즘에 대해 역으로 생각해서 구해야하는 문제였
	는데, 조건을 생각하기가 어려웠고, 답을 참고했다.

	핵심 조건은 다음 2가지이다.

	1. i->j경우와 i->k + k->j의 거리가 같다면 보다 많은 도시를 커버해야하기
	때문에, i->j의 도로를 지운다.

	2. i->j로 가는 경로의 길이가 k를 거쳐가는 길이보다 크다면 최소 이동거리가
	성립하지 않으므로, -1을 출력한다.

	이 외에 예외사항으로 i==j, j==k, i==k 일경우 스킵하고 다음으로 넘어간다.
*/
#include <iostream>
#include <cstring>
using namespace std;

int arr[20][20],n,ans;
bool c[20][20];

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	memset(c,true,sizeof(c));
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j||j==k||i==k){
					continue;
				}
				else if(arr[i][j]==arr[i][k]+arr[k][j]){
					c[i][j]=false;
				}else if(arr[i][j]>arr[i][k]+arr[k][j]){
					cout<<"-1";
					return 0;
				}
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(c[i][j]){
				ans+=arr[i][j];
			}
		}
	}
	cout<<ans;
}
