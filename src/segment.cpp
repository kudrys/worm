
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
    return is_painted?color:'.';
}

void segment::add_segment(){
    segment * s = new segment;
    s->next=next;
    next = s;
}

void segment::delete_segment(){
    next=next->next;
}

