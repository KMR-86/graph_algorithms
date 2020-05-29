#include<bits/stdc++.h>
using namespace std;

add_edge(vector<vector<pair<int,int> > >&g,int u,int v,int w){
    g[u].push_back(make_pair(v,w));
    g[v].push_back(make_pair(u,w));

}

void print_graph(vector<vector<pair<int, int > > > g){
    for(int i=0;i<g.size();i++){
        cout<<"["<<i<<"] - > ";
        for(int j=0;j<g[i].size();j++){
            cout<<g[i][j].first<<" ("<<g[i][j].second<<") -> ";
        }
        cout<<endl;

    }

}

void DFS_one_node(vector<vector<pair<int,int> > >g,vector<bool>&visited,int node){
    visited[node]=true;
    cout<<node<<endl;
    for(int i=0;i<g[node].size();i++){
        if(visited[g[node][i].first]==false){

            DFS_one_node(g,visited,g[node][i].first);
        }
    }

}
void DFS(vector<vector<pair<int,int> > > g){
    vector<bool> visited(g.size(),false);
    for(int i=0;i<g.size();i++){
        if(visited[i]==false){
            DFS_one_node(g,visited,i);
        }


    }


}
int main(){
int n=10;

vector<vector<pair<int,int > > >g(n);
add_edge(g,1,5,4);
add_edge(g,1,3,6);
add_edge(g,2,1,44);
add_edge(g,3,5,44);
add_edge(g,0,9,44);
add_edge(g,9,5,44);
add_edge(g,5,4,44);
print_graph(g);
cout<<endl<<endl;

DFS(g);

return 0;
}
