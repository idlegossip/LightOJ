#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll len = 1e5+7;
ll fail[len+1];
void fail_func(string pat,ll n)
{
    fail[0] = 0;
    fail[1] = 0;
    for(int i = 1; i < n; i++)
    {
        int j = fail[i];
        while(1)
        {
            if(pat[j] == pat[i])
            {
                fail[i+1] = j+1;
                break;
            }
            if(j==0)
            {
                fail[i+1] = 0;
                break;
            }
            j = fail[j];
        }
    }
}
bool kmp_match(string s,string pat,ll n,ll len)
{
    ll j = 0;
    for(ll i = 0; i < n; i++)
    {
        if(s[i] == pat[j])
        {
            j++;
        }
        else
        {
            while(j > 0 and pat[j] !=s[i])
            {
                j = fail[j];
            }
        }
        if(j==len)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s,pat;
    cin>>s>>pat;
    ll n =s.size();
    ll len = pat.size();
    fail_func(pat,len);
    bool f = kmp_match(s,pat,n,len);
    if(f)
    {
        cout<<"Ok\n";
    }
    else
    {
        cout<<"No\n";
    }

}
