#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct st
{
    ll val;
};

st tree[400010];
void build(long long p, long long l, long long r)
{
    if(l==r)
    {
        tree[p].val=0;
        return ;
    }
    ll le=2*p;
    ll mid=(l+r)/2;
    build(le,l,mid);
    build(le+1,mid+1,r);
    tree[p].val=0;
}
void  update(ll p, ll l, ll r, ll i,ll f)
{
    if(l>i||r<i)
        return ;
    if(l>=i&&r<=i)
    {
        if(f)
            tree[p].val++;
        else
            tree[p].val--;
        return ;
    }
    ll le=2*p;
    ll mid=(l+r)/2;
    update(le,l,mid,i,f);
    update(le+1,mid+1,r,i,f);
    tree[p].val=tree[le].val+tree[le+1].val;
}
ll   query(ll p, ll l, ll r, ll i, ll j)
{
    if(l>j||r<i)
        return 0;
    if(l>=i&&r<=j)
    {
        return  tree[p].val;
    }
    ll le=2*p;
    ll mid=(l+r)/2;
    ll p1=query(le,l,mid,i,j);
    ll p2=query(le+1,mid+1,r,i,j);
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
        for(ll i=1; i<=n; i++)
            scanf("%lld",&ar[i]);
        build(1,1,n);
        printf("Case %lld:\n",ts);
        vector<pair<ll,pair<ll,ll> > >vp;
        ll a,b,c;
        for(ll i=1; i<=q; i++)
        {
            scanf("%lld %lld",&b,&c);
            vp.push_back({c,{b,i}});
        }
        sort(vp.begin(),vp.end());
        ll ans[100010];
        ll res[q+10];
        memset(ans,-1,sizeof(ans));
        ll cur=0;
        for(ll i=1; i<=n; i++)
        {
            a=ar[i];
            if(ans[a]==-1)
            {
                update(1,1,n,i,1);
                ans[a]=i;
            }
            else
            {
                update(1,1,n,ans[a],0);
                ans[a]=i;
                update(1,1,n,i,1);
            }
           while(vp[cur].first==i)
            {
                ll b=vp[cur].second.first;
                ll ind=vp[cur].second.second;
                a=query(1,1,n,b,i);
                cur++;
                res[ind]=a;
            }
        }
        for(ll i=1; i<=q; i++)
            printf("%lld\n",res[i]);
    }
}

