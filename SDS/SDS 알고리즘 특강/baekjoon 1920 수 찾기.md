### 1920. 수 찾기



#### 문제

N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

#### 입력

첫째 줄에 자연수 N(1≤N≤100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1≤M≤100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수들의 범위는 int 로 한다.



- 이분 탐색의 hello world격 문제. 이분 탐색을 구현하면 된다.

- ```c++
  #include <iostream>
  #include <algorithm>
  using namespace std;
  
  int n,m,arr[100001],low,high;
  
  int main(){
  	ios_base :: sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  	cin>>n;
  	for(int i=0;i<n;i++){
  		cin>>arr[i];
  	}
  	sort(arr,arr+n);
  	cin>>m;
  	for(int i=0;i<m;i++){
  		int num;
  		cin>>num;
  		bool flag=false;
  		low=0;high=n-1;
  		while(low<=high){
  			int mid=(low+high)/2;
  			if(num==arr[mid]){
  				flag=true;
  				break;
  			}else if(num<arr[mid]){
  				high=mid-1;
  			}else{
  				low=mid+1;
  			}
  		}
  		if(flag){
  			cout<<"1\n";
  		}else{
  			cout<<"0\n";
  		}
  	}
  	return 0;
  }
  ```

  