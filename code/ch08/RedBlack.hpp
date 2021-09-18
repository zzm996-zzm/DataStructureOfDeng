#include "../ch07/BST.hpp"  

template<typename T>
class RedBlack : public BST<T> {
protected:
    void solveDoubleRed(BinNode<T>* x);
    void solveDoubleBlack(BinNode<T>* x);
    int updateHeight(BinNode<T>* x); 
public: 
    BinNode<T>* insert(const T& e);
    bool remove(const T& e);
};

template<typename T>
bool IsBlack(BinNode<T>* p){
    return !p || p->color == RBColor::BLACK;
}

template<typename T>
bool IsRed(BinNode<T>* p){
    return !IsBlack(p);
}

template<typename T>
bool BlackHeightUpdated(BinNode<T>& x){
    return (stature(x.lc) == stature(x.rc)) && x.height == (IsRed(&x)?stature(x.lc):stature(x.lc)+1); 
}

template<typename T>
int RedBlack<T>::updateHeight(BinNode<T>* x){
    x->height = max(stature(x->lc), stature(x->rc));
    return IsBlack(x) ? x->height++ : x->height;
}

template<typename T>
BinNode<T>* RedBlack<T>::insert(const T& e){
    BinNode<T>*& x = this->search(e);
    if(x)
        return x;
    x = new BinNode<T>(e, this->_hot, nullptr, nullptr, -1);
    this->_size++;
    solveDoubleRed(x);
    return x?x:this->_hot->parent;
}

template<typename T>
void RedBlack<T>::solveDoubleRed(BinNode<T>* x){
    if(IsRoot(*x)){//已经是根节点
        this->_root->color = RBColor::BLACK;
        this->_root->height++;
        return;
    }

    BinNode<T>* p = x->parent;
    if(IsBlack(p)) return;

    BinNode<T>* g = p->parent;
    BinNode<T>* u = uncle(x);

    if(IsBlack(u)){// RR-1-u为黑色 (黑节点(含NULL) )
        if(IsLChild(*x) == IsLChild(*p))//同侧：zig-zig或zag-zag
            p->color = RBColor::BLACK;// parent转黑;
        else//异测：zig-zag或zag-zig
            x->color = RBColor::BLACK;// x转黑;
        g->color = RBColor::RED;

        BinNode<T>* gg = g->parent;
        BinNode<T>* r = this->FromParentTo(*g) = this->rotateAt(x);
        r->parent = gg;
    } else {// RR-2-u为红色
        p->color = RBColor::BLACK;//向上传递红色
        p->height++;//黑高度更新
        u->color = RBColor::BLACK;//向上传递红色
        u->height++;//黑高度更新
        if(!IsRoot(*g)) g->color = RBColor::RED;
        solveDoubleRed(g);
    }
}

template<typename T>
bool RedBlack<T>::remove(const T& e){
    BinNode<T>*& x = this->search(e);
    if(!x)
        return false;

    BinNode<T>* r = removeAt(x, this->_hot);
    if(!(--this->_size))//如果删除的是根节点
        return true;//直接返回

    if(!this->_hot){
        this->_root->color = RBColor::BLACK;
        this->updateHeight(this->_root);
        return true;
    }

    if(BlackHeightUpdated(*this->_hot))//若仍然黑平衡 
        return true;//无需调整

    if(IsRed(r)){// (b)
        r->color = RBColor::BLACK;
        r->height++;
        return true;
    }

    solveDoubleBlack(r);//双黑调整
    return true;
}

template<typename T>
void RedBlack<T>::solveDoubleBlack(BinNode<T>* r){
    BinNode<T>* p = r ? r->parent: this->_hot;//后继节点
    if(!p) 
        return;
    BinNode<T>* s = (r == p->lc) ? p->rc:p->lc;

    if(IsBlack(s)){
        BinNode<T>* t = nullptr;// s的红孩子，皆红时左者优先。
        if(IsRed(s->rc)) t = s->rc;
        if(IsRed(s->lc)) t = s->lc;
        if(t){// BB-1
            RBColor oldcolor = p->color;
            BinNode<T>* b = this->FromParentTo(*p) = this->rotateAt(t);
            
            if(HasLChild(*b)){ 
                b->lc->color = RBColor::BLACK;
                this->updateHeight(b->lc);
            }

            if(HasRChild(*b)){
                b->rc->color = RBColor::BLACK;
                this->updateHeight(b->rc);
            }

            b->color = oldcolor;
            this->updateHeight(b);
        } else {
            s->color = RBColor::RED;
            s->height--;
            if(IsRed(p))//BB-2R
                p->color = RBColor::BLACK;
            else{
                p->height--;
                solveDoubleBlack(p);
            }
        }
    } else {
        s->color = RBColor::BLACK;
        p->color = RBColor::RED;
        BinNode<T>* t = IsLChild(*s)?s->lc:s->rc;
        this->_hot = p;
        this->FromParentTo(*p) = this->rotateAt(t);
        solveDoubleBlack(r);
    }
}





    