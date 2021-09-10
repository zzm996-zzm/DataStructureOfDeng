#include "../_share/print.h"  
#include <iostream>


int main(int argc, char** argv){
    if(argc!=2){
        printf("Usage: %s <size>\n", argv[0]);
        return 0;
    }

    int times = atoi(argv[1]);


    AVL<double> bst;
    for(int i = 0; i < times; i++){
        bst.insert(dice(1000.0));
    }

    print(bst);

    for(int i = 0; i < times/2; i++){
        bst.remove(i);
    }

    print(bst);

    return 0;
}