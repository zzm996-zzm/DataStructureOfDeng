#include "../_share/print.h"  

#define TIME 50

int main(){
    BST<int> bst;
    for(int i = 1; i < TIME; i++)
        bst.insert(dice(100));
    print(bst);
    return 0;
}