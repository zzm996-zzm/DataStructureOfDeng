#include "../_share/print.h"
#include <unistd.h>

#define TIME 2

int main(int argc, char** argv){

    if(argc!=2){
        printf("Usage: %s <num of nodes>\n", argv[0]);
        exit(0);
    }
    int n = atoi(argv[1]);

    BTree<int> btree{8};
    for(int i = 0; i < n; i++){
        btree.insert(i);
        print(btree);
        sleep(TIME);
    }

    printf("Press to see if you want to see the process of deletion\n");
    getchar();

    for(int i = 0; i < n; i++){
        btree.remove(i);
        print(btree);
        sleep(TIME);
    }


    return 0;
}