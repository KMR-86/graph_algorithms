#include<bits/stdc++.h>
using namespace std;
char g[1000][1000];
bool visited[1000][1000];
int n_row,n_col;
int x_dir[4]={0,0,1,-1};
int y_dir[4]={1,-1,0,0};

void dfs(int row,int col){
    cout<<g[row][col]<<row<<col<<endl;
    visited[row][col]=1;
    for(int i=0;i<4;i++){
        if(row+x_dir[i]>=0 && row+x_dir[i]<n_row && col+y_dir[i]>=0 && col+y_dir[i]<n_col && visited[row+x_dir[i]][col+y_dir[i]]==0){

            dfs(row+x_dir[i],col+y_dir[i]);
        }

    }
}
int main(){

cin>>n_row>>n_col;
for(int i=0;i<n_row;i++){
    string s;
    cin>>s;
    for(int j=0;j<s.size();j++){
        g[i][j]=s[j];
    }

}
int s_row,s_col;
cin>>s_row>>s_col;

dfs(s_row,s_col);
return 0;
}
