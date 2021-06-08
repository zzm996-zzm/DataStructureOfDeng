#include "BinNode.hpp"
#include "../_share/util.hpp"
#include "../_share/release.hpp"

template<typename T>
static int removeAt(BinNodePosi(T) x){
    if(!x) return 0;
    int n = 1 + removeAt(x->lc) + removeAt(x->rc);//delete for travPost.
    release(x->data);
    release(x);
    return n;
}

template<typename T>
class BinTree{
protected:
    int _size;
    BinNodePosi(T) _root;
    virtual int updateHeight (BinNodePosi(T) x);
    void updateHeightAbove (BinNodePosi(T) x);
public:
    BinTree(): _size(0), _root(nullptr) { }
    ~BinTree() {if( 0 < _size ) remove(_root); }
    int size() const { return _size; }
    bool empty() const { return !_root; }
    BinNodePosi(T) root() const { return _root; }

    BinNodePosi(T) insertAsRoot(T const& e);
    BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const& e);
    BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const& e);
    BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>* &T);
    BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>* &T);

    int remove(BinNodePosi(T) x);
    BinTree<T>* secede( BinNodePosi(T) x);
    template<typename VST> void travLevel(VST& visit) { if(_root) _root->travLevel(visit); }
    template<typename VST> void travPre(VST& visit) { if(_root) _root->travPre(visit); }
    template<typename VST> void travIn(VST& visit) { if(_root) _root->travIn(visit); }
    template<typename VST> void travPost(VST& visit) { if(_root) _root->travPost(visit); }

    //bool operator< (BinTree<T> const& t) {  return _root && t._root && lt}
};

template<typename T>
int BinTree<T>::updateHeight(BinNodePosi(T) x){
    return x->height = 1 + max(stature(x->lc), stature(x->rc));
}

template<typename T>
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x){
    while(x){
        updateHeight(x);
        x = x->parent;
    }
}

//Insert
template<typename T>
BinNodePosi(T) BinTree<T>::insertAsRoot(T const& e){
    _size = 1;
    return _root = new BinNode<T>(e);
}

template<typename T>
BinNodePosi(T) 
BinTree<T>::insertAsRC(BinNodePosi(T) x, T const& e){
    _size++;
    x->insertAsRC(e);
    updateHeightAbove(x);
    return x->rc;
}

template<typename T>
BinNodePosi(T) 
BinTree<T>::insertAsLC(BinNodePosi(T) x, T const& e){
    _size++;
    x->insertAsLC(e);
    updateHeightAbove(x);
    return x->lc;
}

template<typename T>
BinNodePosi(T) 
BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>* &S){
    if(x->rc = S->_root) x->rc->parent = x;
    _size += S->_size;
    updateHeightAbove(x);
    S->_root = nullptr;
    S->_size = 0;
    release(S);
    S = nullptr;
    return x;
}

template<typename T>
BinNodePosi(T) 
BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>* &S){
    if(x->lc = S->_root) x->lc->parent = x;
    _size += S->_size;
    updateHeightAbove(x);
    S->_root = nullptr;
    S->_size = 0;
    release(S);
    S = nullptr;
    return x;
}

//delete
template<typename T>
int BinTree<T>::remove(BinNodePosi(T) x){
    FromParentTo(*x) = nullptr;//cut off the pointer from parent
    updateHeightAbove(x->parent);
    int n = removeAt(x);
    _size-=n;
    return n;
}

template<typename T>
BinTree<T>* BinTree<T>::secede(BinNodePosi(T) x){
    FromParentTo(*x) = nullptr;
    updateHeightAbove(x->parent);
    BinTree<T>* S = new BinTree<T>;
    S->_root = x;
    x->parent = nullptr;
    S->_size = x->size();
    _size -= S->_size;
    return S;
}
