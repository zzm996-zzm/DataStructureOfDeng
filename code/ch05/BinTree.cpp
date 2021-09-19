#include "../_share/print.h"
#include <iostream>

#define TIME 100

int main(){
    BinTree<int> tree;
    BinNode<int>* root = tree.insertAsRoot(dice(TIME));
    BinNode<int>* left = tree.insertAsLC(root, dice(TIME));
    BinNode<int>* right = tree.insertAsRC(root, dice(TIME));
    tree.insertAsLC(left, dice(TIME));
    tree.insertAsRC(left, dice(TIME));
    tree.insertAsLC(right, dice(TIME));
    BinNode<int>* n = tree.insertAsRC(right, dice(TIME));
    
    

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
    
    std::cout << "Pre-traverse:    ";
    tree.travPre(Print<int>());
    std::cout << std::endl;
    std::cout << "In-traverse:     ";
    tree.travIn(Print<int>());
    std::cout << std::endl;
    std::cout << "Post-traverse:   ";
    tree.travPost(Print<int>());
    std::cout << std::endl;
    std::cout << "Level-traverse:  "; 
    tree.travLevel(Print<int>());
    std::cout << std::endl;
}