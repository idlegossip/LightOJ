#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct st
{
    ll val;
    ll lazy;

};
st tree[500000];
ll ar[100010];
void build(long long p, long long l, long long r)
{
    if(l==r)
    {
        tree[p].val=0;
        tree[p].lazy=0;
        return;
    }
    ll le=2*p;
    ll mid=(l+r)/2;
    build(le,l, mid);
    build(le+1, mid+1,r);
    tree[p].val=tree[le].val+tree[le+1].val;
    tree[p].lazy=0;

}
void push_down(ll p,ll l,ll r)
{
    ll  le=2*p;
    ll  cur=tree[p].lazy;
    tree[p].val+=(r-l+1)*cur;
    if(l!=r)
    {
        tree[le].lazy+=cur;
        tree[le+1].lazy+=cur;

    }
    tree[p].lazy=0;
}
void update(long long p, long long l, long long r, long long i,ll j, long long x)
{
    if(tree[p].lazy)
        push_down(p,l,r);
    if(l>j||r<i)
        return;
    if(l>=i&&r<=j)
    {
        tree[p].lazy+=x;
        push_down(p,l,r);
        return;
    }
    ll le=2*p;
    ll mid=(l+r)/2;
    update(le,l,mid,i,j,x);
    update(le+1,mid+1,r,i,j,x);
    tree[p].val=tree[le].val+tree[le+1].val;
}
ll query(long long p, long long l, long long r, long long i, long long j)
{
    if(tree[p].lazy)
        push_down(p,l,r);
    if(l>j||r<i)
        return 0;
    if(l>=i&&r<=j)
    {
        return tree[p].val;
    }
    ll le=2*p;
    ll mid=(l+r)/2;
    ll p1=query(le,l,mid,i,j);
    ll p2= query(le+1,mid+1,r,i,j);
    tree[p].val=tree[le].val+tree[le+1].val;
    return p1+p2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    scanf("%lld",&t);
    //  printf("\n");
    for(ll ts=1; ts<=t; ts++)
    {
        ll n,q;
        scanf("%lld %lld",&n,&q);
        ll ar[n+10];
        build(1,1,n);
        printf("Case %lld:\n",ts);
        ll a,b,c,va;
        for(ll i=1; i<=q; i++)
        {
                  scanf("%lld",&c);
                  if(c==0)
                  {
                          scanf("%lld %lld %lld",&b,&c,&va);
                          update(1,1,n,b+1,c+1,va);
                  }
                  else
                  {
                         scanf("%lld %lld",&b,&c);
                         a=query(1,1,n,b+1,c+1);
                        printf("%lld\n",a);
                  }

        }

    }
}


