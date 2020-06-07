#include<bits/stdc++.h>
using namespace std;
char g[55][55];
int visited[55][55]={0};
int dis[55][55]={0};
int n_row,n_col;
int x_dir[8]= {0,0,1,-1,1,1,-1,-1};
int y_dir[8]= {1,-1,0,0,1,-1,1,-1};
int max_c=0;
queue<pair<int , int > > q;
void dfs(int row,int col,int c)
{
    //cout<<g[row][col]<<row<<col<<endl;
    visited[row][col]=1;
    if(c+1>max_c)max_c=c+1;
    for(int i=0; i<8; i++)
    {
        if(row+x_dir[i]>=0 && row+x_dir[i]<n_row && col+y_dir[i]>=0 && col+y_dir[i]<n_col )
        {
            if(g[row][col]+1==g[row+x_dir[i]][col+y_dir[i]] && visited[row+x_dir[i]][col+y_dir[i]]==0)
            {
                dfs(row+x_dir[i],col+y_dir[i],c+1);
            }

        }

    }
}

void bfs_print(int row,int col){
    q.push(make_pair(row,col));

    while(!q.empty()){
        pair<int,int> p;
        p=q.front();
        q.pop();
        int row=p.first;
        int col=p.second;
        visited[row][col]=2;
        cout<<g[row][col]<<"\n";
        for(int i=0; i<8; i++)
        {
            //cout<<row+x_dir[i]<<" "<< col+y_dir[i]<<n_row<<n_col<<endl;
            if(row+x_dir[i]>=0 && row+x_dir[i]<n_row && col+y_dir[i]>=0 && col+y_dir[i]<n_col )
            {
                //cout<<row+x_dir[i]<<" "<< col+y_dir[i]<<endl;
                if(visited[row+x_dir[i]][col+y_dir[i]]==0)
                {

                    q.push(make_pair(row+x_dir[i],col+y_dir[i]));
                    visited[row+x_dir[i]][col+y_dir[i]]=1;
                }

        }

    }

    }
}
int main()
{
    int tc=0;
    while(true)
    {
        tc++;
        max_c=0;
        cin>>n_row>>n_col;
        if(n_row==0 && n_col==0){
            break;
        }
        for(int i=0; i<n_row; i++)
        {
            string s;
            cin>>s;
            for(int j=0; j<s.size(); j++)
            {
                g[i][j]=s[j];
                visited[i][j]=0;
                dis[i][j]=0;
            }

        }
        bfs_print(0,0);


    }


    return 0;
}
