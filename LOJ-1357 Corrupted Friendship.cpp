#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5+7;
ll col[N+1];
bool vis[N+ 1];
vector<ll>g[N+1];
ll ans = 0;
ll n;
void go(ll u,ll p,ll cnt)
{
    vis[u] = 1;
    col[u] = 1;
    for(auto ch : g[u])
    {
        if(ch != p and !vis[ch])
        {
            go(ch,u,cnt+1);
            col[u] += col[ch];
        }
    }
    ans += (n - (cnt+col[u]));
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
        cin>>n;
        ll a;
        ll b;
        for(int i = 0; i< n-1; i++){
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        ans = 0;
        go(1,-1,0);

        cout<<"Case "<<++ts<<": "<<n-1<<" "<<ans/2<<'\n';
        for(int i = 1; i <= n; i++)
        {
            vis[i] = 0;
            g[i].clear();
            col[i] = 0;
        }


    }
}

