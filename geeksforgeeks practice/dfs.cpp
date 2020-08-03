/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/

#include<bits/stdc++.h>
#define S 1000000
using namespace std;
vector <int> bfs(vector<int> g[], int N);
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



///this is correct but not accepted in gfg because of their bad testing code
vector <int> dfs(vector<int> g[], int N)
{




}
