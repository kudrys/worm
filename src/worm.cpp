#include "worm.h"
#include "segment.h"

worm::worm(){
    segment_count=1;
    active_segment = new segment;
}

segment * worm::get_active(){
    return active_segment->next;
}

char worm::get_color(){
    return get_active()->get_color();
}


bool worm::is_alive(){
    if(segment_count>0){
        return 1;
    }else{
        return 0;
    }
}

void worm::add_segments(int c){
    for(int i=0; i<c; i++){
        active_segment->add_segment();
    }
    segment_count+=c;
}

void worm::go(){
    active_segment=active_segment->next;
}

void worm::paint_active(char color){
    get_active()->paint(color);
}

void worm::delete_active_segment(){
    get_active()->delete_segment();
}





