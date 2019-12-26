### 1049. 기타줄

- 사야하는 기타줄의 수,타줄을 파는 브랜드 수,6개씩 들어있는 패키지의 가격과 낱개줄의 가격이 주어졌을 때, 최소의 비용을 구하는 문제.

- 그리디적으로 접근하면 모든 패키지의 가격중 가장 최소의 값만을 구하고, 모든 낱개줄의 가격중 가장 최소의 값을 구해 갈아야하는 기타줄의 수 n에 따라 비교해주면 된다.

- ```c++
  #include <iostream>
  using namespace std;
  int n,m,minpack=10000,minpiece=10000,num;
  
  int main(){
  	cin>>n>>m;
  	for(int i=0;i<m;i++){
  		int pack,piece;
  		cin>>pack>>piece;
  		minpack=min(minpack,pack);
  		minpiece=min(minpiece,piece);
  	}
  	if(minpack>6*minpiece){
  		cout<<n*minpiece;
  	}else{
  		if(n/6){
  			num=(n/6)*minpack;
  			n%=6;
  		}
  		if(minpack>n*minpiece){
  			num+=n*minpiece;
  		}else{
  			num+=minpack;
  		}
  		cout<<num;
  	}
  }
  ```

  