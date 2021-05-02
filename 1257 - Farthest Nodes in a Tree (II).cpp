#include<bits/stdc++.h>
using namespace std;
vector<long long>adj[30010];
vector<long long>weight[30010];
long long dis[30010];
long long dis1[30010];
long long dis2[30010];
long long diameterNode;
long long visit[30010];
long long mx=0;
vector<pair<long long,long long> >res;
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
void dfs1(long long u)
{
    visit[u]=1;
    for(long long i=0; i<adj[u].size(); i++)
    {
        long long v=adj[u][i];
        if(visit[v])
            continue;
        dis1[v]=dis1[u]+weight[u][i];
        dfs1(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
        printf("Case %lld:\n",ts);
        mx=0;
        dfs(0);
        for(i=0; i<=n; i++)
            dis[i]=0,visit[i]=0;
            mx=0;
        dfs(diameterNode);
        for(i=0; i<=n; i++)
            dis1[i]=0,visit[i]=0;
        dfs1(diameterNode)  ;
        for(j=0; j<n; j++)
        {
            printf("%lld\n",max(dis1[j],dis[j]));
        }
    }

    return 0;

}

