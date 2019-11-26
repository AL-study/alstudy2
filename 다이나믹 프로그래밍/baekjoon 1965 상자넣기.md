### 1965. 상자넣기

- 가장 긴 증가하는 부분 수열의 실생활 문제버전. 풀이방식과 코드가 가장 긴 증가하는 부분 수열과 같다.

- 2가지 접근 방법이 존재한다.

  1. O(n^2)

     - 해당 인덱스보다 작은 인덱스를 탐색하면서 dp배열을 갱신하고 최대값을 갱신해 출력

     - ```c++
       #include <iostream>
       using namespace std;
       int n,arr[1001],dp[1001],ans;
       int main(){
       	cin>>n;
       	for(int i=0;i<n;i++){
       		cin>>arr[i];
       	}
       	for(int i=0;i<n;i++){
       		dp[i]=1;
       		for(int j=0;j<i;j++){
       			if(arr[i]>arr[j]){
       				dp[i]=max(dp[i],dp[j]+1);
       			}
       		}
       		ans=max(dp[i],ans);
       	}
       	cout<<ans;
       }
       ```

  2. O(nlogn)

     - 최대 길이의 배열을 갱신하며 저장. 이후 배열의 길이출력.

     - ```c++
       #include <iostream>
       #include <vector> 
       #include <algorithm>
       using namespace std;
       int n;
       vector<int> v;
       int main(){
       	cin>>n;
       	for(int i=0;i<n;i++){
       		int num;
       		cin>>num;
       		if(v.empty()||v.back()<num){
       			v.push_back(num);
       		}else{
       			vector<int>::iterator it;
       			it=lower_bound(v.begin(),v.end(),num);
       			*it=num;
       		}
       	}
       	cout<<v.size();
       }
       ```

       

     