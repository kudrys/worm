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
cout<<skarbow.edzio.get_color();
skarbow.edzio.paint_active('K');
cout<<skarbow.edzio.get_color();

skarbow.load();
skarbow.draw2();
while('x'){
    int c;
    cin>>c;
    skarbow.moves(c);
    skarbow.draw2();
}
//cout<<skarbow.draw_point(1,2);
}
//. . T . . . . . . .
//. . . . . . . . . .
//. c . . . . . . a b
//. . . . . . . . . .
//. . . . . . . . . .
//. . . . . . . . . .
//. G G . . . . . . .
//. . . . . . . . . .
//. . . K K K K K K .
//. . . . . . . . . .
//
