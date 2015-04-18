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
    return get_tab(pointX, pointY);
}

void mapa::trees_everywhere() {
    for(int i=0; i<x+2; i++) {
        set_tab(i, 0, 'T');
        set_tab(i, y+1, 'T');
    }
    for(int j=0; j<y+2; j++) {
        set_tab(0, j, 'T');
        set_tab(x+1, j, 'T');
    }
}

void mapa::create_map() {

    tab = new char[(x+2)*(y+2)];
    trees_everywhere();
}

void mapa::draw_trees() {
    for(int i=0; i<y+2; i++) {
        cout<<"\n";
        for(int j=0; j<x+2; j++) {
            cout<<get_tab(j, i);
        }
    }
}

void mapa::draw() {
    for(int i=1; i<y+1; i++) {
        cout<<"\n";
        for(int j=1; j<x+1; j++) {
            cout<<get_tab(j, i);
        }
    }

}

void mapa::draw2() {
    cout<<edzioX-1<<" "<<edzioY-1;
    draw();
}

void mapa::load_one_char(char c) {
    set_tab(actualX, actualY, c);
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
        } else {
            cin>>z;
            temp=atoi(c);
            for(int j=0; j<temp; j++) {
                load_one_char(z);
            }
            i=i+temp-1;
        }
    }
}

void mapa::set_edzio_size(int c) {
    if(edzio.segment_count==1) {
        edzio.add_segments(c-1);
    }
}

bool mapa::go(int x, int y) {
    char action=get_tab(x,y);
    switch(action) {
        case '.':
            edzio.go();
            edzioX=x;
            edzioY=y;
            if(edzio.get_active()->is_painted) {
                set_tab(x,y,edzio.get_color());
            }
            break;
        case 'G':
            edzio.go();
            edzioX=x;
            edzioY=y;
            edzio.add_segments(1);
            set_tab(x,y,edzio.get_color());
            break;
        case 'K':
            edzio.delete_active_segment();
            edzio.segment_count-=1;
            if(!edzio.is_alive()) {
                cout<<"\nZegnaj, okrutny swiecie!\n" ;
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
    char krok;
    int temp; //ilosc krokow, przet³umaczone c na int
    while(cin>>c) {
        if(!edzio.is_alive()) {
            break;
        } else {
            if(isalpha(c[0])) {
                moves(c[0]);
            } else {
                if (c[0]=='!')draw2();//delete it when everything works
                else{
                    cin>>krok;
                    temp=atoi(c);
                    for(int j=0; j<temp; j++) {
                        if(edzio.is_alive())
                            if(moves(krok))
                                break;
                    }
                }
            }
        }
        if(!edzio.is_alive())
            break;
    }
    draw2();
}


void mapa::set_tab(int gx, int gy, char c){
    tab[get_index(gx, gy)]=c;
    //cout <<tab[get_index(gx, gy)];
}

char mapa::get_tab(int gx, int gy){
    return tab[get_index(gx, gy)];
}

int mapa::get_index(int given_x, int given_y){
    //cout << "x: " << given_x << " y: " << given_y << " index: " << given_x*(x+2)+given_y << "\n";
    return given_x*(x+2)+given_y;
}




