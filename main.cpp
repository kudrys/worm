#include "worm.h"
#include "segment.h"
#include <iostream>
using namespace std;


int main(){

    worm edek;

    edek.add_segments(4);
    edek.paint_active('c');
    edek.add_segments(2);
    edek.paint_active('t');

    segment jeden;
    jeden.paint('z');
    cout<<jeden.get_color();
    cout<<jeden.next->get_color();
    jeden.add_segment();
    //jeden.next->paint('k');
    cout<<jeden.get_color();
    cout<<jeden.next->get_color();
    cout<<jeden.next->next->get_color();
    jeden.add_segment();
    cout<<jeden.get_color();
    cout<<jeden.next->get_color();
    cout<<jeden.next->next->get_color();
    cout<<jeden.next->next->next->get_color();





//    for(int i=0;i<20;i++){
//        edek.go();
//        cout<<edek.get_color();
//        cout<<i;
//    }
}
