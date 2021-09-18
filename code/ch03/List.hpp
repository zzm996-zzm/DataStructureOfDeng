#include "ListNode.hpp"  

template<typename T>
class List {

private:
    int _size;
    ListNode<T>* header;
    ListNode<T>* trailer;

protected:
    void init();
    int clear();
    void copyNodes(ListNode<T>*, int);
    void merge(ListNode<T>*&, int, List<T>&, ListNode<T>*, int);
    void mergeSort(ListNode<T>*&, int);
    void selectionSort(ListNode<T>*, int);
    void insertionSort(ListNode<T>*, int);

public:
    List() {  init(); }
    List(List<T> const& L);// copy constructor
    List(List<T> const& L, Rank r, int n);
    List(ListNode<T>* p, int n);
    ~List();

    Rank size() const { return _size; }
    bool empty() const {  return _size <= 0; }
    T& operator[](Rank r) const;
    ListNode<T>* first() const {  return header->succ;  }
    ListNode<T>* last()  const {  return trailer->pred; }
    bool valid(ListNode<T>* p) {  return p && (trailer != p) && (header!=p); }
    int disordered() const;
    ListNode<T>* find(T const& e) const {  return find(e, _size, trailer); }
    ListNode<T>* find(T const& e, int n, ListNode<T>* p) const;
    ListNode<T>* search(T const& e) const {  return search(e, _size, trailer); }
    ListNode<T>* search(T const& e, int n, ListNode<T>* p) const;
    ListNode<T>* selectMax(ListNode<T>* p, int n);
    ListNode<T>* selectMax() {    return selectMax(header->succ,_size);  }
    ListNode<T>* insertAsFirst(T const& e);
    ListNode<T>* insertAsLast(T const& e);
    ListNode<T>* insertA(ListNode<T>* p, T const& e);
    ListNode<T>* insertB(ListNode<T>* p, T const& e);
    T remove(ListNode<T>* p);
    void merge(List<T>& L) { merge(first(), size, L, L.first(), L._size); }
    void sort(ListNode<T>* p, int n);
    void sort() { sort(first(), _size); }
    int deduplicate();
    int uniquify();
    void reverse();

    void traverse(void(*)(T&));
    template<typename VST> void traverse(VST&);
};

template<typename T>
void List<T>::init(){
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->succ = trailer;
    header->pred = nullptr;
    trailer->pred = header;
    trailer->succ = nullptr;
    _size = 0;
}

template<typename T>
T& List<T>::operator[](Rank r) const {
    ListNode<T>* p = first();
    while(0 < r--) p = p->succ;
    return p->data;
}

template<typename T>
ListNode<T>* List<T>::find(T const& e, int n, ListNode<T>* p) const {
    while(0 < n--)
        if(e == (p = p->pred)->data) return p;
    return nullptr;
}

template<typename T>
ListNode<T>* List<T>::insertAsFirst(T const& e){
    _size++;
    return header->insertAsSucc(e);
}

template<typename T>
ListNode<T>* List<T>::insertAsLast(T const& e){
    _size++;
    return trailer->insertAsPred(e);
}

template<typename T>
ListNode<T>* List<T>::insertA(ListNode<T>* p, T const& e){
    _size++;
    return p->insertAsSucc(e);
}

template<typename T>
ListNode<T>* List<T>::insertB(ListNode<T>* p, T const& e){
    _size++;
    return p->insertAsPred(e);
}

template<typename T>
void List<T>::copyNodes(ListNode<T>* p, int n){
    init();
    while(n--){
        insertAsLast(p->data);
        p = p->succ;
    }
}

template<typename T>
List<T>::List(ListNode<T>* p, int n) { copyNodes(p, n); }

template<typename T>
List<T>::List(List<T> const& L) {   copyNodes(L.first(), L._size); }

template<typename T>
List<T>::List(List<T> const& L, int r, int n) { copyNodes(L[r], n); }

template<typename T>
T List<T>::remove(ListNode<T>* p){
    T e = p->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    delete p;
    _size--;
    return e;
}

template<typename T>
List<T>::~List(){
    clear();
    delete header;
    delete trailer;
}

template<typename T>
int List<T>::clear(){
    int oldSize = _size;
    while(0 < _size) remove(header->succ);
    return oldSize;
}

template<typename T>
int List<T>::deduplicate(){
    if(_size < 2) return 0;
    int oldSize = _size;
    ListNode<T>* p = header;
    Rank r = 0;
    while(trailer != (p = p->succ)){
        ListNode<T>* q = find(p->data, r, p);
        q ? remove(q):r++;
    }
    return oldSize - _size;
}

template<typename T>
void List<T>::traverse(void (*visit)(T&)){
    for(ListNode<T>* p = header->succ; p != trailer; p = p->succ)
        visit(p->data);
}

template<typename T>
template<typename VST>
void List<T>::traverse(VST& visit){
    for(ListNode<T>* p = header->succ; p != trailer; p = p->succ)
        visit(p->data);
}

template<typename T>
int List<T>::uniquify(){
    if(_size < 2) 
        return 0;
    int oldSize = _size;
    ListNode<T>* p = first();
    ListNode<T>* q;
    while(trailer != (q = p->succ))
        if(p->data != q->data) p = q;
        else remove(q);
    return oldSize - _size;
}

template<typename T>
ListNode<T>* List<T>::search(T const& e, int n, ListNode<T>* p) const {
    while(0 <= n--)
        if(((p = p->pred)->data) <= e) break;
    return p;
}