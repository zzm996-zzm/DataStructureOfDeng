#pragma once

#include "BinNode.hpp"  


template<typename T> 
class BinTree {
protected:
    int _size; 
    BinNode<T>* _root;
    virtual int updateHeight(BinNode<T>* x);
    void updateHeightAbove(BinNode<T>* x);
    BinNode<T>*& FromParentTo(const BinNode<T>& node);
public:
    BinTree():_size(0), _root(nullptr) {}
    ~BinTree() {if(_size > 0) remove(_root); }
    int size() const {  return _size; }
    bool empty() const {    return !_root; }
    BinNode<T>* root() const { return _root; }
    BinNode<T>* insertAsRoot(T const& e);
    BinNode<T>* insertAsLC(BinNode<T>* x, T const& e);
    BinNode<T>* insertAsRC(BinNode<T>* x, T const& e);
    BinNode<T>* attachAsLC(BinNode<T>* x, BinTree<T>*& S);
    BinNode<T>* attachAsRC(BinNode<T>* x, BinTree<T>*& S);
    int remove(BinNode<T>* x);
    BinTree<T>* secede(BinNode<T>* x);
    //template<typename VST> void travLevel(VST& visit){  if(_root) _root->travLevel(visit); }
    template<typename VST> void travPre(VST&& visit){  if(_root) _root->travPre(visit); }
    template<typename VST> void travIn(VST&& visit){  if(_root) _root->travIn(visit); }
    template<typename VST> void travPost(VST&& visit){  if(_root) _root->travPost(visit); }
    bool operator< (const BinTree<T> &t){   return _root && t._root && ((*_root) < (*t._root));   }
    bool operator> (const BinTree<T> &t){   return _root && t._root && ((*_root) > (*t._root));   }
    bool operator== (const BinTree<T> &t){   return _root && t._root && (_root == t._root);   }
    bool operator!= (const BinTree<T> &t){   return !(*this==t);    }
};

template<typename T>
int BinTree<T>::updateHeight(BinNode<T>* x){
    return x->height = 1 + max(stature(x->lc), stature(x->rc));
}

template<typename T>
void BinTree<T>::updateHeightAbove(BinNode<T>* x){
    while(x){
        updateHeight(x);
        x = x->parent;
    }
}

template<typename T>
BinNode<T>* 
BinTree<T>::insertAsRoot(T const& e){
    _size = 1;
    return _root = new BinNode<T>(e);
}

template<typename T>
BinNode<T>* 
BinTree<T>::insertAsRC(BinNode<T>* x, T const& e){
    _size++;
    x->insertAsRC(e);
    updateHeightAbove(x);
    return x->rc;
}

template<typename T>
BinNode<T>* 
BinTree<T>::insertAsLC(BinNode<T>* x, T const& e){
    _size++;
    x->insertAsLC(e);
    updateHeightAbove(x);
    return x->lc;
}

template<typename T>
BinNode<T>*
BinTree<T>::attachAsRC(BinNode<T>* x, BinTree<T>*& S){
    if(x->rc = S->_root) x->rc->parent = x;
    _size += S->_size;
    updateHeightAbove(x);
    S->_root = nullptr;
    S->_size = 0;
    //
    S = nullptr;
    return x;
}

template<typename T>
BinNode<T>*
BinTree<T>::attachAsLC(BinNode<T>* x, BinTree<T>*& S){
    if(x->lc = S->_root) x->lc->parent = x;
    _size += S->_size;
    updateHeightAbove(x);
    S->_root = nullptr;
    S->_size = 0;
    //
    S = nullptr;
    return x;
}

template<typename T>
static int removeAt(BinNode<T>* x){
    if(!x) return 0;
    int n = 1 + removeAt(x->lc) + removeAt(x->rc);
    //
    return n;
}

template<typename T>
BinNode<T>*& 
BinTree<T>::FromParentTo(const BinNode<T>& node){
    if(IsRoot(node))
        return this->_root;
    else if(IsLChild(node))
        return node.parent->lc;
    else 
        return node.parent->rc;
}

template<typename T>
int BinTree<T>::remove(BinNode<T>* x){
    this->FromParentTo(*x) = nullptr;
    updateHeightAbove(x->parent);
    int n = removeAt(x);
    _size -= n;
    return n;
}

template<typename T>
BinTree<T>* 
BinTree<T>::secede(BinNode<T>* x){
    this->FromParentTo(*x) = nullptr;
    updateHeightAbove(x->parent);
    BinTree<T>* S = new BinTree<T>();
    S->_root = x;
    x->parent = nullptr;
    S->_size = x->size();
    _size -= S->_size;
    return S;
}

