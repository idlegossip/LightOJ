#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct st
{
    ll ind;
};
st tree[800010];
void build(long long p, long long l, long long r)
{
    if(l==r)
    {
        tree[p].ind=0;
        return;

    }
    ll le=2*p;
    ll mid=(l+r)/2;
    build(le,l,mid);
    build(le+1,mid+1,r);
    tree[p].ind=0;
}
void push_down(ll p,ll l,ll r)
{
    ll le=2*p;
    ll x=tree[p].ind;
    if(l!=r)
    {
        if(tree[le].ind<x)
            tree[le].ind=x;
        if(tree[le+1].ind<x)
            tree[le+1].ind=x;
        tree[p].ind=0;
    }
}
void update(ll p, ll l, ll r, ll i,ll j, ll in)
{
    if(tree[p].ind)
        push_down(p,l,r);
    if(l>j||r<i)
        return;
    if(l>=i&&r<=j)
    {

        tree[p].ind=in;
        return;
    }
    ll le=2*p;
    ll mid=(l+r)/2;
    update(le,l,mid,i,j,in);
    update(le+1,mid+1,r,i,j,in);
}
map<ll,ll>mp;
ll query(long long p, long long l, long long r)
{
    if(tree[p].ind)
    {
        if(mp[tree[p].ind]==0)
        {
            mp[tree[p].ind]=1;
               //  cout<<l<<"  1   "<<r<<" "<<tree[p].ind<<endl;
            return 1;
        }
        else
        {
             // cout<<l<<"  0   "<<r<<" "<<tree[p].ind<<endl;
            mp[tree[p].ind]=1;
            return 0;
        }
    }
    if(l==r)
        return 0;
    ll le=2*p;
    ll mid=(l+r)/2;
    ll p1=query(le,l,mid);
    ll p2=query(le+1,mid+1,r);
    return p1+p2;
}
int main()
{
    ios_base::sync_with_stdio(0);
  //freopen("OutPut.text","w",stdout);
    ll t;
    scanf("%lld",&t);
    //  printf("\n");
    for(ll ts=1; ts<=t; ts++)
    {
        ll n,q;
        scanf("%lld",&n);
        build(1,1,(2*n));

        ll a,b,c,va;
        mp.clear();
        for(ll i=1; i<=n; i++)
        {
            scanf("%lld %lld",&b,&c);
            update(1,1,2*n,b,c,i);
        }
        a=query(1,1,(2*n));

        printf("Case %lld: %lld\n",ts,a);
    }



}

