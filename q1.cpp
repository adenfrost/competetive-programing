/*
    authored by
    aden_frost
    on 19-01-2021
    Happy New Year!!
    2021
    Go Corona Corona Go!!
*/
#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
#define lli long long int
#define MOD1 998244353
#define MOD 1000000007
using namespace std;
void fastaf(void)
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
}
bool prime[10000000];
void sieve(void)
{
    memset(prime,true,sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i<10000000;i++)
    {
        if(prime[i])
        {
            for(int j=2;j<10000000;j++)
            {
                if(i*j<1e7)
                    prime[i*j]=false;
                else
                    break;
            }
        }
    }
}
void solve(void)
{
    lli d;
    cin>>d;
    lli ans=1;
    ans+=d;
    for(lli i=ans;;i++)
        if(prime[i])
        {
            ans=i;
            break;
        }
    lli ans2=ans+d;
    for(lli i=ans2;;i++)
    {
        if(prime[i])
        {
            ans2=i;
            break;
        }
    }
    cout<<ans*ans2;
}
/*
- - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/
int main()
{
    fastaf();
    sieve();
    int Testcases;
    cin>>Testcases;
    while(Testcases--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}