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


skarbow.set_edzio_size(edzio_size);
skarbow.create_map();
//cout<<skarbow.edzio.get_color();
skarbow.edzio.paint_active('j');
//cout<<skarbow.edzio.get_color();

skarbow.load();
cout<<"gg";
skarbow.draw2();
skarbow.load_moves();
skarbow.draw2();

//10 10 3
//2 . T 18 . c 6 . a b 31 . 2 G 20 . 6 K 11 .
//5 p d d 100 p d d 10 l d d p p p p g l l d d d 10 p

}
