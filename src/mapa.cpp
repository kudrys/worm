#include "mapa.h"
#include <iostream>
using namespace std;

mapa::mapa(){
    actualX=1;
    actualY=1;
}

char mapa::draw_point(int pointX,int pointY){
    return tab[pointX][pointY];
}

void mapa::trees_everywhere()
{
    for(int i=0;i<y+2;i++){
        for(int j=0;j<x+2;j++){
            tab[0][j] = 'T';
            tab[i][0] = 'T';
            tab[i][x+1] = 'T';
            tab[y+1][j] = 'T';
        }
    }
}


void mapa::create_map(){
        tab = new char* [x+2];

        for (int i = 0; i < x+2; i++){
            tab[i] = new char [y+2];
            //cout<<tab<<"\n";
        }
}

void mapa::draw(){

    for(int i=1;i<y+1;i++){
        cout<<"\n";
        for(int j=1;j<x+1;j++){
            //tab[i][j]='d';
            cout<<tab[j][i];
        }
    }
}

void mapa::load_one_char(char c){
    tab[actualX][actualY]=c;
    actualX++;
    if(actualX==x+1){
        actualX=1;
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


