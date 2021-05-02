#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll y;
ll GCD(ll a,ll b)
{
    return (b == 0) ? a:GCD(b,a%b);
}
struct st
{
    ll data;
    ll lazy;

};
st tree[800000];
void build(ll p,ll l,ll r)
{
    if(l==r)
    {
        tree[p].data=0;
        tree[p].lazy=-1;
        return;
    }
    ll le=2*p;
    ll mid=(l+r)/2;
    build(le,l,mid);
    build(le+1,mid+1,r);
    tree[p].data=0;
    tree[p].lazy=0;
}
void push_down(ll p,ll l,ll r,ll x)
{
    ll le=2*p;
    tree[p].data=(r-l+1)*x;
    if(l!=r)
    {
        tree[le].lazy=x;
        tree[le+1].lazy=x;
    }
    tree[p].lazy=-1;
}
void update(ll p,ll l,ll r,ll i,ll j,ll x)
{
      if(tree[p].lazy>-1)
    push_down(p,l,r,tree[p].lazy);
    if(l>j||r<i)
        return;
    if(l>=i&&r<=j)
    {
        push_down(p,l,r,x);
        return;
    }
    ll le=2*p;
    ll mid=(l+r)/2;
    update(le,l,mid,i,j,x);
    update(le+1,mid+1,r,i,j,x);
    tree[p].data=tree[le].data+tree[le+1].data;
}
ll query(ll p,ll l,ll r,ll i,ll j)
{
    if(tree[p].lazy>-1)
    push_down(p,l,r,tree[p].lazy);
    if(l>j||r<i)
        return 0;
    if(l>=i&&r<=j)
    {
        y+=(r-l+1);
        return  tree[p].data;
    }
    ll le=2*p;
    ll mid=(l+r)/2;
    ll p1=query(le,l,mid,i,j);
    ll p2=query(le+1,mid+1,r,i,j);
    tree[p].data=tree[le].data+tree[le+1].data;
    return p1+p2;
}
int main()
{
   // freopen("OutPut.text","w",stdout);
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
            scanf("%lld",&a);
            ll res1=0,res2=0;

            if(a==1)
            {
                scanf("%lld %lld %lld ",&b,&c,&a);
                update(1,1,n,b+1,c+1,a);
            }
            else
            {
                scanf("%lld %lld",&b,&c);
                y=0;
                ll x=query(1,1,n,b+1,c+1);
                if(x%y==0)
                {
                    printf("%lld\n",x/y);
                    continue;
                }
                //  cout<<x<<" "<<y<<endl;
                ll f=1;
                while(1)
                {
                    ll z=GCD(x,y);
                    if(z==1)
                        break;
                    x/=z;
                    y/=z;
                }


                printf("%lld/%lld\n",x,y);
            }
        }
    }


}
