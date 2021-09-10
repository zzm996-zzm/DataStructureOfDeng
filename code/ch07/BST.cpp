#include "../_share/print.h"  
#include <iostream>

#define TIME 20

int main(){
    BST<int> bst;
    for(int i = 1; i < TIME; i++)
        bst.insert(i);
    print(bst);

    for(int i = TIME - 1; i > 10; i--)
        bst.remove(i);
    print(bst);

    std::cout << bst.search(10) << std::endl;
    return 0;
}