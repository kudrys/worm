#ifndef WORM_H
#define WORM_H
#include "segment.h"


class worm{
    public:
        worm();
        bool is_alive();
        void add_segments(int);
        segment get_active();
        char get_color();
        void paint_active(char);
        void go();
        int segment_count;
    protected:
    private:
        segment * active_segment;  //TODO uwaga na wszkaznik
};

#endif // WORM_H
