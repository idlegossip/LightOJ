#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9;
ll bigmod(ll b,ll p)
{
    ll ans = 1;
    while(p)
    {
        if(p&1)
        {
            ans = (b *  ans % mod);
        }
        p >>= 1;
        b = b * b % mod;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    ll ts = 0;
    while(t--)
    {
        ll n,m,k,b;
        cin>>n>>m>>k>>b;
        vector<ll>g[m+1];
        ll x,y;
        vector<ll>v;
        ll cnt = m;
        for(int i = 0; i < b; i++)
        {
            cin>>x>>y;
            if(x==1)
               cnt--;
            if(g[y].size()==0)
                v.push_back(y);
            g[y].push_back(x);
        }
        for(int i = 0 ; i < v.size(); i++)
        {
            sort(g[v[i]].begin(),g[v[i]].end());
        }
        for(int i = 0; i < v.size(); i++)
        {
            for(ll j = 1; j < g[v[i]].size(); j++)
            {
                if((g[v[i]][j]-g[v[i]][j-1]) > 1)
                {
                    cnt++;
                }
            }
            ll sz = g[v[i]].size();
            if(sz > 0 and g[v[i]][sz-1] != n)
            {
                cnt++;
            }
        }
        ll tot = n * m;
        tot -= (cnt+b);
        ll ans = bigmod(k,cnt);
        ans %= mod;
        ll tmp =ans;
        ans =(ans *  bigmod(k-1,tot)) % mod;
        //cout<<ans<<" "<<ans / tmp<<'\n';
        cout<<"Case "<<++ts<<": "<<ans<<'\n';
    }
}
