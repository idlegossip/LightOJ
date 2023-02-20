#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
int fail[N+1];
void fail_func(string pat,int n)
{
    fail[0] = -1;
    fail[1] = 0;
    for(int i = 1 ; i < n; i++)
    {
        int j = fail[i];
        while(1)
        {
            if(pat[i]==pat[j])
            {
                fail[i+1] = j+1;
                break;
            }
            if(j==-1)
            {
                fail[i+1] = 0;
                break;
            }
            j = fail[j];
        }
    }
}
ll kmp_match(string s,string pat, ll n,ll len)
{
    ll ans = 0;
    int j = 0;
    for(int i = 0; i <n; i++)
    {
        if(s[i]== pat[j])
        {
            j++;
        }
        else
        {
            while(j > -1 and pat[j]!=s[i])
                j = fail[j];
            j++;
        }
        if(j==len)
        {
            ans++;
            j = fail[j];
            //cout<<j<<'\n';
        }
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
        string s,pat;
        cin>>s>>pat;
        ll n = s.size();
        ll len = pat.size();
        fail_func(pat,len);
        ll ans = kmp_match(s,pat,n,len);
        cout<<"Case "<<++ts<<": "<<ans<<'\n';

    }
}
