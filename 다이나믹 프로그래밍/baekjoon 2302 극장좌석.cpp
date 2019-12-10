#include<iostream>
using namespace std;

int n,m,dp[41],s,e,ans=1;

int solve(int N){
    if (N <=2) return 1;
    if (dp[N] > 0) return dp[N];
    return dp[N] = solve(N - 1) + solve(N - 2);
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>s;
        ans*=solve(s-e);
        e=s;
    }
    ans=ans*solve(n+1-e);
    cout<<ans;
}

