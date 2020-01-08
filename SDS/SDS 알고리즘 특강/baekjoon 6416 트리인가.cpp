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
