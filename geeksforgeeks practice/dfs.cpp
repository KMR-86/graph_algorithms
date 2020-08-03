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
    }
    vector<int>res=bfs(adj,n);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

}


return 0;
}




vector <int> bfs(vector<int> g[], int N) {

    // Your code here
    vector<int>ans;
    stack<int>s;
    int color[N];
    memset(color,0,sizeof(color[0])*N);
    s.push(0);
    color[0]=1;
    while(!s.empty()){
        int node=s.top();
        s.pop();
        ans.push_back(node);
        color[node]=2;
        for(int i=0;i<g[node].size();i++){
            if(color[g[node][i]]==0){
                s.push(g[node][i]);
                color[g[node][i]]=1;
            }
        }
    }


    return ans;
}
