#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    ll ts = 0;
    while(t--)
    {
        ll n,m,q;
        //cout<<'\n';
        cin>>n>>m>>q;
        vector<ll>x(n+1,0),y(m+1,0);
        ll a,b,c;
        ll sum = 0,sum1 = 0;
        for(int i = 0; i < q; i++){
            cin>>a>>b>>c;
            sum+= c;
            sum1+= c;
            x[a] += c;
            y[b] += c;
        }
        ll mid = (sum+1)/2;

        ll ansx,ansy;
         sum = 0;
        for(int i = 0; i <= n; i++){
            sum+=x[i];
            if(sum >= mid){
                ansx = i;
                break;
            }
        }
        //mid = sum1/2;
        sum = 0;
        for(int i = 0; i <= m; i++){
            sum+=y[i];
            if(sum >= mid){
                ansy = i;
                break;
            }
        }
        cout<<"Case "<<++ts<<": "<<ansx<<' '<<ansy<<'\n';
    }
}

