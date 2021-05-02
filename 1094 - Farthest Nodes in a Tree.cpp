#include<bits/stdc++.h>
using namespace std;
vector<long long>adj[30010];
vector<long long>weight[30010];
long long dis[30010];
long long diameterNode;
long long visit[30010];
long long mx=0;
void dfs(long long u)
{
      visit[u]=1;
    for(long long i=0; i<adj[u].size(); i++)
    {
        long long v=adj[u][i];
        if(visit[v])
            continue;
        dis[v]=dis[u]+weight[u][i];
        dfs(v);
    }
    if(dis[u]>mx)
    {
        mx=dis[u];
        diameterNode=u;
    }
}
int main()
{
    long long t,ts=0;
    scanf("%lld",&t);
    while(t--)
    {
        ts++;
        long long n;
        scanf("%lld",&n);
        long long i,j,k;
        long long a,b,c;
        for(i=0; i<=n; i++)
            adj[i].clear(),weight[i].clear(),dis[i]=0,visit[i]=0;
        mx=0LL;
        for(i=0; i<n-1; i++)
        {
            scanf("%lld %lld %lld",&a,&b,&c);
            adj[a].push_back(b);
            adj[b].push_back(a);
            weight[a].push_back(c);
            weight[b].push_back(c);
        }
        dis[0]=0;
        dfs(0LL);
        for(i=0; i<=n; i++)
            dis[i]=0,visit[i]=0;
        mx=0LL;
        a=diameterNode;
        dis[a]=0;
        dfs(diameterNode);
        printf("Case %lld: %lld\n",ts,mx);

    }

    return 0;

}

