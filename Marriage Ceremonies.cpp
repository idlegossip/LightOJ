#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll dp[17][65538];
ll mat[17][17];
ll  knap(ll i,ll x)
{
    if(i>n)
        return 0;
    if(dp[i][x]!=-1)
        return dp[i][x];
    ll a=0;
    for(ll j=1; j<=n; j++)
    {
        if((x&(1<<(j-1))))
        {
           // cout<<mat[i][j]<<endl;
            a=max(a,mat[i][j]+knap(i+1,x^(1<<j-1)));
        }
    }
    return dp[i][x]=a;
}
int main()
{
    ll ts=0;
    ll t;
    cin>>t;
    while(t--)
    {
        ts++;
    ll m;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(ll i=1; i<=n; i++)
        for(ll j=1; j<=n; j++)
            cin>>mat[i][j];
    cout<<"Case "<<ts<<": ";
     cout<<knap(1,65535)<<endl;
    }
}
