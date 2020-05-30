#include <iostream>
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
using namespace std;

int main () {
  ofstream myfile;
  myfile.open ("test.txt");
  myfile<<"15904 4"<<endl;
  for(int i=0;i<15904;i++){
    int t = rand()%2;
    myfile<<t<<endl;
  }
    for(int i=0;i<15903;i++){

    int t = rand()%15903;
    int t2= rand()%15903;
    while(t==t2 || (t==0 || t2==0)){
        t = rand()%15903;
        t2= rand()%15903;
    }
    myfile<<t<<" "<<t2<<endl;
  }

  myfile.close();
  return 0;
}
