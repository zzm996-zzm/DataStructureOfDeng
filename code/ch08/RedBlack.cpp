#include "../_share/print.h"
#include <unistd.h>

int main(int argc, char** argv){

    
    system("clear");
    RedBlack<int> tree;
    int temp;

    for(int i = 0; i < N; i++){
        temp = dice(RANDOM);
        printf("Insert: %d\n\n", temp);
        tree.insert(temp);
        printRedBlackTree(tree);
        sleep(1);
        system("clear");
    }

    printf("Press to see if you want to see the process of deletion\n");
    getchar();
    system("clear");

    
    while(!tree.empty()){
        temp = dice(RANDOM);
        if(tree.search(temp)){
            printf("Delete: %d\n\n", temp);
            tree.remove(temp);
            printRedBlackTree(tree);
            sleep(1);
            system("clear");
        }
    }

    return 0;
}