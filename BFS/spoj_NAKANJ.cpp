#include<bits/stdc++.h>
using namespace std;
int visited[8][8]={0};
int dis[8][8]={0};
int disx[8]={2,2,-2,-2,1,1,-1,-1};
int disy[8]={1,-1,1,-1,2,-2,2,-2};
queue<pair<int,int> > q;
void bfs(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            visited[i][j]=0;
            dis[i][j]=0;
        }
    }

    while(!q.empty()){
        pair<int,int> p=q.front();
        //cout<<p.first<<" "<<p.second<<endl;
        q.pop();
        int x,y;
        x=p.first;
        y=p.second;
        visited[x][y]=2;
        for(int i=0;i<8;i++){
            if(x+disx[i]>=0 && x+disx[i]<8 && y+disy[i]>=0 && y+disy[i]<8){
                if(visited[x+disx[i]][y+disy[i]]==0){

                    dis[x+disx[i]][y+disy[i]]=dis[x][y]+1;
                    q.push(make_pair(x+disx[i],y+disy[i]));
                    visited[x+disx[i]][y+disy[i]]=1;
                }
            }
        }
    }




}

int main(){

//for(int i=0;i<8;i++){
//    for(int j=0;j<8;j++){
//        printf("%d ",dis[i][j]);
//    }
//    printf("\n");
//
//}

int cases;
cin>>cases;

while(cases--){
    string s,f;
    cin>>s>>f;

    q.push(make_pair(s[0]-97,s[1]-49));
    bfs();
    cout<<dis[f[0]-97][f[1]-49]<<endl;
}

return 0;
}
