#include "mapa.h"
#include <iostream>
using namespace std;

mapa::mapa(){
    actualX=0;
    actualY=0;
}
//char draw_point(int pointX,int pointY){
//    return tab[pointX][pointY];
//}
void mapa::draw(){

    for(int i=0;i<y;i++){
        cout<<"\n";
        for(int j=0;j<x;j++){
            //tab[i][j]='d';
            cout<<tab[j][i];
        }
    }
}

void mapa::create_map(){
        tab = new char* [x];

        for (int i = 0; i < x; i++){
            tab[i] = new char [y];
            //cout<<tab<<"\n";
        }
}

void mapa::load_one_char(char c){
    tab[actualX][actualY]=c;
    actualX++;
    if(actualX==x){
        actualX=0;
        actualY++;
    }
}

void mapa::load(){
    char c;
    for(int i=0;i<x*y;i++){
        cin>>c;
        load_one_char(c);
    }
}


