#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct st
{
    ll data;
    ll tog;
};
st tree[800000];
string str;
void build(ll l,ll r,ll p)
{
    if(l>r)
        return;
    if(l==r)
    {
        tree[p].tog=0;
        return;
    }
    ll le=2*p;
    ll mid=(l+r)/2;
    build(l,mid,le);
    build(mid+1,r,le+1);
    tree[p].tog=0;

}
void update(ll p,ll l,ll r,ll i,ll j)
{
      if(l>j||r<i)
            return;
      if(l>=i&&r<=j)
      {
            tree[p].tog^=1;
            return;
      }
      ll le=2*p;
      ll mid=(l+r)/2;
      update(le,l,mid,i,j);
      update(le+1,mid+1,r,i,j);

}
ll query(ll p,ll l,ll r,ll i,ll pr)
{
      if(l>i||r<i)
            return 0;
      if(l==r&&l==i)
      {
            if((tree[p].tog+pr)%2)
            {
                  if(str[i-1]=='0')
                        return 1;
                  else
                        return 0;
            }
            else
            {
                if(str[i-1]=='1')
                        return 1;
                  else
                        return 0;
            }
      }
      ll le=2*p;
      ll mid=(l+r)/2;
      ll p1=query(le,l,mid,i,pr+tree[p].tog);
      ll p2=query(le+1,mid+1,r,i,pr+tree[p].tog);
      return p1+p2;

}
int main()
{
      ll t;
      cin>>t;
      for(ll ts=1;ts<=t;ts++)
      {
              ll n,q;
              cin>>str;
              n=str.size();
              build(1,n,1);
              cin>>q;
              printf("Case %lld:\n",ts);
              char ch;
              ll a,b;
              while(q--)
              {
                    cin>>ch;
                    if(ch=='Q')
                    {
                          cin>>a;
                          cout<<query(1,1,n,a,0)<<endl;
                    }
                    else
                    {
                          cin>>a>>b;
                          update(1,1,n,a,b);
                    }

              }

      }

}
