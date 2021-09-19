#include "../_share/print.h"
#include <unistd.h>

#define TIME 1

int main(int argc, char** argv){

    if(argc!=2){
        printf("Usage: %s <num of nodes>\n", argv[0]);
        exit(0);
    }
    int n = atoi(argv[1]);
    
    system("clear");
    RedBlack<int> tree;

    for(int i = 0; i < n; i++){
        tree.insert(dice(100));
        printRedBlackTree(tree);
        sleep(TIME);
        system("clear");
    }

    printf("Press to see if you want to see the process of deletion\n");
    getchar();
    system("clear");

    int temp;
    while(!tree.empty()){
        temp = dice(100);
        if(tree.search(temp)){
            tree.remove(temp);
            printRedBlackTree(tree);
            sleep(1);
            system("clear");
        }
    }


    return 0;
}