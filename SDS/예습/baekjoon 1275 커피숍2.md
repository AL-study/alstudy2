### 1275. 커피숍2



#### 문제

모두 알다시피 동호는 커피숍의 마담이다. (마담이 무엇인지는 본인에게 물어보도록 하자.)

어느 날 커피숍의 손님 A씨가 동호에게 게임을 하자고 했다.

그 게임은 다음과 같은 규칙을 갖는다.

N개의 정수가 있으면, 동호는 다음과 같이 말한다. “3번째에서7번째 수의 합은 무엇이죠?” 그러면 상대방은 “그 답은 000입니다. 그리고 8번째 수를 2로 고치도록 하죠” 그러면 동호는 “네 알겠습니다.”라고 한 뒤에 다시 상대방이 동호가 했던 것처럼 “8번째에서 9번째 수의 합은 무엇이죠?”라고 묻게된다. 이 것을 번갈아 가면서 반복하는 게임이다.

당신은 이 게임의 심판 역을 맡았다. 요컨대, 질문에 대한 답들을 미리 알아야 한다는 것이다.

당신의 머리가 출중하다면 10만개 가량 되는 정수와 10만턴 정도 되는 게임을 기억할 수 있을 것이다. 몇판 이 게임을 즐기던 동호는 많은 사람들이 이 게임을 하기를 바라게 되었고, 당신에게 심판 프로그램을 구현해달라고 요청했다.

#### 입력

첫째 줄에 수의 개수 N과 턴의 개수 Q가 주어진다.(1 ≤ N, Q ≤ 100,000) 둘째 줄에는 처음 배열에 들어가 있는 정수 N개가 주어진다. 세 번째 줄에서 Q+2번째 줄까지는 x y a b의 형식으로 x에서 y까지의 합을 구하여라, a번째 수를 b로 바꾸어라 라는 뜻의 데이터가 주어진다.

입력되는 모든 수는 32비트 부호있는 정수이다.



- 부분합 세그먼트 트리를 구현하는 문제. 초기화 함수, 해당 범위의 부분합을 구하는 함수, 해당 인덱스 값부터 차례로 부분합을 갱신시키는 함수를 구현한다. 세그먼트 트리의 기본 문제.

- 주의사항으로는 x>y인 경우 y번째 부터 x번째로 생각해야하기 때문에 둘을 스왑해준다.

- ```c++
  #include <iostream>
  #include <cmath>
  #include <vector>
  using namespace std;
  int n,q;
  long long init(vector<long long> &v, vector<long long> &tree, int node, int start, int end){
  	if(start==end){
  		return tree[node]=v[start];
  	}else{
  		return tree[node]=init(v,tree,node*2,start,(start+end)/2)+init(v,tree,node*2+1,(start+end)/2+1,end);
  	}
  }
  // 해당 범위의 구간 합을 구한다. 
  long long sum(vector<long long> &tree, int node, int start, int end, int left, int right){
  	if(right<start||end<left){
  		return 0;
  	}
  	if(left<=start&&end<=right){
  		return tree[node];
  	}
  	return sum(tree,node*2,start,(start+end)/2,left,right)+sum(tree,node*2+1,(start+end)/2+1,end,left,right);
  }
  // 해당 index의 값을 전부 갱신하여 구간합을 갱신한다. 
  void update(vector<long long> &tree, int node, int start, int end, int index, long long diff){
  	if(index<start || index>end){
  		return;
  	}
  	tree[node]+=diff;
  	if(start!=end){
  		update(tree,node*2,start,(start+end)/2,index,diff);
  		update(tree,node*2+1,(start+end)/2+1,end,index,diff);
  	}
  }
  
  int main(){
  	ios_base :: sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  	cin>>n>>q;
  	vector<long long> v(n);
  	int h=(int)ceil(log2(n));
  	int tree_s=(1<<(h+1));
  	vector<long long>tree(tree_s);
  	for(int i=0;i<n;i++){
  		cin>>v[i];
  	}
  	init(v,tree,1,0,n-1);
  	for(int i=0;i<q;i++){
  		long long x,y,a,b;
  		cin>>x>>y>>a>>b;
  		if(x>y){
  			swap(x,y);
  		}
  		cout<<sum(tree,1,0,n-1,x-1,y-1)<<"\n";
  		
  		long long diff=b-v[a-1];
  		//해당 배열은 바꿔주고 update해야 한다. 
  		v[a-1]=b;
  		update(tree,1,0,n-1,a-1,diff);
  	}
  }
  ```

  