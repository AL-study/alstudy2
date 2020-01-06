### 1339. 단어 수학



#### 문제

민식이는 수학학원에서 단어 수학 문제를 푸는 숙제를 받았다.

단어 수학 문제는 N개의 단어로 이루어져 있으며, 각 단어는 알파벳 대문자로만 이루어져 있다. 이때, 각 알파벳 대문자를 0부터 9까지의 숫자 중 하나로 바꿔서 N개의 수를 합하는 문제이다. 같은 알파벳은 같은 숫자로 바꿔야 하며, 두 개 이상의 알파벳이 같은 숫자로 바뀌어지면 안 된다.

예를 들어, GCF + ACDEB를 계산한다고 할 때, A = 9, B = 4, C = 8, D = 6, E = 5, F = 3, G = 7로 결정한다면, 두 수의 합은 99437이 되어서 최대가 될 것이다.

N개의 단어가 주어졌을 때, 그 수의 합을 최대로 만드는 프로그램을 작성하시오.

#### 입력

첫째 줄에 단어의 개수 N(1 ≤ N ≤ 10)이 주어진다. 둘째 줄부터 N개의 줄에 단어가 한 줄에 하나씩 주어진다. 단어는 알파벳 대문자로만 이루어져있다. 모든 단어에 포함되어 있는 알파벳은 최대 10개이고, 수의 최대 길이는 8이다. 서로 다른 문자는 서로 다른 숫자를 나타낸다.



- 프로님의 새로운 접근법으로 쉽게 풀었던 문제. 예를 들어 테스트 케이스 2번의 GCF, ACDEB가 주어진다면, 각 자리수 만큼의 곱으로 표현할 수 있다. 이게 무슨 말이냐면, GCF의 경우 G x 100 + C x 10 + F x 1 로 표현 할 수 있다. 또한 ACDEB는 A x 10000 + C x 1000 + D x 100 + E x 10 + B x 1로 표현 할 수 있다. GCF와 ACDEB를 더해보면 A x 100000 + B x 1 + C X 1010 + D x 100 + E x 10 + F x 1 + G x 100 으로 표현 가능하다. 따라서 내림차순으로 정렬한 뒤 9부터 하나씩 빼주면서 곱을해 결과를 출력해주면 된다. 

- ```c+
  #include <iostream>
  #include <vector>
  #include <algorithm>
  using namespace std;
  int n,arr[26],ans;
  vector<int> v(26);
  bool compare(int a,int b){
  	return a>b;
  }
  int main(){
  	cin>>n;
  	for(int i=0;i<n;i++){
  		string str;
  		cin>>str;
  		int num=1;
  		for(int j=str.length()-1;j>=0;j--){
  			v[str[j]-'A']+=num;
  			num*=10;
  		}
  	}
  	sort(v.begin(),v.end(),compare);
  	int number=9;
  	for(int i=0;i<10;i++){
  		ans+=v[i]*number;
  		number--;
  	}
  	cout<<ans;
  }
  ```

  

  