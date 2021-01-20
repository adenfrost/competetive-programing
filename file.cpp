#pragma GCC optimize("Ofast") 
#include <bits/stdc++.h> // -_-bruh u copying mah code?!
///#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp> 
//#include <ext/pb_ds/detail/standard_policies.hpp> 
using namespace std;
#define lli long long int
#define i int
#define cr char
#define f float
#define uns unsigned
#define input(x) cin >>x
#define output(x) cout <<x
#define space() cout <<endl
#define gc getchar_unlocked 
#define vi(x) vector<x>
#define loop(I,N) for(lli I=0;I<N;I++)
#define pb push_back 
#define mp make_pair 
#define F first 
#define S second 
#define PI 3.1415926535897932384626 
const i mod = 1000000007; 
#define Fill(a,v) memset(a,v,sizeof(a)) 
#define you -> Noob
//written by Aden Frost
void fastaf(void)
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
}
lli A[100][100];
void flood_fill(lli N,lli M,lli x,lli y,lli k,lli colour)
{
    if(x>=N)
        return;
    if(y>=M)
        return;
    else
    {
        A[x][y]=k;
        if(A[x+1][y]==colour)
        {
            flood_fill(N,M,x+1,y,k,colour);
        }
        if(A[x][y+1]==colour)
        {
            flood_fill(N,M,x,y+1,k,colour);
        }
        if(A[x-1][y]==colour)
        {
            flood_fill(N,M,x-1,y,k,colour);
        }
        if(A[x][y-1]==colour)
        {
            flood_fill(N,M,x,y-1,k,colour);
        }
        return;
    }
    
}
void solve(void)
{
    lli N,M;
    input(N)>>M;
    for(lli I=0;I<N;I++)
    {
        for(lli j=0;j<M;j++)
        {
            input(A[I][j]);
        }
    }
    lli x,y,k;
    input(x)>>y>>k;
    flood_fill(N,M,x,y,k,A[x][y]);
    for(lli I=0;I<N;I++)
    {
        for(lli j=0;j<M;j++)
        {
            output(A[I][j])<<" ";
        }
        //space();
    }
}
int main()
{
    fastaf();
    i T;
    input (T);
    while(T--)
    {
       solve();
       space();
    }
    return 0;
}