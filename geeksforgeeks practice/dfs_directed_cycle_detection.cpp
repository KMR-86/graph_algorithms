#include<bits/stdc++.h>
#define S 1000000
using namespace std;
bool isCyclic(vector<int> g[], int V);
bool visited[1000];
void dfs_node(vector<int> g[], int V,int node){
    cout<<node<<" ";
    visited[node]=1;
    for(int i=0;i<g[node].size();i++){
        if(visited[g[node][i]]==0){
            visited[g[node][i]]=1;
            dfs_node(g,V,g[node][i]);
        }


    }
}
bool isCyclic(vector<int> g[], int V)
{
   // Your code here
   memset(visited,0,sizeof(visited[0])*1000);
   for(int i=0;i<V;i++){
       if(visited[i]==0){

           dfs_node(g,V,i);
       }
   }



}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

int tc;
cin>>tc;
while(tc--){
    int n,e;
    cin>>n>>e;
    vector<int>adj[n];
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    isCyclic(adj,n);

}


return 0;
}
