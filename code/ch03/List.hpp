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