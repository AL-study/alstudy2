### 1991. 트리

- 트리의 hello world(?)격 문제라고 할 수 있다. 전위순회(preorder traversal), 중위순회(inorder traversal), 후위순회(postorder traversal)를 이용하여 트리를 탐색하는 문제.

- c++에서는 구조체를 이용하기도 하고, 클래스를 이용하기도 하며, 재귀함수로 표현하기도 한다. 여기서는 재귀함수를 이용해서 문제를 해결했다.

- ```c++
  #include <iostream>
  
  using namespace std;
  int arr[32][2],n;
  // 루트-왼쪽-오른쪽 
  void preorder(int node){
  	if(node==(int)('.'-'A')){
  		return; 
  	}
  	cout<<(char)(node+'A');
  	preorder(arr[node][0]);
  	preorder(arr[node][1]);
  }
  // 왼쪽-루트-오른쪽 
  void inorder(int node){
  	if(node==(int)('.'-'A')){
  		return; 
  	}
  	inorder(arr[node][0]);
  	cout<<(char)(node+'A');
  	inorder(arr[node][1]);
  }
  // 왼쪽-오른쪽-루트 
  void postorder(int node){
  	if(node==(int)('.'-'A')){
  		return; 
  	}
  	postorder(arr[node][0]);
  	postorder(arr[node][1]);
  	cout<<(char)(node+'A');
  }
  
  int main(){
  	cin>>n;
  	for(int i=0;i<n;i++){
  		char a,b,c;
  		cin>>a>>b>>c;
  		arr[a-'A'][0]=b-'A';
  		arr[a-'A'][1]=c-'A';
  	}
  	preorder(0);
  	cout<<"\n";
  	inorder(0);
  	cout<<"\n";
  	postorder(0);
  }
  ```

  