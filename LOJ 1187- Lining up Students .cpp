#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
int main()
{
    ll t;
    cin>>t;
    ll ts=0;
    while(t--)
    {
        ts++;
        ll n;
        cin>>n;
        vector<ll>v;
        ll a;
        o_set<ll>st;
        for(ll i=0;i<n;i++)
        {
            cin>>a;
            v.push_back(a);
            st.insert(i+1);
        }
        for(ll i=n;i>1;i--)
        {
            a=v[i-1];
            a=i-a;
            auto x = st.find_by_order(a-1);
            st.erase(st.find(*x));
        }
        cout<<"Case "<<ts<<": ";
        cout<<*st.find_by_order(0)<<endl;
    }

}
