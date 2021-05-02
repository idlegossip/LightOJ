
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
ll dp1[1000] [1000];
ll res[2000];
string s,s1;
ll lcs(long long i, long long j,ll pa)
{
      if(i>=s.size()||j>=s1.size())
            return 0;
      if(dp1[i][j]!=-1)
            return dp1[i][j];
            ll ans=0;
      if(s[i]==s1[j])
      {
            ans=1+lcs(i+1,j+1,i);
              res[i]=pa;
      }
      else
      {
            ll x=lcs(i+1,j,pa);
            ll y=lcs(i,j+1,pa);
            ans=max(x,y);
      }
      dp1 [i][j]=ans;
      return ans;

}




int main()
{
    ll t;
    cin>>t;
    ll ts=0;
    while(t--)
    {
        ts++;



        cin>>s>>s1;
        memset(dp1,-1,sizeof(dp1));
        memset(res,-2,sizeof(res));

        printf("Case %lld: ",ts);
        ll a=lcs(0,0,-1);
        if(a)
        {
             for(ll i=0;i<s.size();i++)
             {
                   if(res[i]==-1)
                   {
                         ll x=i
                         while(res[])
                         cout<<s[res[i]];
                   }

             }

        }
        else
            cout<<":(";
        cout<<endl;



    }
}


