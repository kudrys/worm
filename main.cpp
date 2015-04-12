#include "worm.h"
#include "segment.h"
#include "mapa.h"
#include <iostream>
using namespace std;

int main() {

    mapa skarbow;

    int x,y,edzio_size;
    cin>>x;
    cin>>y;
    cin>>edzio_size;
    skarbow.x=x;
    skarbow.y=y;

    skarbow.set_edzio_size(edzio_size);
    skarbow.create_map();
    skarbow.load();
    skarbow.load_moves();

}
/*

10 10 3
2 . T 18 . c 6 . a b 31 . 2 G 20 . 6 K 11 .
5 p d d 100 p d d 10 l d d p p p p g l l d d d 10 p

*/
