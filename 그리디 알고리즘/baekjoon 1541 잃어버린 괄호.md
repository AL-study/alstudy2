### 1541. 잃어버린 괄호

- 양수와 연산자 +, - 가 주어졌을때 괄호를 넣어 구할 수 있는 최대값을 구하는 문제.

- 잃어버린 괄호지만 진짜로 괄호를 추가할 필요는 없다. 연산자 기호는 덧셈과 뺄셈만 존재하기 때문에 여기서 최대값을 구하기 위해선 -를 만나자마자 바로 빼주고 (해당 수에만 괄호를 붙이는 것과 같다) +를 만날땐 전부 더해주면 된다.

- 구현에 따라 다르겠지만 연산자를 만났을 때 계산을 하려고 하면 마지막 수를 놓치게 된다. 그 부분을 잘 생각해서 처리해주자.

- ```c++
  #include <iostream>
  #include <stdlib.h>
  using namespace std;
  string str;
  int ans;
  int main(void){
      cin >> str;
      string temp = "";
      bool minus = false;
      for (int i = 0; i <= str.size(); i++){
          if (str[i]=='+'||str[i]=='-'||i==str.size()){
              if(minus){
              	ans-=atoi(temp.c_str());
  			}else{
                  ans+=atoi(temp.c_str());
          	}
  			temp = "";
              if(str[i]=='-')
                  minus=true;
              continue;
          }
          temp+=str[i];
      }
  	cout<<ans;
      return 0;
  }
  ```

  