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
       printf("Case %lld: ",ts);
        ll s;
        cin>>s;
        ll i=sqrtl(s);
        if(i*i!=s)
            i++;

        if(i%2==0)
        {
            ll x=(i-1)*(i-1);
            //x++;
            ll y=i*i;
            ll a=s-x;
            ll b=y-s;
            if(a<=i)
                cout<<a<<" "<<i<<endl;
            else
                cout<<i<<" "<<b+1<<endl;
        }
        else
        {
            ll x=(i-1)*(i-1);
            ll y=i*i;
            ll a=s-x;
            ll b=y-s;
            if(a<=i)
                cout<<i<<" "<<a<<endl;
            else
                cout<<b+1<<" "<<i<<endl;
        }
    }
}
