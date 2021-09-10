#pragma once 

#include "./BST.hpp" 

template<typename T>
class AVL: public BST<T> {
public:
    BinNode<T>* insert(const T& e);
    bool remove(const T& e);
};

template<typename T>
BinNode<T>* 
AVL<T>::insert(const T& e){
    BinNode<T>* & x = this->search ( e ); if ( x ) return x; //确认目标节点不存在
    BinNode<T>* xx = x = new BinNode<T> ( e, this->_hot ); this->_size++; //创建新节点x
// 此时，x的父亲_hot若增高，则其祖父有可能失衡
   for ( BinNode<T>* g = this->_hot; g; g = g->parent ) //从x之父出发向上，逐层检查各代祖先g
      if ( !AvlBalanced ( *g ) ) { //一旦发现g失衡，则（采用“3 + 4”算法）使之复衡，并将子树
         FromParentTo ( *g ) = this->rotateAt ( tallerChild ( tallerChild ( g ) ) ); //重新接入原树
         break; //局部子树复衡后，高度必然复原；其祖先亦必如此，故调整结束
      } else //否则（g仍平衡）
         this->updateHeight ( g ); //只需更新其高度（注意：即便g未失衡，高度亦可能增加）
   return xx; //返回新节点位置
}

template<typename T>
bool AVL<T>::remove(const T& e){
    BinNode<T>*& x = this->search(e);
    if(!x)
        return false;
    removeAt(x, this->_hot);
    this->_size--;
    for(BinNode<T>* g = this->_hot; g; g = g->parent){
        if(!AvlBalanced(*g))
            g = FromParentTo(*g) = this->rotateAt(tallerChild(tallerChild(g)));
        this->updateHeight(g);
    }
    return true;
}
