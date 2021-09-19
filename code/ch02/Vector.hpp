#pragma once

using Rank = int;
#define DEFAULT_CAPACITY 3
#include <random>
#include <cstdio>
#include "../_share/util.hpp"
#include "../ch01/Fib.hpp" 

template<typename T>
class Vector{
protected:
    Rank _size;
    int _capacity;
    T* _elem;

    void copyFrom(T const* A, Rank lo, Rank hi);
    void expand();
    void shrink();
    bool bubble(Rank lo, Rank hi);
    void bubbleSort(Rank lo, Rank hi);
    Rank max(Rank lo, Rank hi);
    void selectionSort(Rank lo, Rank hi);
    void merge(Rank lo, Rank mi, Rank hi);
    void mergeSort(Rank lo, Rank hi);
    Rank partition(Rank lo, Rank hi);
    void quickSort(Rank lo, Rank hi);
    void heapSort(Rank lo, Rank hi);
public:
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0){
        _elem = new T[_capacity = c];
        for(_size = 0; _size < s; _elem[_size++] = v);
    }
    Vector(T const* A, Rank n){ copyFrom(A, 0, n); }
    Vector(T const* A, Rank lo, Rank hi){   copyFrom(A, lo, hi);    }
    Vector(Vector<T> const& V) {    copyFrom(V._elem, 0, V._size);   }//copy constructor
    Vector(Vector<T> const& V, Rank lo, Rank hi) {  copyFrom(V._elem, lo, hi); }

    ~Vector()   {   delete []_elem;   }
    //writable
    T& operator[] (Rank r) const;
    Vector<T> & operator=(Vector<T> const&);
    
    //move
    //Read Only
    Rank size() const { return _size; }
    bool empty() const { return !_size; }
    Rank capacity() const { return _capacity; }
    int disordered()  const;
    Rank find(T const& e) const { return find(e, 0, _size); }
    Rank find(T const& e, Rank lo, Rank hi) const;
    Rank binSearch (T* A, T const& e, Rank lo, Rank hi) const;
    Rank fibSearch (T* A, T const& e, Rank lo, Rank hi) const;
    Rank search(T const& e) const { return (0 >= _size)?-1:search(e, 0, _size); }
    Rank search(T const& e, Rank lo, Rank hi) const;
    

    
    T remove(Rank r);
    int remove(Rank lo, Rank hi);
    Rank insert(Rank r, T const& e);
    Rank insert(T const& e) {   return insert(_size, e);  }

    void sort() {   sort(0, _size); }
    void sort(Rank lo, Rank hi);
    void unsort(Rank lo, Rank hi);
    void unsort() { unsort(0, _size); }
    int deduplicate();
    int uniquify();

    void traverse(void(*)(T&));
    template<typename VST> void traverse(VST&&);
};

template<typename T> 
void Vector<T>::unsort(Rank lo, Rank hi){
    T* V = _elem + lo;
    for(Rank i = hi - lo; i > 0; i--)
        swap(V[i-1], V[rand()%i]);
}

template<typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi){
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0;
    while(lo < hi)
        _elem[_size++] = A[lo++];
}

template<typename T>
Vector<T>& 
Vector<T>::operator=(Vector<T> const& V){
    if( _elem ) delete []_elem;
    copyFrom(V._elem, 0, V.size());
    return *this;
}

template<typename T>
void Vector<T>::expand(){
    if(_size < _capacity)  return;
    if(_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
    T* oldElem = _elem;
    _elem = new T[_capacity <<= 1];
    for(int i = 0; i < _size; i++)
        _elem[i] = oldElem[i];
    delete []oldElem;
}

template<typename T>
void Vector<T>::shrink(){
    if(_capacity < DEFAULT_CAPACITY << 1) return;
    if(_size << 2 > _capacity) return;
    T* oldElem = _elem;
    _elem = new T[_capacity >>= 1];
    for(int i = 0; i < _size; i++)
        _elem[i] = oldElem[i];
    delete []oldElem;
}

template<typename T>
T& Vector<T>::operator[](Rank r) const{
    return _elem[r];
}


template<typename T>
Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const{
    while((lo < hi--) && (e!=_elem[hi]))
        ;
    return hi;
}

template<typename T>
Rank Vector<T>::insert(Rank r, T const& e){
    expand();
    for(int i = _size; i > r; i--)
        _elem[i] = _elem[i-1];
    _elem[r] = e;
    _size++;
    return r;
}

template<typename T>
int Vector<T>::remove(Rank lo, Rank hi){
    if(lo == hi) return 0;
    while(hi < _size) _elem[lo++] = _elem[hi++];
    _size = lo;
    shrink();
    return hi-lo;
}

template<typename T>
T Vector<T>::remove(Rank r){
    T e = _elem[r];
    remove(r, r+1);
    return e;
}

template<typename T>
int Vector<T>::deduplicate(){
    int oldSize = _size;
    Rank i = 1;
    while(i < _size)
        (find(_elem[i], 0, i)<0) ? i++:remove(i);
    return oldSize - _size;
}

template<typename T> 
void Vector<T>::traverse(void (*visit)(T&)){
    for(int i = 0; i <_size; i ++)
        visit(_elem[i]);
}

template<typename T>
template<typename VST>
void Vector<T>::traverse(VST&& visit){
    for(int i = 0; i < _size; i++)
        visit(_elem[i]);
}

template<typename T>
int Vector<T>::disordered() const {
    int n = 0;
    for(int i = 1; i < _size; i++)
        if(_elem[i-1] > _elem[i]) n++;
    return n;
}

template<typename T>
int Vector<T>::uniquify(){
    Rank i = 0, j = 0;
    while( ++j < _size)
        if(_elem[i]!=_elem[j])
            _elem[++i] = _elem[j];
    _size = ++i; 
    shrink();
    return j - i;
}

template<typename T>
Rank Vector<T>::search(T const& e, Rank lo, Rank hi) const{
    return (rand()%2)? binSearch(_elem, e, lo, hi):fibSearch(_elem, e, lo, hi);
}

template<typename T> 
Rank Vector<T>::binSearch (T* A, T const& e, Rank lo, Rank hi) const{
    //printf("BinSearch\n");
    while(lo < hi){
        Rank mi = (lo + hi) >> 1;
        (e < A[mi])? hi = mi:lo = mi+1;
    }
    return --lo;
}

template<typename T>
Rank Vector<T>::fibSearch (T* A, T const& e, Rank lo, Rank hi) const{
    //printf ( "FIB search (B)\n" );
    for( Fib fib ( hi - lo ); lo < hi;  ) { //Fib数列制表备查
        while( hi - lo < fib.get() ) fib.prev(); //自后向前顺序查找（分摊O(1)）
        Rank mi = lo + fib.get() - 1; //确定形如Fib(k) - 1的轴点
        ( e < A[mi] ) ? hi = mi : lo = mi + 1; //比较后确定深入前半段[lo, mi)或后半段(mi, hi)
    } //成功查找不能提前终止
    return --lo; 
}

template<typename T>
void Vector<T>::sort(Rank lo, Rank hi){
    switch(dice(2021)%2){
        case 1: 
            printf("BubbleSort.\n");
            bubbleSort(lo, hi); 
            break;
        //case 2: selectionSort(lo, hi); break;
        default:
            printf("MergeSort.\n"); 
            mergeSort(lo, hi); 
            break;
        //case 4: heapSort(lo, hi); break;
        //default: quickSort(lo, hi); break;
    }
}

template<typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi){
    while(!bubble(lo, hi--));
}

template<typename T>
bool Vector<T>::bubble(Rank lo, Rank hi){
    bool sorted = true;
    while(++lo < hi)
        if(_elem[lo - 1] > _elem[lo]){
            sorted = false;
            swap(_elem[lo-1], _elem[lo]);
        }
    return sorted;
}

template<typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi){
    if(hi - lo < 2) return;
    int mi = (lo + hi)/2;
    mergeSort(lo, mi);
    mergeSort(mi, hi);
    merge(lo, mi, hi);
}

template<typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi){
    T* A = _elem + lo;
    int lb = mi - lo;
    T* B = new T[lb];
    for(Rank i = 0; i < lb; B[i] = A[i], i++);

    int lc = hi - mi;
    T* C = _elem + mi;

    for(Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);){
        if((j < lb) && (!(k < lc) || (B[j] <= C[k]))) A[i++] = B[j++];
        if((k < lc) && (!(j < lb) || (C[k] < B[j]))) A[i++] = C[k++];
    }
    delete []B;
}


template<typename T> void increase(Vector<T>& V){
    V.traverse(Increase<T>());
}