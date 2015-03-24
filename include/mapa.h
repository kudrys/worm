#ifndef MAPA_H
#define MAPA_H


class mapa
{
    public:
        int x;
        int y;
        char **tab;
        void create_map();
        void draw();
        void draw_point();
        mapa();
    protected:
    private:
};

#endif // MAPA_H
