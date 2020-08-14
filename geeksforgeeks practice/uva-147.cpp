#include<bits/stdc++.h>
#define S 1000000
using namespace std;
float w[]={100.0,50,20,10,5,2,1,0.5,0.2,0.1,0.05}
int mem[12][30001];

int max_coin(int n){
    memset(mem,-1,sizeof(mem[0][0])*10000);
    for(int i=0;i<12;i++){
        for(int j=0;j<30001;j++){
            if(j==0){
                mem[i][j]=0;
                return 0;
            }

            else if(i==0){
                mem[i][j]=-INF_MAX+1;
                return mem[i][j];
            }
            else if(i==1){
                if(fmod(n,w[i])==0.0){
                    mem[i][j]=(int)floor(n/w[i]);
                }
                else{
                    mem[i][j]=-INF_MAX+1;
                    return mem[i][j];
            }
            if(mem[i][j]!=-1)return mem[i][j];


        }
    }

}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

int tc;
float n;
while(true){
    cin>>n;
    if(n==0.0){
        break;
    }


}


return 0;
}



