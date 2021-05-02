#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct st
{
    ll lazy;
    ll one;
    ll two;
    ll three;
};
st tree[800000];
ll ar[300000];
void build(ll p,ll l,ll r)
{
    tree[p].one=0;
    tree[p].two=0;
    tree[p].three=(r-l+1);
    if(l>r)
        return;
    if(l==r)
    {
        tree[p].three=1;
        tree[p].lazy=0;
        return;
    }
    ll le=2*p;
    ll mid=(l+r)/2;
    build(le,l,mid);
    build(le+1,mid+1,r);
    tree[p].lazy=0;
}
void ss(ll p,ll l,ll r)
{
    ll le=2*p;
    ll a=tree[p].lazy;
    ll x=a;
    a%=3;
    if(a==1)
    {
        ll b=tree[p].one;
        ll c=tree[p].two;
        ll d=tree[p].three;
        tree[p].one=d;
        tree[p].two=b;
        tree[p].three=(r-l+1)- tree[p].one-tree[p].two;
    }
    else if(a==2)
    {
        ll b=tree[p].one;
        ll c=tree[p].two;
        ll d=tree[p].three;
        tree[p].one=c;
        tree[p].two=d;
        tree[p].three=(r-l+1)- tree[p].one-tree[p].two;
    }
    if(l!=r)
    {
        tree[le].lazy=( tree[le].lazy+a)%3;
        tree[le+1].lazy=( tree[le+1].lazy+a)%3;
    }
    tree[p].lazy=0;

}
void update(ll p,ll l,ll r,ll i,ll j)
{
    ss(p,l,r)   ;
    if(l>j||r<i)
        return;
    if(l>=i&&r<=j)
    {
           tree[p].lazy++;
        ss(p,l,r)   ;
        return ;
    }
    ll le=2*p;
    ll mid=(l+r)/2;
    update(le,l,mid,i,j);
    update(le+1,mid+1,r,i,j);
    tree[p].one= tree[le].one+ tree[le+1].one;
    tree[p].two= tree[le].two+ tree[le+1].two;
    tree[p].three= tree[le].three+ tree[le+1].three;

}
ll query(ll p,ll l,ll r,ll i,ll j)
{
    ss(p,l,r) ;
    if(l>j||r<i)
        return 0;
    if(l>=i&&r<=j)
    {
        return tree[p].three;
    }
    ll le=2*p;
    ll mid=(l+r)/2;
    ll p1=query(le,l,mid,i,j);
    ll p2=query(le+1,mid+1,r,i,j);
    tree[p].one= tree[le].one+ tree[le+1].one;
    tree[p].two= tree[le].two+ tree[le+1].two;
    tree[p].three= tree[le].three+ tree[le+1].three;
    return p1+p2;
}
int main()
{
    ll t;
    scanf("%lld",&t);
    for(ll ts=1; ts<=t; ts++)
    {
        ll n,q;
        scanf("%lld %lld",&n,&q);
        build(1,1,n);
        printf("Case %lld:\n",ts);
        while(q--)
        {
            ll a,b,c;
            scanf("%lld",&c);
            if(c==1)
            {
                scanf("%lld %lld",&a,&b);
                printf("%lld\n",query(1,1,n,a+1,b+1));
            }
            else
            {
                scanf("%lld %lld",&a,&b);
                update(1,1,n,a+1,b+1);
            }
        }


    }
}
