#include "../_share/print.h"
#include <iostream>


int main(){
    BinTree<int> tree;
    BinNode<int>* root = tree.insertAsRoot(dice(50));
    BinNode<int>* left = tree.insertAsLC(root, dice(50));
    BinNode<int>* right = tree.insertAsRC(root, dice(50));
    tree.insertAsLC(left, dice(50));
    tree.insertAsRC(left, dice(50));
    tree.insertAsLC(right, dice(50));
    BinNode<int>* n = tree.insertAsRC(right, dice(50));
    
    

    print(tree);
    std::cout << "---------------" << std::endl;
    BinTree<int>* sub = tree.secede(left);
    
    print(tree);
    print(sub);

    std::cout << "---------------" << std::endl;
    tree.attachAsRC(right, sub);
    print(tree);

    tree.insertAsLC(n, dice(100, 1000));

    std::cout << "---------------" << std::endl;
    std::cout << "Increase: " << std::endl; 
    tree.travPre(Increase<int>());
    print(tree);
    
    std::cout << "Pre-traverse:   ";
    tree.travPre(Print<int>());
    std::cout << std::endl;
    std::cout << "In-traverse:    ";
    tree.travIn(Print<int>());
    std::cout << std::endl;
    std::cout << "Post-traverse:  ";
    tree.travPost(Print<int>());
    std::cout << std::endl;
}