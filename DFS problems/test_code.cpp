#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100001];
int visited[100001]={0};
int a[100001];
int c[100001]={0};
int k=0,ans=0,m;

void dfs(int n)
{
    visited[n]=1;

    for(int i=0;i<adj[n].size();i++)
    {
        if(!visited[adj[n][i]])
        {
            visited[adj[n][i]]=1;
              c[adj[n][i]]=c[n];
        if(a[adj[n][i]])
        c[adj[n][i]]++;
         else
         c[adj[n][i]]=0;
         if(c[adj[n][i]]>m)
         continue;
         else
         dfs(adj[n][i]);
        }
    }
    if(adj[n].size()==1 && c[n]<=m && n!=1)
    ans++;

}
int main()
{
    long long n,i,j,l;
    cin>>n>>m;
   for(i=1;i<=n;i++)
   cin>>a[i];
   for(i=0;i<n-1;i++)
   {
       cin>>j>>k;
       adj[j].push_back(k);
       adj[k].push_back(j);
   }
   k=0;
   c[1]=a[1];
   dfs(1);
   cout<<ans;
    return 0;
}
