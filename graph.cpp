#pragma GCC optimize("Ofast") 
#include <bits/stdc++.h> // -_-bruh u copying mah code?!
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp> 
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
void BFS(std::unordered_map<i,list<i>> &graphh,i s)
{
    bool visited[graphh.size()];
    Fill(visited,false);
    queue<i> queue;
    visited[s]=true;
    queue.push(s);
    list<i>::iterator I;
    while(!queue.empty())
    {
        s=queue.front();
        output(s)<<" ";
        queue.pop();
        for(I=graphh[s].begin();I!=graphh[s].end();I++)
        {
            if(visited[*I]==false)
            {
                visited[*I]=true;
                queue.push(*I);
            }
        }
    }
}
void DFS_Utill(std::unordered_map<i,list<i>> &graphh,i s,bool visited[])
{
    output(s)<<" ";
    visited[s]=true;
    list<i>::iterator I;
    for(I=graphh[s].begin();I!=graphh[s].end();I++)
    {
        if(visited[*I]==false)
            DFS_Utill(graphh,*I,visited);
    }
}
void DFS(std::unordered_map<i,list<i>> &graphh,i s)
{
    bool visited[graphh.size()];
    Fill(visited,false);
    DFS_Utill(graphh,s,visited);
}
void DFS_iterative(std::unordered_map<i,list<i>> &graphh,i s)
{
    bool visited[graphh.size()];
    Fill(visited,false);
    list<i>::iterator I;
    stack<i> stack;
    stack.push(s);
    while(!stack.empty())
    {
        s=stack.top();
        stack.pop();
        if(visited[s]==false)
        {
            output(s)<<" ";
            visited[s]=true;
        }
        for(I=graphh[s].begin();I!=graphh[s].end();I++)
        {
            if(visited[*I]==false)
            {
                stack.push(*I);
            }
        }
    }
}
void Topological_sort_Util(std::unordered_map<i,list<i>> &graphh,i s,bool visited[],std::stack<i> &stack)
{
   visited[s]=true;
   list<i>::iterator I;
   for(I=graphh[s].begin();I!=graphh[s].end();I++)
   {
       if(visited[*I]==false)
            Topological_sort_Util(graphh,*I,visited,stack);
   }
   stack.push(s);
}
void Topological_sort(std::unordered_map<i,list<i>> &graphh)
{
    bool visited[graphh.size()];
    Fill(visited,false);
    stack<i> stack;
    for(int I=0;I<graphh.size();I++)
    {
        if(visited[I]==false)
            Topological_sort_Util(graphh,I,visited,stack);
    }
    while(!stack.empty())
    {
        output(stack.top())<<" ";
        stack.pop();
    }
}
bool iscyclic_directed_util(std::unordered_map<i,list<i>> &graphh,i s,bool visited[],bool recstack[])
{
    if(visited[s]==false)
    {
        visited[s]=true;
        recstack[s]=true;
        list<i>::iterator I;
        for(I=graphh[s].begin();I!=graphh[s].end();I++)
        {
            if(visited[*I]==false&&iscyclic_directed_util(graphh,*I,visited,recstack))
                return true;
            else if(recstack[*I]==true)
                return true;
        }
    }
    recstack[s]=false;
    return false;
}
bool iscyclic_directed(std::unordered_map<i,list<i>> &graphh)
{
    bool visited[graphh.size()],recstack[graphh.size()];
    Fill(visited,false);
    Fill(recstack,false);
    for(i I=0;I<graphh.size();I++)
    {
        if(iscyclic_directed_util(graphh,I,visited,recstack))
            return true;
    }
    return false;
}
bool iscyclic_undirected_util(std::unordered_map<i,list<i>> &graphh,i s,bool visited[],i parent)
{
   visited[s]=true;
   list<i>::iterator I;
   for(I=graphh[s].begin();I!=graphh[s].end();I++)
   {
        if(visited[*I]==false)
        {
            if(iscyclic_undirected_util(graphh,*I,visited,s))
                return true;
        }
        else if(*I!=parent)
            return true;
   }
   return false;
}
bool iscyclic_undirected(std::unordered_map<i,list<i>> &graphh)
{
    bool visited[graphh.size()];
    Fill(visited,false);
    for(i I=0;I<graphh.size();I++)
    {
        if(visited[I]==false)
        {
            if(iscyclic_undirected_util(graphh,I,visited,-1))
                return true;
        }
    }
    return false;
}
i findmother_vertex(std::unordered_map<i,list<i>> &graphh)
{
    bool visited[graphh.size()];
    Fill(visited,false);
    i v=0;
    for(i I=0;I<graphh.size();I++)
    {
        if(visited[I]==false)
        {
            DFS_Utill(graphh,I,visited);
            v=I;
        }
    }
    Fill(visited,false);
    DFS_Utill(graphh,v,visited);
    for(i I=0;I<graphh.size();I++)
    {
        if(visited[I]==false)
            return -1;
    }
    return v;
}
void solve(void)
{
    unordered_map<i,list<i>> graphh;//graph having same weighted edges or no weighted
    unordered_map<i,list<pair<i,i>>> graphh1;//graph havinng weighted edges
    graphh[0].pb(1);
    graphh[0].pb(2);
    graphh[1].pb(3);
    graphh[4].pb(1);
    graphh[6].pb(4);
    graphh[5].pb(6);
    graphh[5].pb(2);
    graphh[6].pb(0);
    //BFS(graphh,2);
    space();
    //DFS_iterative(graphh,2);
    space();
    //DFS(graphh,2);
    space();
    //Topological_sort(graphh);
    space();
    //iscyclic_directed(graphh)?output("yes!"):output("no!");
    //iscyclic_undirected(graphh)?output("yes!"):output("no!");
    //output(findmother_vertex(graphh))<<"is a mother vertex!";
}
int main()
{
    fastaf();
    solve();
    space();
    return 0;
}


