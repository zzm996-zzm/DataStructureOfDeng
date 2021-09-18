#include "../_share/print.h"

int main(){
    RedBlack<int> tree;
    for(int i = 0; i < 50; i++){
        tree.insert(i);
    }
    
    print(tree);

    for(int i = 0; i < 50; i++){
        tree.remove(i);
        print(tree);
    }
    return 0;
}