#include "segment.h"
#include <iostream>
using namespace std;

segment::segment(){
    is_painted = 0;
    next = this;
}

segment::~segment(){
    //cout<<"deleted"<<"\n"<<this;
}

void segment::paint(char paintcolor){
    color=paintcolor;
    is_painted = 1;
}

char segment::get_color(){
    if(is_painted)
        return color;
    else
        //cout<<"jest czysty";
        return '.';
}

void segment::add_segment(){
    segment * s = new segment;

    s->next=next;
    next = s;
    //cout <<"\nadres " << s << " next adres " << s->next;
}

void segment::delete_segment(){

    cout << next;
    cout << next->next;
    cout << next->next->next;
    next=next->next->next;
    cout << next;
    //delete temp;

}

