#include "worm.h"
#include "segment.h"
#include "mapa.h"
#include <iostream>
using namespace std;

//char rysuj_mape(char t[][],int x,int y){
//    for (int i=0; i<=x; i++){
//         for (int j=0; j<=y; j++){
//            //cout<<"^";
//            t[i][j]='*';
//            cout<<t[i][j];
//        }
//        cout<<"\n";
//    }
//}


int main(){


mapa skarbow;

int x,y;
cin>>x;
cin>>y;
skarbow.x=x;
skarbow.y=y;

//char t[10][10];
//t[x][y];

skarbow.create_map();

skarbow.draw();

}
