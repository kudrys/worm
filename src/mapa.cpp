#include "mapa.h"
#include <iostream>
#include <locale>
#include <stdlib.h>

using namespace std;

mapa::mapa() {
    actualX=1;
    actualY=1;
    edzioX=1;
    edzioY=1;
}

char mapa::draw_point(int pointX,int pointY) {
    return tab[pointX][pointY];
}

void mapa::trees_everywhere() {
    for(int i=0; i<y+2; i++) {
        for(int j=0; j<x+2; j++) {
            tab[0][j] = 'T';
            tab[i][0] = 'T';
            tab[i][x+1] = 'T';
            tab[y+1][j] = 'T';
        }
    }
}

void mapa::create_map() {
    tab = new char* [x+2];

    for (int i = 0; i < x+2; i++) {
        tab[i] = new char [y+2];
        //cout<<tab<<"\n";
    }
    trees_everywhere();
}

void mapa::draw() {

    for(int i=1; i<y+1; i++) {
        cout<<"\n";
        for(int j=1; j<x+1; j++) {
            //tab[i][j]='d';
            cout<<tab[j][i];
        }
    }
}

void mapa::draw2() {
    cout<<edzioX-1<<" "<<edzioY-1;
    draw();
}

void mapa::load_one_char(char c) {
    tab[actualX][actualY]=c;
    actualX++;
    if(actualX==x+1) {
        actualX=1;
        actualY++;
    }
}

void mapa::load() {
    char c[5];
    char z;
    int temp; //ilosc krokow, przet³umaczone c na int
    for(int i=0; i<x*y; i++) {
        cin>>c; //wczytujemy liczbe albo char
        //a jak wczytamy 5000 to to bedzie w c[0]? 5 w c[1] =0
        if(isalpha(c[0])||c[0]=='.') {
            load_one_char(c[0]);
            cout<<"i="<<i<<"\n";
        } else {
            //c-='0';
            cin>>z;
            temp=atoi(c);
            for(int j=0; j<temp; j++) {
                load_one_char(z);
                cout<<i;
            }
            i=i+temp;
            //actualX=actualX+c;
        }
    }
}

void mapa::set_edzio_size(int c) {
    if(edzio.segment_count==1) {
        edzio.add_segments(c-1);
    }
}

bool mapa::go(int x, int y) {
    char action;
    action=tab[x][y];

    switch(action) {
    case '.':
        edzio.go();
        edzioX=x;
        edzioY=y;
        if(edzio.get_active().is_painted) {
            tab[x][y]=edzio.get_color();
        }
        break;
    case 'G':
        edzio.go();
        edzioX=x;
        edzioY=y;
        edzio.add_segments(1);
        tab[x][y]=edzio.get_color();
        break;
    case 'K':
        edzio.get_active().delete_segment();
        cout << edzio.segment_count << "lala\n";
        edzio.segment_count-=1;
        cout << edzio.segment_count << "lala\n";
        if(!edzio.is_alive()) {
            cout<<"Zegnaj, okrutny swiecie!\n" <<"mam " << edzio.segment_count << "segmencikow\n";;
            return 0;
            break;
        } else {
            edzio.go();
            edzioX=x;
            edzioY=y;
            break;
        }
    case 'T':
        return 1;
    default:
        edzio.go();
        edzioX=x;
        edzioY=y;
        edzio.paint_active(action);
    }
    return 0;
}

bool mapa::moves(char c) {
    switch(c) {
    case 'l':
        return go(edzioX-1,edzioY);
    case 'p':
        return go(edzioX+1,edzioY);
    case 'g':
        return go(edzioX,edzioY-1);
    case 'd':
        return go(edzioX,edzioY+1);
    default:
        return 0;
    }
}

void mapa::load_moves() {

    char c[5];
    char k;
    int temp; //ilosc krokow, przet³umaczone c na int
    while(cin>>c) {
        cout << edzio.segment_count;
        if(!edzio.is_alive()) {
            cout<<"Zegnaj, okrutny swiecie!";
        } else {
            if(isalpha(c[0])) {
                moves(c[0]);
            } else {
                //c-='0';
                cin>>k;
                temp=atoi(c);
                for(int j=0; j<temp; j++) {
                    if(moves(k)) {
                        //cout<<"temp="<<temp;
                        //break;
                    }
                }
            }
            draw2();
        }
    }
}



