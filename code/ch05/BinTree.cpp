#include "../_share/print.h"
#include <iostream>
#include <unistd.h>

#define TIME 100

int main(){
    system("clear");
    BinTree<int> tree;
    BinNode<int>* node = tree.insertAsRoot(dice(RANDOM));
    print(tree);
    sleep(1);
    system("clear");
    BinNode<int>* left = tree.insertAsLC(node, dice(RANDOM));
    print(tree);
    sleep(1);
    system("clear");
    BinNode<int>* right = tree.insertAsRC(node, dice(RANDOM));
    print(tree);
    sleep(1);
    system("clear");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 4; j++){
            if(dice(RANDOM)%4 == 0){
                tree.insertAsLC(left, dice(RANDOM));
                left = tree.insertAsRC(left, dice(RANDOM));
            } else if(dice(RANDOM)% 4 == 1){
                left = tree.insertAsLC(left, dice(RANDOM));
            } else if(dice(RANDOM)% 4 == 2){
                left = tree.insertAsRC(left, dice(RANDOM));
            } else {
                tree.insertAsRC(left, dice(RANDOM));
                left = tree.insertAsLC(left, dice(RANDOM));
            }
            print(tree);
            sleep(1);
            system("clear");

        }

        for(int j = 0; j < 4; j++){
            if(dice(RANDOM)%4 == 0){
                tree.insertAsLC(left, dice(RANDOM));
                right = tree.insertAsRC(right, dice(RANDOM));
            } else if(dice(RANDOM)% 4 == 1){
                right = tree.insertAsLC(right, dice(RANDOM));
            } else if(dice(RANDOM)% 4 == 2){
                right = tree.insertAsRC(right, dice(RANDOM));
            } else {
                tree.insertAsRC(left, dice(RANDOM));
                right = tree.insertAsLC(right, dice(RANDOM));
            }
            print(tree);
            sleep(1);
            system("clear");
        }
    }
    print(tree);
    sleep(5);
    printf("\n\n");

    BinTree<int>* subtree = tree.secede(tree.root()->rc);
    tree.attachAsRC(tree.root()->lc, subtree);
    print(tree);
    sleep(5);
    printf("\n\n");

    subtree = tree.secede(tree.root()->lc->rc);
    tree.attachAsRC(tree.root(), subtree);
    print(tree);
    sleep(5);
    printf("\n\n");
    
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