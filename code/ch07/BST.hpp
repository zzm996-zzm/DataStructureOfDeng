#pragma once

#include "../ch05/BinTree.hpp"
#include "../_share/util.hpp"

template<typename T>
class BST: public BinTree<T> {
protected:
    BinNode<T>* _hot;
    BinNode<T>* connect34(
        BinNode<T>*, BinNode<T>*, BinNode<T>*,
        BinNode<T>*, BinNode<T>*, BinNode<T>*, BinNode<T>*
    );
    BinNode<T>* rotateAt(BinNode<T>* x);
public:
    virtual BinNode<T>*& search(const T& e);
    virtual BinNode<T>*  insert(const T& e);
    virtual bool remove(const T& e);
};

template<typename T>
static BinNode<T>* & searchIn(BinNode<T>*& v, const T& e, BinNode<T>*& hot){
    if(!v || (e == v->data)) return v;
    hot = v;
    return searchIn(((e < v->data)?v->lc:v->rc), e, hot);
}

template<typename T>
BinNode<T>*&
BST<T>::search(const T& e){
    return searchIn(this->_root, e, _hot = nullptr);
}

template<typename T>
BinNode<T>* 
BST<T>::insert(const T& e){
    BinNode<T>*& x = search(e);
    if(x)
        return x;
    x = new BinNode<T>(e, _hot);
    this->_size++;
    this->updateHeightAbove(x);
    return x;
}

template<typename T>
static BinNode<T>* removeAt(BinNode<T>*& x, BinNode<T>*& hot){
    BinNode<T>* w = x;
    BinNode<T>* succ = nullptr;
    if(!HasLChild(*x))
        succ = x = x->rc;
    else if(!HasRChild(*x))
        succ = x = x->lc;
    else {
        w = w->succ();
        swap(x->data, w->data);
        BinNode<T>* u = w->parent;
        ((u==x)?u->rc:u->lc) = succ = w->rc;
    }
    hot = w->parent;
    if(succ) succ->parent = hot;
    //
    return succ;
}

template<typename T>
bool BST<T>::remove(const T& e){
    BinNode<T>*& x = search(e);
    if(!x) 
        return false;
    removeAt(x ,_hot);
    this->_size--;
    this->updateHeightAbove(_hot);
    return true;
}