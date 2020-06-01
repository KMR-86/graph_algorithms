#include<bits/stdc++.h>
#define SIZE 1000002
using namespace std;
vector<int>eular(SIZE,0);
void set_eular(){
    for(int i=0;i<SIZE;i++){
        eular[i]=i;
    }
    for(int i=2;i<SIZE;i++){
        if(eular[i]==i){
            for(int j=i;j<SIZE;j=j+i){
                eular[j]=eular[j]-eular[j]/i;
            }
        }

    }

}
int main(){
set_eular();
int cases;
cin>>cases;
while(cases--){
int t;
cin>>t;
cout<<eular[t]<<endl;

}
return 0;
}

