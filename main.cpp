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

//segment S;
//S.add_segment();
//S.delete_segment();

mapa skarbow;

int x,y,edzio_size;
cin>>x;
cin>>y;
cin>>edzio_size;
skarbow.x=x;
skarbow.y=y;

//char t[10][10];
//t[x][y];
skarbow.set_edzio_size(edzio_size);
skarbow.create_map();
//skarbow.trees_everywhere();
//cout<<skarbow.tab;
skarbow.load();
skarbow.draw();
//cout<<skarbow.draw_point(1,2);
}
