#include<bits/stdc++.h>
#define S 1000000
using namespace std;
bool isCyclic(int V, vector<int> adj[]);
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

    }
    cout<<isCyclic(n,adj)<<endl;


}


return 0;
}

void dfs_in_one_node(vector<int>g[], int N, int node,vector<bool> &visited,bool &ans,int start_node){
    visited[node]=true;

    for(int i=0;i<g[node].size();i++){
        if(visited[g[node][i]]==0){

            dfs_in_one_node(g,N,g[node][i],visited,ans,start_node);
        }
        else{
            //cout<<"here "<<node<<endl;
            if(g[node][i]==start_node){
                ans=true;
            }

        }
    }

}


bool isCyclic(int V, vector<int> adj[])
{


    bool ans=false;

    for(int i=0;i<V;i++){
        vector<bool>visited(V,0);
        dfs_in_one_node(adj,V,i,visited,ans,i);

    }
    return ans;
}
