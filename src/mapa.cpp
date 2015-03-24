#include "mapa.h"
#include <iostream>
using namespace std;

mapa::mapa(){

}

//char draw_point(int pointX,int pointY){
//    return tab[pointX][pointY];
//}

void mapa::draw(){

    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            //tab[i][j]='d';
            cout<<tab[i][j];
        }
    }
}

void mapa::create_map(){
        char** tab = new char* [x];

        for (int i = 0; i < x; i++){
            tab[i] = new char [y];
        }
}


