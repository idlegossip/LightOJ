#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
      ll t;
      cin>>t;
      for(ll ts=1;ts<=t;ts++)
      {
            string cur_p="http://www.lightoj.com/";
            string test,str;

            stack<string>b,f;
            printf("Case %lld:\n",ts);
            while(1)
            {
                   cin>>str;
                   if(str=="BACK")
                   {
                         if(b.empty())
                         {
                               cout<<"Ignored"<<endl;
                               continue;
                         }
                         f.push(cur_p);
                         cur_p=b.top();
                         cout<<cur_p<<endl;
                         b.pop();
                   }
                   else if(str=="FORWARD")
                   {
                     if(f.empty())
                         {
                               cout<<"Ignored"<<endl;
                               continue;
                         }
                         b.push(cur_p);
                         cur_p=f.top();
                          cout<<cur_p<<endl;
                         f.pop();
                   }
                   else  if(str=="VISIT")
                   {
                         cin>>test;
                         b.push(cur_p);
                         cur_p=test;
                         cout<<test<<endl;
                         while(!f.empty())
                              f.pop();

                   }
                   else
                        break;

            }




      }
}
