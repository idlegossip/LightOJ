#include<bits/stdc++.h>
using namespace std;
#define ll long long
void fail_func(string pat,int len,int dp[],int fail[])
{
    fail[0] = -1;
    fail[1] = 0;
    dp[0] = 1;
    for(int i = 1; i < len; i++)
    {
        int j = fail[i];
        while(1)
        {
            if(pat[j]==pat[i])
            {
                fail[i+1] = j+1;
                dp[i] = dp[j]+1;
                break;
            }
            if(j==-1)
            {
                dp[i] = 1;
                fail[i+1] = 0;
                break;
            }
            j = fail[j];
        }
    }
}
void kmp_match(string s,string pat,int n,int len,int dp[],int fail[],int mat[])
{
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(pat[j]==s[i])
        {
            mat[i] = dp[j];
            j++;
        }
        else
        {
            while(j > -1 and s[i] != pat[j])
                j = fail[j];
            if(j > -1)
                mat[i] = dp[j];
            else
            {
                mat[i] = 0;
            }
            j++;
        }
        if(j==len) j = fail[j];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    ll ts= 0;
    cin>>t;
    while(t--)
    {
        string s,pat;
        cin>>s>>pat;
        ll n = s.size();
        ll len = pat.size();

        int dp[len+2],fail[len+2],mat[n+1];
        int dp1[len+2],fail1[len+2],mat1[n+1];


        fail_func(pat,len-1,dp,fail);
        kmp_match(s,pat,n,len-1,dp,fail,mat);

        reverse(pat.begin(),pat.end());
        reverse(s.begin(),s.end());

        fail_func(pat,len-1,dp1,fail1);
        kmp_match(s,pat,n,len-1,dp1,fail1,mat1);

        ll ans = 0;
        for(int i = 0; i < n-1; i++)
        {
            //cout<<mat[i]<<" "<<mat1[n-i-2]<<'\n';
            ans += (1ll * mat[i] * mat1[n-i-2]);
        }
        cout<<"Case "<<++ts<<": "<<ans<<'\n';
    }
}
