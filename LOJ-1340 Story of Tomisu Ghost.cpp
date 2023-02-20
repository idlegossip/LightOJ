#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5+7;
vector<ll>prime;
bool vis[N+1];
ll mod = 10000019;
ll bigmod(ll b,ll p)
{
    ll ans = 1;
    while(p)
    {
        if(p&1) ans = ans * b % mod;
        p>>=1;
        b = b * b % mod;
    }
    return ans;
}

void sive()
{
    for(int i = 2; i * i <= N; i++)
    {
        if(vis[i]) continue;
        for(int j = i * i; j<= N; j+=i) vis[j] = 1;
    }
    for(int i = 2; i <= N; i++)
    {
        if(!vis[i]) prime.push_back(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sive();
    ll t;
    cin>>t;
    ll ts = 0;
    ll sz =  prime.size();
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll ans = 0;
        for(int i = 0; i < sz and prime[i] <= n; i++)
        {
            ll cnt = 0;
            ll tmp = n;
            while(tmp)
            {
                cnt += (tmp/prime[i]);
                tmp /= prime[i];
            }
            if(cnt >= m)
            {
                if(ans==0)
                    ans = 1;
                ans *= bigmod(prime[i],cnt/m);
                ans %= mod;
            }
        }
        cout<<"Case "<<++ts<<": ";
        if(ans==0) cout<<-1<<'\n';
        else
        cout<<ans<<'\n';
    }

}
