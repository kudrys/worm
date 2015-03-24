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
        char draw_point(int,int);
        void load();
        void load_one_char(char);
        mapa();
    protected:
    private:
        int actualX;
        int actualY;
};

#endif // MAPA_H
