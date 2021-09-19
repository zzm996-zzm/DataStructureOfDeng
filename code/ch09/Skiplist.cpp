#include "Skiplist.hpp"  

int main(){
    Skiplist<int, int> list;
    for(int i = 0; i <= 100; i++){
        list.put(i, i);
    }  

    for(int i = 0; i <= 100; i++){
        list.get(i);
    }  

    for(int i = 0; i <= 100; i++){
        list.remove(i);
    }  

    return 0;
}