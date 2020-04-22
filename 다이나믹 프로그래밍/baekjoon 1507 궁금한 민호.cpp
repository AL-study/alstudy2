/*
	�� ���� ���� �ִܰŸ��� ��� ���ϴ� �÷��̵� �˰����� n^3�� �ð�
	���⵵�� ������. �÷��̵� �˰��� ��ü�� ����� �ʾƼ� ������ ������,
	�̹� ������ �÷��̵� �˰��� ���� ������ �����ؼ� ���ؾ��ϴ� ������
	�µ�, ������ �����ϱⰡ �������, ���� �����ߴ�.

	�ٽ� ������ ���� 2�����̴�.

	1. i->j���� i->k + k->j�� �Ÿ��� ���ٸ� ���� ���� ���ø� Ŀ���ؾ��ϱ�
	������, i->j�� ���θ� �����.

	2. i->j�� ���� ����� ���̰� k�� ���İ��� ���̺��� ũ�ٸ� �ּ� �̵��Ÿ���
	�������� �����Ƿ�, -1�� ����Ѵ�.

	�� �ܿ� ���ܻ������� i==j, j==k, i==k �ϰ�� ��ŵ�ϰ� �������� �Ѿ��.
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
