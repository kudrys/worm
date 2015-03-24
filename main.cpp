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


//t[5][5]='X';

//rysuj_mape(t,10,10);
//cout<<t[5][5];

//    worm edek;
//
//    edek.add_segments(4);
//    edek.paint_active('c');
//    edek.add_segments(2);
//    edek.paint_active('t');
//
//    segment jeden;
//    jeden.paint('z');
//    cout<<jeden.get_color();
//    cout<<jeden.next->get_color();
//    jeden.add_segment();
//    //jeden.next->paint('k');
//    cout<<jeden.get_color();
//    cout<<jeden.next->get_color();
//    cout<<jeden.next->next->get_color();
//    jeden.add_segment();
//    cout<<jeden.get_color();
//    cout<<jeden.next->get_color();
//    cout<<jeden.next->next->get_color();
//    cout<<jeden.next->next->next->get_color();
//




//    for(int i=0;i<20;i++){
//        edek.go();
//        cout<<edek.get_color();
//        cout<<i;
//    }
}
