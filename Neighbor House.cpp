
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
ll dp1[4][22] ;
ll r[100];
ll g[100];
ll b[100];

ll recur(ll cur,ll ind)
{
    if(ind>n)
        return 0;
        if( dp1[cur][ind]!=-1)
            return dp1[cur][ind];
    ll a=LONG_LONG_MAX;
    ll b1=LONG_LONG_MAX;

    if(cur==1)
    {
        a=r[ind]+recur(2,ind+1)   ;
        b1=r[ind]+recur(3,ind+1)   ;

    }
    else if(cur==2)
    {
        b1=g[ind]+recur(1,ind+1)   ;
        a=g[ind]+recur(3,ind+1)   ;
    }
    else
    {
        b1=b[ind]+recur(2,ind+1)   ;
        a=b[ind]+recur(1,ind+1)   ;
    }
    return    dp1[cur][ind]=min(a,b1);

}
int main()
{
    ll t;
    cin>>t;
    ll ts=0;
    while(t--)
    {

        ts++;
        cin>>n;
        ll a,c,d;
        memset(dp1,-1,sizeof(dp1));


        for(ll i=1; i<=n; i++)
            cin>>r[i]>>g[i]>>b[i];

  printf("Case %lld: ",ts);
        ll res=recur(1,1)   ;
        res=min(res,recur(2,1) )  ;
        res=min(res,recur(3,1) )  ;

        cout<<res<<endl;


    }
}


