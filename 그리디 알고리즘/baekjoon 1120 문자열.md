### 1120. 문자열

#### 문제

길이가 N으로 같은 문자열 X와 Y가 있을 때, 두 문자열 X와 Y의 차이는 X[i] ≠ Y[i]인 i의 개수이다.  A의 길이는 B의 길이보다 작거나 같다. 이제 A의 길이가 B의 길이와 같아질 때 까지 다음과 같은 연산을 할 수 있다.

​	1. A의 앞에 아무 알파벳이나 추가한다.

​	2. A의 뒤에 아무 알파벳이나 추가한다.

이때, A와 B의 길이가 같으면서, A와 B의 차이의 최솟값을 구해야 한다.

- 주어진 조건을 먼저 살펴보자. A의 앞, 뒤에 아무 알파벳이나 추가한다는 얘기는 **원하는 알파벳을 붙일 수 있다는 뜻이다.** 그러면 A의 남은 길이는 고려할 필요가 없다. 차이를 최소로 하기 위해 B와 같은 문자를 추가하면 되기 때문이다.  

- 그렇다면 A문자열을 B문자열과 비교하며 최소로 가지는 자리만 찾아주어 틀린 자리수의 값만 출력해주면 된다.

- ```C++
  #include <iostream>
  using namespace std;
  string a,b;
  int minnum=100000;
  int main(){
  	cin>>a>>b;
  	int num=b.length()-a.length();
  	for(int i=0;i<=num;i++){
  		int temp=0;
  		for(int j=0;j<a.length();j++){
  			if(b[j+i]!=a[j]){
  				temp++;
  			}
  		}
  		minnum=min(minnum,temp);
  	}
  	cout<<minnum;
  }
  ```

  