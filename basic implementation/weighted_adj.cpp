#include<bits/stdc++.h>
using namespace std;
void add_edge(vector<vector<pair<int,int > > > &g, int u,int v, int w){

    g[u].push_back(make_pair(v,w));
    g[v].push_back(make_pair(u,w));///for one directional, this line should be commented


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
int main(){
int n=10;
vector<vector <pair<int,int> > > g(n);
add_edge(g,1,2,13);
add_edge(g,3,4,44);
add_edge(g,1,5,9);
print_graph(g);


return 0;
}
