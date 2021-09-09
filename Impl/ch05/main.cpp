#include "../_share/print.h"

int main(){
    BinTree<int> tree;
    BinNode<int>* root = tree.insertAsRoot(10);
    BinNode<int>* left = tree.insertAsLC(root, 50);
    BinNode<int>* right = tree.insertAsRC(root, 60);
    for(int i = 0; i <= 20; i++){
        if(i/2 == 0){
            left = tree.insertAsLC(left, i);
            right = tree.insertAsRC(right, 20 - i);
        } else {
            left = tree.insertAsLC(right, i);
            right = tree.insertAsRC(right, 20 - i);
        }
    }
    print(tree);
    print(root);
    print(left);
    print(right);
}