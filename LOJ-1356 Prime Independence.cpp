#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5+7;
ll col[N+1];
bool vis[N+ 1],vis1[N+1];
vector<ll>g[N+1];
ll col1 = 0, col2 = 0;
void siv()
{
    for(int i = 2; i*i<=N; i++)
    {
        if(vis[i]) continue;
        for(int j = i * i; j<= N; j+=i)
        {
            vis[j] = true;
        }
    }
}
void go(ll u)
{
    queue<ll>pq;
    pq.push(u);
    col[u] = 1;
    while(!pq.empty())
    {
        u = pq.front();
        pq.pop();
        // cout<<u<<'\n';
        for(auto ch : g[u])
        {
            if(!vis1[ch])
            {
                col[ch] = col[u] ^ 1;
                if(col[ch])
                    col1++;
                else
                    col2++;
                vis1[ch] = 1;
                pq.push(ch);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    siv();
    cin>>t;
    ll ts = 0;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a;
        vector<ll>v,mp(N+1,0);
        for(int i = 0; i < n; i++)
        {
            cin>>a;
            mp[a]= 1;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j * j <= v[i]; j++)
            {
                if(v[i] % j==0)
                {
                    if(mp[j] and !vis[v[i]/j])
                    {
                        g[j].push_back(v[i]);
                        g[v[i]].push_back(j);
                    }
                    if(mp[v[i]/j] and !vis[j])
                    {
                        g[v[i]/j].push_back(v[i]);
                        g[v[i]].push_back(v[i]/j);
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) sort(g[v[i]].begin(),g[v[i]].end());

        ll ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(vis1[v[i]])
                continue;
            // cout<<" Call = "<<v[i]<<'\n';
            col1 = 0, col2 = 0;
            go(v[i]);
            ans += max(col1,col2);
        }
        cout<<"Case "<<++ts<<": "<<ans<<'\n';
        for(int i = 1; i <= N; i++)
        {
            vis1[i] = 0;
            g[i].clear();
            col[i] = 0;
        }
    }
}
