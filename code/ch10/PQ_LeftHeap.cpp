#include "../_share/print.h"  
#include <unistd.h>  

int main(){
    PQ_LeftHeap<int> left;
    PQ_LeftHeap<int> right;  

    system("clear");
    for(int i = 0; i < 10; i++){
        left.insert(dice(RANDOM));
        print(left);
        sleep(1);
        system("clear");
    }

    for(int i = 0; i < 10; i++){
        right.insert(dice(RANDOM));
        print(right);
        sleep(1);
        system("clear");
    }

    print(left);
    print(right);
    getchar();

    return 0;
}