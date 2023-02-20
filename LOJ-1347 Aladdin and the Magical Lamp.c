#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e3+7,mod1 = 1e9+7,mod2 = 1e9+9,p1 = 137,p2 = 277;
pair<int,int>hs1[N+1],hs2[N+1],hs3[N+1];
pair<int,int>pw[N+1],inpw[N+1];
ll bigmod(ll b,ll p, ll mod)
{
    ll ans = 1;
    while(p)
    {
        if(p&1) ans = b * ans % mod;
        b = b * b % mod;
        p >>= 1;
    }
    return ans;
}
void prec()
{
   ll inp1=bigmod(p1,mod1-2,mod1);
   ll inp2=bigmod(p1,mod2-2,mod2);
   pw[0].first = 1;
   pw[0].second = 1;

   inpw[0].first = 1;
   inpw[0].second = 1;

   for(int i = 1; i <= N; i++){
     pw[i].first = pw[i-1].first * p1 % mod1
    pw[i].second = pw[i-1].second  * p2 % mod2;

    inpw[i].first = inpw[i-1].first * inp1 % mod1
    inpw[i].second = inpw[i-1].second  * inp2 % mod2;
   }
}

void build(string s1,string s2,string s3)
{
    ll n1 = s1.size();
    ll n2 = s2.size();
    ll n3 = s3.size();
     for(int i = 0; i < n1; i++){
        hs1[i].first = s1[i] * pw[i].first % mod1;
        hs1[i].second = s1[i] * pw[i].second % mod2;

        if(i){
            hs1[i].first =  (hs1[i-1].first+hs1[i].first) % mod1;
            hs1[i].second = (hs1[i-1].second+ hs1[i].second) %mod2;
        }
     }
     for(int i = 0; i < n2; i++){
        hs[i].first = s2[i] * pw[i].first % mod1;
        hs[i].second = s2[i] * pw[i].second % mod2;

        if(i){
            hs2[i].first =  (hs2[i-1].first+hs2[i].first) % mod1;
            hs2[i].second = (hs2[i-1].second+ hs2[i].second) %mod2;
        }
     }
     for(int i = 0; i < n3; i++){
        hs3[i].first = s3[i] * pw[i].first % mod1;
        hs3[i].second = s3[i] * pw[i].second % mod2;

        if(i){
            hs3[i].first =  (hs3[i-1].first+hs3[i].first) % mod1;
            hs3[i].second = (hs3[i-1].second+ hs3[i].second) %mod2;
        }
     }
}
pair<int,int>q(ll l,ll r,ll tp)
{
    pair<int,int>hs= {0,0};
    if(tp == 1)
    {
        hs.first = hs1[r].first;
        hs.second= hs1[r].second;
        if(l){
            hs.first = (hs.first - hs1[l-1].first + mod1) % mod1;
            hs.second = (hs.second - hs1[l-1].second + mod2) % mod2;
        }
        hs.first = hs.first * inpw[l].first % mod1;
        hs.second = hs.second * inpw[l].second % mod2;

    }
     if(tp == 1)
    {
        hs.first = hs2[r].first;
        hs.second= hs2[r].second;
        if(l){
            hs.first = (hs.first - hs2[l-1].first + mod1) % mod1;
            hs.second = (hs.second - hs2[l-1].second + mod2) % mod2;
        }
        hs.first = hs.first * inpw[l].first % mod1;
        hs.second = hs.second * inpw[l].second % mod2;

    }
     if(tp == 3)
    {
        hs.first = hs3[r].first;
        hs.second= hs3[r].second;
        if(l){
            hs.first = (hs.first - hs3[l-1].first + mod1) % mod1;
            hs.second = (hs.second - hs3[l-1].second + mod2) % mod2;
        }
        hs.first = hs.first * inpw[l].first % mod1;
        hs.second = hs.second * inpw[l].second % mod2;

    }
    return hs;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    ll ts = 0;
    prec();
    while(t--)
    {
        string s1,s3,s2;
        cin>>s1>>s2>>s3;
        build(s1,s2,s3);
        ll n1 = s1.size();
        ll n2 = s2.size();
        ll n3 = s3.size();

    }
}
