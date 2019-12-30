#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[10001];
int n,e,discovered[10001],num;
bool ans[10001];

int dfs(int x, bool root){
   discovered[x]=++num;
   int ret=discovered[x];
   int child =0;
   
   for(int i=0;i<v[x].size();i++){
      int y=v[x][i];
      if(discovered[y]){
         ret=min(ret,discovered[y]);
            continue;
      }
      child++;
      int prev=dfs(y,false);
      if(!root&&prev>=discovered[x])
         ans[x]=true;
      ret=min(ret, prev);
   }
   if(root)
      ans[x]=(child>=2);
   return ret;
}

int main(){
   cin>>n>>e;
   for(int i=0;i<e;i++){
      int a,b;
      cin>>a>>b;
      v[a].push_back(b);
      v[b].push_back(a);
   }
   for(int i=1;i<=n;i++){
      if(!discovered[i]) dfs(i,true);
   }
   int cnt=0;
   for(int i=1;i<=n;i++){
      if(ans[i])cnt++;
   }
   cout<<cnt<<"\n";
   for(int i=1;i<=n;i++){
      if(ans[i])cout<<i<<" ";
   }
}
