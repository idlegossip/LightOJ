#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll tree[1000005];
void update(ll p,ll l,ll r,ll i,ll val)
{
    //
    if(l>i||r<i)
        return  ;
    if(l==i&&r==i)
    {

        tree[p]=val;
        //cout<<" p "<<tree[p]<<endl;
        return  ;
    }
    ll le=2*p;
    ll mid=(l+r)/2;
    update(le,l,mid,i,val);
    update(le+1,mid+1,r,i,val);
    tree[p]=tree[le]+tree[le+1];
   // cout<<l<<" l r i "<<r<<" "<<tree[p]<<endl;
}
void build(ll p,ll l,ll r)
{
    if(l==r)
    {
        tree[p]=1;
        return  ;
    }
    ll le=2*p;
    ll mid=(l+r)/2;
    build(le,l,mid);
    build(le+1,mid+1,r);
    tree[p]=tree[le]+tree[le+1];
    // cout<<l<<" l r  "<<r<<" "<<tree[p]<<endl;
}
ll query(ll p,ll l,ll r,ll i,ll j)
{
    if(l>j||r<i)
        return 0;
    if(l>=i&&r<=j)
        return tree[p];
    ll le=2*p;
    ll mid=(l+r)/2;
    ll p1= query(le,l,mid,i,j);
    ll p2=query(le+1,mid+1,r,i,j);
    return p1+p2;

}
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("OutPut.text","w",stdout);
    ll t;
    cin>>t;
    for(ll ts=1; ts<=t; ts++)
    {
        ll n,a,q;
        cin>>n>>q;
        vector<ll>vp;
        for(ll i=1; i<=n; i++)
        {
            cin>>a;
            vp.push_back(a);
        }
        build(1,1,200000);
        printf("Case %lld:\n",ts);
        char ch;
        for(ll i=0; i<q; i++)
        {

            cin>>ch;
            ll ans=-1;
            ll l=1,r=n;
            if(ch=='c')
            {
                cin>>a;

                while(l<=r)
                {
                    ll mid=(l+r)/2;
                    ll x=query(1,1,200000,1,mid);
                    if(x>=a)
                    {
                        r=mid-1;
                        ans=mid;
                    }
                    else
                        l=mid+1;
                }
                if(ans>=0)
                {
                    printf("%lld\n",vp[ans-1]);
                    update(1,1,200000,ans,0);
                }
                else
                    printf("none\n");
            }
            else
            {
                n++;
                cin>>a;
                vp.push_back(a);
            }

        }
    }
}
