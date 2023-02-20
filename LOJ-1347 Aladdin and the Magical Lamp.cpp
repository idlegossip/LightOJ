#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e3+7,mod1 = 1e9+7,p1 = 277;
int hs1[N+2],hs2[N+2],hs3[N+2];
int pw[N+2],inpw[N+2];
int bigmod(int b,int p, int mod)
{
    ll ans = 1;
    while(p)
    {
        if(p&1) ans = 1LL*b * ans % mod;
        b = 1LL*b * b % mod;
        p >>= 1;
    }
    return ans;
}
void prec()
{
    int inp1=bigmod(p1,mod1-2,mod1);
    pw[0] = 1;
    inpw[0] = 1;
    for(int i = 1; i <= N; i++)
    {
        pw[i] = (1LL*pw[i-1] * p1) % mod1;
        inpw[i]= (1LL*inpw[i-1] * inp1 )% mod1;
    }
}

void build(string s1,string s2,string s3)
{
    int n1 = s1.size();
    int n2 = s2.size();
    int n3 = s3.size();
    for(int i = 0; i < n1; i++)
    {
        hs1[i] = (1LL*s1[i] * pw[i]) % mod1;
        if(i)
        {
            hs1[i]=  (hs1[i-1]+hs1[i]) % mod1;
        }
    }
    for(int i = 0; i < n2; i++)
    {
        hs2[i] = (1LL*s2[i] * pw[i]) % mod1;
        if(i)
        {
            hs2[i]=  (hs2[i-1]+hs2[i]) % mod1;
        }
    }
    for(int i = 0; i < n3; i++)
    {
        hs3[i]= (1LL*s3[i] * pw[i]) % mod1;
        if(i)
        {
            hs3[i]=  (hs3[i-1]+hs3[i]) % mod1;
        }
    }
}
int q(int l,int r,int tp)
{
    int hs = 0;
    if(tp == 1)
    {
        hs = hs1[r];
        if(l)
        {
            hs= (hs- hs1[l-1]+ mod1) % mod1;
        }
        hs = (1LL*hs* inpw[l]) % mod1;
    }
    if(tp == 2)
    {
        hs = hs2[r];
        if(l)
        {
            hs= (hs- hs2[l-1]+ mod1) % mod1;
        }
        hs = (1LL*hs* inpw[l]) % mod1;
    }
    if(tp == 3)
    {
        hs = hs3[r];
        if(l)
        {
            hs= (hs- hs3[l-1]+ mod1) % mod1;
        }
        hs = (1LL*hs* inpw[l]) % mod1;
    }
    return hs;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    int ts = 0;
    prec();
    while(t--)
    {
        int ans = 0;
        string s1,s3,s2;
        cin>>s1>>s2>>s3;
        build(s1,s2,s3);
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        int tmp1;
        int l  = 1, r = n3;
        while(l <= r)
        {
            int mid = (l + r)>>1;
            int f = 0;
            map<int,int>mp,mp1;
            for(int k = 0; k + mid <= n1; k++)
            {
               tmp1 = q(k,k+mid-1,1);
               mp[tmp1] = 1;
            }
            for(int k = 0; k + mid <= n2; k++)
            {
               tmp1 = q(k,k+mid-1,2);
               mp1[tmp1] = 1;
            }
            for(int k = 0; k + mid <= n3; k++)
            {
               tmp1 = q(k,k+mid-1,3);
              if(mp[tmp1] and mp1[tmp1]){
                f = 1;
                break;
              }
            }
            if(f)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout<<"Case "<<++ts<<": "<<ans<<'\n';
    }
}
