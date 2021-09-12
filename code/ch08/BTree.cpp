#include "../_share/print.h"

int main(){
    BTree<int> btree{16};
    for(int i = 0; i < 1000; i++){
        btree.insert(i);
    }

    print(btree);

    for(int i = 0; i < 20; i++){
        btree.remove(i);
    }

    print(btree);

    return 0;
}