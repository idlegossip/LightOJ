
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
ll dp[35][35][35];
ll dp1[35] [35];
ll ncr(ll m,ll r)
{
      if(m==r||r==0)
            return 1;
      if(m<r)
            return 0;
      if(dp1[m][r]!=-1)
            return dp1[m][r];
      ll a=ncr(m-1,r-1)+ncr(m-1,r);
      return dp1[m][r]=a;
}


ll recur(ll i,ll j, ll c)
{
    if(c==0)
        return 1;
    if(i<=0||j<=0)
        return 0;
    if(dp[i][j][c]!=-1)
        return dp[i][j][c];
    ll a=0;
    a=j*recur(i-1,j-1,c-1);
     a+=recur(i-1,j,c);
    dp[i][j][c]=a;

    return a;

}
int main()
{
    ll t;
    cin>>t;
    ll ts=0;
    while(t--)
    {
        ts++;



        cin>>n>>k;
        memset(dp1,-1,sizeof(dp1));
       // memset(r,0,sizeof(r));
        //memset(co,-0,sizeof(co));
        printf("Case %lld: ",ts);
       // ll res=recur(n,n,k);
       ll res=ncr(n,k);
       res*=res;
       for(ll i=1;i<=k;i++)
            res*=i;
        cout<<res<<endl;


    }
}

