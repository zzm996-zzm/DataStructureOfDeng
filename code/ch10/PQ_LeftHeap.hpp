#include "PQ.hpp"  
#include "../ch05/BinTree.hpp"  

template<typename T>
class PQ_LeftHeap : public PQ<T>, public BinTree<T> {
public:
    PQ_LeftHeap() { }
    PQ_LeftHeap(T* E, int n){
        for(int i = 0; i < n; i++)
            insert(E[i]);
    }
    void insert(T);
    T getMax();
    T delMax();
};

template<typename T>
static BinNode<T>* merge(BinNode<T>* a, BinNode<T>* b) {
    if(!a)  return b;
    if(!b)  return a;
    if(lt(a->data, b->data)) swap(a, b);
    a->rc = merge(a->rc, b);
    a->rc->parent = a;
    if(!a->lc || a->lc->npl < a->rc->npl)
        swap(a->lc, a->rc);
    a->npl = a->rc? a->rc->npl+1 : 1;
    return a;
}

template<typename T>
T PQ_LeftHeap<T>::delMax() {
    BinNode<T>* lHeap = this->_root->lc;
    BinNode<T>* rHeap = this->_root->rc;
    T e = this->_root->data;
    delete this->_root;
    this->_size--;
    this->_root = merge(lHeap, rHeap);
    if(this->_root) this->_root->parent = nullptr;
    return e;
}

template <typename T> 
T PQ_LeftHeap<T>::getMax(){
    return this->_root->data; 
} //按照此处约定，堆顶即优先级最高的词条

template <typename T>
void PQ_LeftHeap<T>::insert(T e){
    BinNode<T>* v = new BinNode<T>(e);
    this->_root = merge(this->_root, v);
    this->_root->parent = nullptr;
    this->_size++;
}
