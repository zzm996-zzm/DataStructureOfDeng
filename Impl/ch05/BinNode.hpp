#define FromParentTo(x) \
    (IsRoot(x)?_root:(IsLChild(x)?(x).parent->lc:(x).parent->rc))

template<typename T>
T max(T l, T r){
    if(l > r)
        return l;
    else 
        return r;
}

enum class RBColor{
    RED,
    BLACK,
};

template<typename T> 
struct BinNode{
    T data;
    BinNode<T>* parent;
    BinNode<T>* lc;
    BinNode<T>* rc;
    int height;
    int npl;//Null Path Length
    RBColor color;

    BinNode():parent(nullptr),lc(nullptr),rc(nullptr),height(0),npl(1),color(RBColor::RED){}
    BinNode(T e, BinNode<T>* p = nullptr, BinNode<T>* lc = nullptr, BinNode<T>* rc = nullptr, 
            int h = 0, int l = 1, RBColor c = RBColor::RED):
            data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c){}
    
    int size();
    BinNode<T>* insertAsLC(T const&);
    BinNode<T>* insertAsRC(T const&);
    BinNode<T>* succ();
    template <typename VST> void travLevel(VST&);
    template <typename VST> void travPre(VST&);
    template <typename VST> void travIn(VST&);
    template <typename VST> void travPost(VST&);

    bool operator< (BinNode const& bn)  { return data < bn.data; }
    bool operator> (BinNode const& bn)  { return data > bn.data; }
    bool operator== (BinNode const& bn) { return data == bn.data; }
    bool operator!= (BinNode const& bn) { return data != bn.data; }
};

template<typename T>
inline int stature(BinNode<T>* p){
    return p?p->height:-1;
}

template<typename T>
inline bool IsRoot(const BinNode<T>& x){
    return !x.parent;
}

template<typename T>
inline bool IsLChild(const BinNode<T>& x){
    return !IsRoot(x) && (&x == x.parent->lc);
}

template<typename T>
inline bool LSRChild(const BinNode<T>& x){
    return !IsRoot(x) && (&x == x.parent->rc);
}

template<typename T>
inline bool HasParent(const BinNode<T>& x){
    return !IsRoot(x);
}

template<typename T>
inline BinNode<T>* HasLChild(const BinNode<T>& x){
    return x.lc;
}

template<typename T>
inline BinNode<T>* HasRChild(const BinNode<T>& x){
    return x.rc;
}

template<typename T>
inline bool HasChild(const BinNode<T>& x){
    return HasLChild(x) || HasRChild(x);
}

template<typename T>
inline bool HasBothChild(const BinNode<T>& x){
    return HasLChild(x) && HasRChild(x);
}

template<typename T>
inline bool IsLeaf(const BinNode<T>& x){
    return !HasChild(x);
}

//Operations
template<typename T>
inline BinNode<T>* sibling(const BinNode<T>*& x){
    return IsLChild(*x)?(x->parent->rc):(x->parent->lc);
}

template<typename T>
inline BinNode<T>* uncle(const BinNode<T>*& x){
    return IsLChild(*(x->parent));
}

template<typename T>
BinNode<T>* 
BinNode<T>::insertAsLC(T const& e){
    return lc = new BinNode(e, this);
}

template<typename T>
BinNode<T>*
BinNode<T>::insertAsRC(T const& e){
    return rc = new BinNode(e, this);
}

template<typename T>
BinNode<T>* 
BinNode<T>::succ(){
    BinNode<T>* s = this;
    if(rc){
        s = rc;
        while(HasLChild(*s)) s = s->lc;
    } else {
        while(IsRChild(*s)) s = s->parent;
        s = s->parent;
    }
    return s;
}

/*
template<typename T> 
template <typename VST>
void BinNode<T>::travIn(VST& visit){

}

template<typename T , typename VST>
static void visitAlongLeftBranch(BinNode<T>* x, VST& visit, Stack<BinNode*>& S){

}
*/
