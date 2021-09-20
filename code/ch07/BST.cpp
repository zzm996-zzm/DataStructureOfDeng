#include "../_share/print.h"  
#include <unistd.h>

int main(){

    system("clear");
    BST<int> bst;
    int temp;

    for(int i = 0; i < N; i++){
        temp = dice(RANDOM);
        printf("Insert: %d\n\n", temp);
        bst.insert(temp);
        print(bst);
        sleep(1);
        system("clear");
    }
    
    printf("Press to see if you want to see the process of deletion\n");
    getchar();
    system("clear");

    while(!bst.empty()){
        temp = dice(RANDOM);
        if(bst.search(temp)){
            printf("Delete: %d\n\n", temp);
            bst.remove(temp);
            print(bst);
            sleep(1);
            system("clear");
        }
    }

    return 0;
}