#ifndef MAPA_H
#define MAPA_H
#include "worm.h"

class mapa
{
    public:
        int x;
        int y;
        int edzioX; //pozycja robaka x
        int edzioY; //pozycja robaka y
        char **tab;
        void create_map();
        void draw();
        void draw2();
        char draw_point(int,int);
        void load();
        void load_one_char(char);
        mapa();
        worm edzio;
        void set_edzio_size(int);
        void go(int,int);
        void moves(char);
        void translate(char);
        void funkk();
    protected:
    private:
        void trees_everywhere();
        int actualX;
        int actualY;
};

#endif // MAPA_H
