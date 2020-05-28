#include<bits/stdc++.h>
using namespace std;


void add_edge(vector<vector<int> > &g,int u,int v){
    g[u].push_back(v);
    g[v].push_back(u);
}
void print_graph(vector<vector <int> > g){
    for(int i=0;i<g.size();i++){
        cout<<"["<<i<<"] - > ";
        for(int j=0;j<g[i].size();j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n=10;
    vector<vector<int> > g(n);

    add_edge(g,0,5);
    add_edge(g,0,3);
    add_edge(g,0,8);
    add_edge(g,1,2);
    add_edge(g,1,6);
    add_edge(g,2,3);
    print_graph(g);
    return 0;
}
