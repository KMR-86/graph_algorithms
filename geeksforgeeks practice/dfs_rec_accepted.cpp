#include<bits/stdc++.h>
#define S 1000000
using namespace std;
vector <int> dfs(vector<int> g[], int N);
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
    vector<int>res=dfs(adj,n);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

}


return 0;
}

void dfs_in_one_node(vector<int>g[], int N, vector<int>&ans,int node,vector<bool> &visited){
    visited[node]=true;

    for(int i=0;i<g[node].size();i++){
        if(visited[g[node][i]]==0){
            ans.push_back(g[node][i]);
            dfs_in_one_node(g,N,ans,g[node][i],visited);
        }
    }

}
vector <int> dfs(vector<int> g[], int N)
{

    // Your code here
    vector<bool>visited(N,0);
    vector<int>ans;
    ans.push_back(0);
    for(int i=0;i<N;i++){
        if(visited[i]==0){
            dfs_in_one_node(g,N,ans,i,visited);
        }
    }
    return ans;

}
