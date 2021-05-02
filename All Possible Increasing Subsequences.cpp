#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll tree[800000];
ll mod=1000000007;
void build(ll p,ll l,ll r,ll val,ll i)
{
      if(l>i||r<i)
        return;
    if(l==r&&l==i)
    {
        tree[p]=val;
        return;
    }

    ll le=2*p;
    ll mid=(l+r)/2;
    build(le,l,mid,val,i);
    build(le+1,mid+1,r,val,i);
    tree[p]=(tree[le]+tree[le+1])%mod;
}
ll query(ll p,ll l,ll r,ll i,ll j)
{
    if(l>j||r<i)
        return 0;
    if(l>=i&&r<=j)
        return tree[p];
    ll le=2*p;
    ll mid=(l+r)/2;
    ll p1=query(le,l,mid,i,j);
    ll p2=query(le+1,mid+1,r,i,j);
    return (p1+p2)%mod;
}
bool cmp(pair<ll,ll>p1,pair<ll,ll>p2)
{
    if(p1.first<p2.first)
        return 1;
    if(p1.first==p2.first&&p1.second>p2.second)
        return 1;
    return 0;
}
int main()
{
    ll t;
    scanf("%lld",&t);
    for(ll ts=1; ts<=t; ts++)
    {
        memset(tree,0,sizeof(tree) );
        vector<pair<ll,ll> >vp;

        ll n,a;
        scanf("%lld",&n);
        for(ll i=1; i<=n; i++)
        {
            scanf("%lld",&a);
            vp.push_back({a,i});
        }
        sort(vp.begin(),vp.end(),cmp);
        for(ll i=0; i<n; i++)
        {
            a=vp[i].second;
            // cout<<a<<" ";
            ll b=query(1,0,n,0,a-1);
            build(1,0,n,b+1,a);
        }
        ll b=query(1,0,n,0,n);
        printf("Case %lld: %lld\n",ts,b);

    }
}
