#ifndef SEGMENT_H
#define SEGMENT_H


class segment
{
    public:
        bool is_painted;
        segment * next;
        void paint(char);
        char get_color();
        void add_segment();
        segment();
    protected:
    private:
        char color;
};

#endif // SEGMENT_H
