#include "worm.h"
#include "segment.h"
#include "mapa.h"
#include <iostream>
#include <stdio.h>
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
    skarbow.draw2();
    skarbow.load_moves();

}
