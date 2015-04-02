#include "mapa.h"
#include <iostream>
#include <locale>

using namespace std;

mapa::mapa(){
    actualX=1;
    actualY=1;
    edzioX=1;
    edzioY=1;
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
        trees_everywhere();
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

void mapa::draw2(){
    draw();
    cout<<"["<<edzioX<<"] ["<<edzioY<<"] ";
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
    char z;
    for(int i=0;i<x*y;i++){
        cin>>c;
        if(isalpha(c)){
            load_one_char(c);
        }else{
            cin>>z;
            for(int j=0;j<c;j++){
                tab[actualX+j][actualY]=z;
            }
          i=i+c;
          actualX=actualX+c;
        }
    }
}

void mapa::set_edzio_size(int c){
    if(edzio.segment_count==1){
        edzio.add_segments(c-1);
    }
}

void mapa::go(int x, int y){
    char action;
    action=tab[x][y];

    switch(action){
    case '.':
        edzio.go();
        edzioX=x;
        edzioY=y;
        if(edzio.get_active().is_painted){
            tab[x][y]=edzio.get_color();
        }break;
    case 'G':
        edzio.go();
        edzioX=x;
        edzioY=y;
        edzio.add_segments(1);
        tab[x][y]=edzio.get_color();
        break;
    case 'K':
        edzio.get_active().delete_segment();
        edzio.go();
        edzioX=x;
        edzioY=y;
        break;
    case 'T':
        break;
    default:
        edzio.go();
        edzioX=x;
        edzioY=y;
        edzio.paint_active(action);
    }
}
void mapa::moves(char c){

    switch(c){
    case 'l':
        go(edzioX-1,edzioY);
        break;
    case 'p':
        go(edzioX+1,edzioY);
        break;
    case 'g':
        go(edzioX,edzioY+1);
        break;
    case 'd':
        go(edzioX,edzioY-1);
        break;
    default:
        break;
    }
}
void mapa::translate(char c){

}





