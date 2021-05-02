#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
         ll n;
         cin>>n;
         if(n<=10)
            cout<<"0 "<<n<<endl;
         else
            cout<<"10 "<<n-10<<endl;
    }
}

