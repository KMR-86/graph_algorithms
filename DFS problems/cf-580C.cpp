#include<bits/stdc++.h>
using namespace std;

int n,k,cat_count=0;
int ans=0;
vector<vector<int> > g(100002);
vector<bool> cats(100002,0);
vector<bool>visited(100002,false);
void add_edge(vector<vector<int> >&g,int u , int v){
    g[u].push_back(v);
    g[v].push_back(u);
}

void dfs_one_node(int node,int limit){

    //cout<<cat_count<<endl;
    cat_count++;
    visited[node]=true;
    if(limit-cats[node]>=0){

        if(g[node].size()==1 && node!=0){ans++;}
        //cout<<node<<endl;
        for(int i=0;i<g[node].size();i++){
            if(visited[g[node][i]]==false){
                if(cats[node]==1){
                    dfs_one_node(g[node][i],limit-1);
                }
                else{
                    dfs_one_node(g[node][i],k);
                }

            }
        }
    }
    //return;

}

int main(){


cin>>n>>k;

for(int i=0;i<n;i++){
    bool t;
    cin>>t;
    cats[i]=t;
}

for(int i=0;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    add_edge(g,u-1,v-1);

}
dfs_one_node(0,k);
cout<<ans<<endl;
return 0;
}
