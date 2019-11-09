### 3079. 입국심사

- 이분탐색을 이용해 최소의 입국시간을 출력하는 문제

- mid값을 기준으로 각 심사대에서 걸리는 시간만큼을 나누어 주어 총 인원을 구하고 그 인원이 입력받은 인원보다 같거나 클경우 결과값(result)를 갱신하고 high=mid-1로 설정후 다시 탐색. 그렇지 않다면 low=mid+1.

- ```c++
  #include<iostream>
  using namespace std;
  int n,m; 
  //범위를 보면 알 수 있듯이 int를 초과하기 때문에 long long으로 선언
  long long high,low,mid,sum,result,maxnum;
  int main() {
  	cin>>n>>m;
  	int arr[n];
  	for(int i=0;i<n;i++){
  		cin>>arr[i];
  		if(maxnum<arr[i]){
  			maxnum=arr[i];
  		}
  	}
  	high=maxnum*m;
  	result=high;
  	while(low<=high){
  		mid=(low+high)/2;
  		sum=0;
  		for(int i=0;i<n;i++){
              //mid값을 기준으로 각 심사대에서 걸리는 시간만큼을 나누어 주어 총 인원을 구한다.
  			sum+=mid/arr[i];
  		}
  		if(sum>=m){
  			result=min(result,mid);
  			high=mid-1;	
  		}else{
  			low=mid+1;
  		}
  	}
  	cout<<result;
  }
  ```

