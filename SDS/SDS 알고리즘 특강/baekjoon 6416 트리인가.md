# 6416. 트리인가?

## 문제

트리는 굉장히 잘 알려진 자료 구조이다. 트리를 만족하는 자료 구조는 비어 있거나(노드의 개수가 0개), 노드의 개수가 1개 이상이고 방향 간선이 존재하며 다음과 같은 조건을 만족해야 한다. 이때, 노드 u에서 노드 v로 가는 간선이 존재하면 간선을 u에 대해서는 '나가는 간선', v에 대해서는 '들어오는 간선'이라고 하자.

1. 들어오는 간선이 하나도 없는 단 하나의 노드가 존재한다. 이를 루트(root) 노드라고 부른다.
2. 루트 노드를 제외한 모든 노드는 반드시 단 하나의 들어오는 간선이 존재한다.
3. 루트에서 다른 노드로 가는 경로는 반드시 가능하며, 유일하다. 이는 루트를 제외한 모든 노드에 성립해야 한다.

아래의 그림을 보자. 원은 노드, 화살표는 간선을 의미하며, 화살표의 방향이 노드 u에서 노드 v로 향하는 경우 이는 이 간선이 u에서 나가는 간선이며 v로 들어오는 간선이다. 3개의 그림 중 앞의 2개는 트리지만 뒤의 1개는 트리가 아니다.

![img](https://www.acmicpc.net/upload/images2/tree1.gif)![img](https://www.acmicpc.net/upload/images2/tree2.gif)![img](https://www.acmicpc.net/upload/images2/tree3.gif)

당신은 간선의 정보들을 받아서 해당 케이스가 트리인지를 판별해야 한다.

## 입력

입력은 여러 개의 테스트 케이스로 이루어져 있으며, 입력의 끝에는 두 개의 음의 정수가 주어진다.

각 테스트 케이스는 여러 개의 정수쌍으로 이루어져 있으며, 테스트 케이스의 끝에는 두 개의 0이 주어진다.

각 정수쌍 u, v에 대해서 이는 노드 u에서 노드 v로 가는 간선이 존재함을 의미한다. u와 v는 0보다 크다.

## 출력

각 테스트 케이스에 대해서, 테스트 케이스의 번호가 k일 때(k는 1부터 시작하며, 1씩 증가한다) 트리일 경우 "Case k is a tree."를, 트리가 아닐 경우 "Case k is not a tree."를 출력한다.



- 해당 조건의 1, 2, 3번 조건을 토대로 다음과 같은 조건을 성립하면 트리로 판별한다.

  1. 루트 노드가 하나인가?
     - 진입차수가 0인 노드가 하나만 존재하는지 판별한다.
  2. 총 간선의 개수+1이 노드의 수와 같은가?
  3. 부모가 2개 이상인 노드가 있는가?
     - 진입 차수가 2개 이상이라면 부모 노드가 2개 이상이다.

- 하지만 이 조건만 따져준다고 답을 맞출 수 없다. 히든 케이스가 있는데, 0 0만 대입 했을 때도 트리가 성립된다. flag변수로 처리를 해주었다.

- ```c++
  #include <iostream>
  #include <cstring>
  #include <algorithm>
  using namespace std;
  
  int edgecnt,minnode=100000,maxnode,indegree[10002],outdegree[10002],cnt=1;;
  bool node[10002],check,chk;
  int main(){
  	ios_base :: sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  	while(1){
  		int a,b;
  		cin>>a>>b;
  		node[a]=true;
  		node[b]=true;
  		if(a==-1&&b==-1){
  			break;
  		}
  		if(a!=0&&b!=0){
  			maxnode = max({ maxnode, a,b });
              minnode = min({ minnode, a,b });
              chk=true;
              edgecnt++;
  			indegree[b]++;
  			outdegree[a]++;	
  		}
  		if(a==0&&b==0){
  			int rootnum=0;
  			int nodenum=0;
  			
  			for(int i=minnode;i<=maxnode;i++){
  				if(indegree[i]==0&&node[i]&&outdegree[i]!=0){
  					rootnum++;
  				}
  				if(node[i]&&indegree[i]>=2){
  					//cout<<"진입차수";
  					check==true;
  				}
  				if(node[i]){
  					nodenum++;
  				}
  			}
  			if(rootnum!=1||nodenum!=edgecnt+1){
  				//cout<<"루트나 엣지 카운트: "<<nodenum;; 
  				
  				check=true;
  			}
  			if(!chk){
  				cout<<"Case "<<cnt++<<" is a tree.\n";
  			}else{
  				if(check){
  					cout<<"Case "<<cnt++<<" is not a tree.\n";
  				}else{
  					cout<<"Case "<<cnt++<<" is a tree.\n";
  				}
  			}
  			chk=false;
  			memset(node,false,sizeof(node));
  			memset(indegree,0,sizeof(indegree));
  			memset(outdegree,0,sizeof(outdegree));
  			minnode=100000;
  			maxnode=0;
  			edgecnt=0;
  			check=false;
  		}
  	}
  }
  ```

  