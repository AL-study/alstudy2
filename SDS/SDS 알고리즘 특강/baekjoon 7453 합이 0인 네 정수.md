# 7453. 합이 0인 네 정수

## 문제

정수로 이루어진 크기가 같은 배열 A, B, C, D가 있다.

A[a], B[b], C[c], D[d]의 합이 0인 (a, b, c, d) 쌍의 개수를 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 배열의 크기 n (1 ≤ n ≤ 4000)이 주어진다. 다음 n개 줄에는 A, B, C, D에 포함되는 정수가 공백으로 구분되어져서 주어진다. 배열에 들어있는 정수의 절댓값은 최대 228이다.

## 출력

합이 0이 되는 쌍의 개수를 출력한다.



- 4개의 배열에 대한 부분 합을 구한다고 하면 O(N^4)로 시간초과를 면할 수 없다. 4개의 배열을 2개의 배열 묶음으로 나누고, 2개의 배열에 대해 각각 부분합을 구해 투 포인터를 이용해 접근한다.

- ```c++
  #include <iostream>
  #include <vector>
  #include <algorithm>
  using namespace std;
  
  int n,arr1[4000],arr2[4000],arr3[4000],arr4[4000];
  vector<int> v1,v2;
  long long ans;
  
  int main(){
  	cin>>n;
  	for(int i=0;i<n;i++){
  		cin>>arr1[i]>>arr2[i]>>arr3[i]>>arr4[i];
  	}
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			int sum=0;
  			sum=arr1[i]+arr2[j];
  			v1.push_back(sum);
  		}
  	}
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			int sum=0;
  			sum=arr3[i]+arr4[j];
  			v2.push_back(sum);
  		}
  	}
  	sort(v1.begin(),v1.end());
  	sort(v2.begin(),v2.end());
  	int p1=0,p2=v2.size()-1;
  	while(1){
  		if(v1[p1]+v2[p2]==0){
  			long long cnt1=1;
  			long long cnt2=1;
  			while(p1+1<=v1.size()-1&&v1[p1]==v1[p1+1]){
  				p1++;
  				cnt1++;
  			}
  			while(p2-1>=0&&v2[p2]==v2[p2-1]){
  				p2--;
  				cnt2++;
  			}
  			ans+=cnt1*cnt2;
  			p1++;
  		}
  		if(p1<=v1.size()-1&&p2>=0&&v1[p1]+v2[p2]<0){
  			p1++;
  		}
  		if(p1<=v1.size()-1&&p2>=0&&v1[p1]+v2[p2]>0){
  			p2--;
  		}
  		if(p1>v1.size()-1||p2<0){
  			break;	
  		}
  	}
  	cout<<ans;
  }
  ```

  