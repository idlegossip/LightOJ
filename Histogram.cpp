#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
      ll t;
      cin>>t;
      for(ll ts=1;ts<=t;ts++)
      {

            stack<pair<ll,ll> >b,f;
            ll n;
            cin>>n;
            ll ar[n+10];
            ll l[n+10];
            ll r[n+10];
            for(ll i=1;i<=n;i++)
                  cin>>ar[i];
            b.push({0,0});
             for(ll i=1;i<=n;i++)
             {
                   ll a=ar[i];
                   while(!b.empty()&&a<=b.top().first)
                        b.pop();
                   l[i]=i-(b.top().second);
                  // cout<<l[i]<<" ";
                    b.push({a,i});
             }
            // cout<<endl;
           f.push({0,n+1});
            for(ll i=n;i>=1;i--)
             {
                   ll a=ar[i];
                   while(!f.empty()&&a<=f.top().first)
                        f.pop();
                   r[i]=(f.top().second)-i;
                   // cout<<r[i]<<" ";
                    f.push({a,i});
             }
             ll res=0;
               for(ll i=1;i<=n;i++)
               {
                     res=max(res,((l[i]+r[i]-1)*ar[i]));

               }


            printf("Case %lld: %lld\n",ts,res);


      }
}

