### 1992. 쿼드트리

- 분할정복의 기초문제.

- 분할정복을 어떻게 설계해야 하는지 개념을 잡을 수 있었다.

- 하나의 문제(쿼드 트리)를 해결하기 위해 여러 문제로 나누어 (1,2,3,4분면을 판단하여 재귀함수로 다시 분기함)해결한다.

- 이해하기 쉬운 코드

  - ```c++
    #include<iostream>
    using namespace std;
    int n;
    string arr[64];
    void solve(int x,int r,int c){
    	if(x==1){
    		cout<<arr[r][c];
    		return;
    	}
    	bool zero=true,one=true;
    	for(int i=r;i<x+r;i++){
    		for(int j=c;j<x+c;j++){
    			if(arr[i][j]=='1'){
    				zero=false;
    			}else{
    				one=false;
    			}	
    		}
    	}
    	if(zero){
    		cout<<"0";
    	}else if(one){
    		cout<<"1";
    	}else{
    		cout<<"(";
    		solve(x/2,r,c);
    		solve(x/2,r,c+x/2);
    		solve(x/2,r+x/2,c);
    		solve(x/2,r+x/2,c+x/2);
    		cout<<")";
    	}
    	return;
    }
    int main(){
    	cin>>n;
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}
    	solve(n,0,0);
    }
    ```

  #### 참고출처: [꾸준함님 블로그]( https://jaimemin.tistory.com/1072 )

- 다음과 같이 좀 더 간결하게 짤 수 있다.

  - ```c++
    #include <iostream>
    
    using namespace std;
    
    int N;
    string aa[64];
    string solution(int n,int i,int j){
    
    	if(n==1){
    		return string(1,aa[i][j]);
    	}
    	string a=solution(n/2,i,j);
    	string b=solution(n/2,i,j+n/2);
    	string c=solution(n/2,i+n/2,j);
    	string d=solution(n/2,i+n/2,j+n/2);
    	if(a==b&&a==c&&a==d&&a.length()==1){
    		return a;
    	}else{
    		return "("+a+b+c+d+")";
    	}
    		
    }
    
    int main(){
    	cin>>N;
    
    	for(int i=0;i<N;i++){
    		cin>>aa[i];
    	}
    	cout<<solution(N,0,0);
    	
    	return 0;
    }
    ```

  #### 참고출처: [안경잡이 개발자(나동빈 님 네이버블로그)]( https://blog.naver.com/ndb796/221250796972 )