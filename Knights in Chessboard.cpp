#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    ll ts=0;
    while(t--)
    {
        ts++;

        ll n,m;
        cin>>n>>m;

        printf("Case %lld: ",ts);
          ll res=0;
        if(n==1||m==1)
            res=max(n,m);
        else if(n==2||m==2)
        {
            res=(n*m)/8;
            res*=4;
            if((n*m)%8==2)
                res+=2;
            else if((n*m)%8>1)
                  res+=4;
        }
        else
        {
            res=((n*m)+1)/2;
        }
        cout<<res<<endl;
    }
}

