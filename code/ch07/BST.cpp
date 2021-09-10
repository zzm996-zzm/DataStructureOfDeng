#include "../_share/print.h"  
#include <iostream>

int main(int argc, char** argv){
    if(argc!=2){
        printf("Usage: %s <size>\n", argv[0]);
        return 0;
    }

    int times = atoi(argv[1]);

    BST<int> bst;
    for(int i = 1; i < times; i++)
        bst.insert(i);
    print(bst);

    for(int i = times - 1; i > 10; i--)
        bst.remove(i);
    print(bst);

    std::cout << bst.search(10) << std::endl;
    return 0;
}