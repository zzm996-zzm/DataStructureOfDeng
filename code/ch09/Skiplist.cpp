#include "../_share/print.h"  
#include <unistd.h>

int main(){
    Skiplist<int, int> list;
    for(int i = 0; i < 8; i+=2){
        list.put(i, dice(10000));
        print(list);
        sleep(1);
    }

    for(int i = 1; i < 9; i+=2){
        list.put(i, dice(10000));
        print(list);
        sleep(1);
    }
    return 0;
}