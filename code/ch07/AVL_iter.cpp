#include "../_share/print.h"  
#include <iostream>

int main(int argc, char** argv){
    if(argc!=2){
        printf("Usage: %s <size>\n", argv[0]);
        return 0;
    }

    int times = atoi(argv[1]);


    AVL<int> bst;
    for(int i = 0; i < times; i++){
        bst.insert(i);
        print(bst);
    }

    return 0;
}