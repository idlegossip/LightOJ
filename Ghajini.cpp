#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct st
{
    ll mn;
    ll mx;
};
st res;
st tree[800000];
ll ar[300000];
void build(ll p,ll l,ll r)
{
    if(l==r)
    {
        tree[p].mn=ar[l];
        tree[p].mx=ar[l];
        return;
    }
    ll le=2*p;
    ll mid=(l+r)/2;
    build(le,l,mid);
    build(le+1,mid+1,r);
    tree[p].mn=min(tree[le].mn,tree[le+1].mn);
    tree[p].mx=max(tree[le].mx,tree[le+1].mx);
}
void query(ll p,ll l,ll r,ll i, ll j)
{
    if(l>j||r<i)
        return;
    if(l>=i&&r<=j)
    {
        res.mn=min(res.mn,tree[p].mn);
        res.mx=max(res.mx,tree[p].mx);
        return;
    }
    ll le=2*p;
    ll mid=(l+r)/2;
    query(le,l,mid,i,j);
    query(le+1,mid+1,r,i,j);
}
int main()
{
    ll t;
    scanf("%lld",&t);
    for(ll ts=1; ts<=t; ts++)
    {
        ll n,d;
        scanf("%lld %lld",&n,&d);

        for(ll i=1; i<=n; i++)
            scanf("%lld",&ar[i]);
            build(1,1,n);
            ll ans=0;
        for(ll i=1; i<=n-d+1; i++)
        {
           ll a=i+d-1;
           res.mn=LONG_LONG_MAX;
            res.mx=LONG_LONG_MIN;
            query(1,1,n,i,a);
           // cout<<res.mn<<" "<<res.mx<<endl;
            ans=max(ans,(res.mx-res.mn));
        }
        printf("Case %lld: %lld\n",ts,ans);
    }
}

