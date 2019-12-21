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
